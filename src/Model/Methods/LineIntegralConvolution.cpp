#include "LineIntegralConvolution.h"

//LicStreamline
LicStreamline::LicStreamline(){
    
}

LicStreamline::~LicStreamline(){
    
}
int LicStreamline::size(){
    return streamBackward_.size()+streamForward_.size() + 1;
}

void LicStreamline::setSeed(int cell){
    seedCell_ = cell;
}

void LicStreamline::addForwardCell(int cell){
    streamForward_.push_back(cell);
}

void LicStreamline::addBackwardCell(int cell){
    streamBackward_.push_back(cell);
}

void LicStreamline::clear(){
    streamBackward_.clear();
    streamForward_.clear();
    seedCell_ = -1;
}

int& LicStreamline::operator[](int m){
    if (m == 0){
        return seedCell_;
    }
    else if (m > 0 && m < (int)streamForward_.size()){
        return streamForward_[m-1];
    }
    else if (m > 0 && m >= (int)streamForward_.size()){
        return streamForward_[streamForward_.size()-1];
    }
    else if (m < 0 && m > -(int)streamBackward_.size()){
        return streamBackward_[-m-1];
    }
    else if (m < 0 && m <= -(int)streamBackward_.size()){
        return streamBackward_[streamBackward_.size()-1];
    }
    return seedCell_;
}



LineIntegralConvolution::LineIntegralConvolution(){
    //Streamline
    dt_ = 0.001;
    
    //LIC
    minHits_ = 50;
    m_ = 50;
    convolutionLength_ = 10;
    
    setOption("dt",dt_);
    
    setOption("minHits",minHits_);
    setOption("M",m_);
    setOption("convolutionLength",convolutionLength_);
    
}

LineIntegralConvolution::~LineIntegralConvolution(){
    //if(texture_ != 0) delete texture_;
}

bool LineIntegralConvolution::execute(){   
    ready_ = false;
    
    int cell = 0;
    
    if(outputs_.size() == 0 || !updateOptions()) return false;
    
    //generate white noise    
    numHits_.clear();
    numHits_.resize(outputs_[0] -> numCells());
    texture_.clear();
    texture_.resize(outputs_[0] -> numCells());
    pixelIntensity_.clear();
    pixelIntensity_.resize(outputs_[0] -> numCells());
        
    generateInputTexture();
    
    for (cell = 0; cell < outputs_[0] -> numCells(); cell++){
        //emit progressChanged(cell*100./outputs_[0] -> numCells()+1);
        if (numHits_[cell] < minHits_){
            computeStreamline(cell); 
            computeConvolution();
        }
    }
    
    for ( cell = 0; cell < (int)pixelIntensity_.size(); cell++){
        pixelIntensity_[cell] *= 1./numHits_[cell];

        outputs_[0] -> setC0Color(cell, pixelIntensity_[cell],pixelIntensity_[cell],pixelIntensity_[cell],1 );
    }
    
    ready_ = true;
    return ready_;
}

bool LineIntegralConvolution::updateOptions(){
    dt_ = optionsMap.value("dt").toDouble();
    minHits_ = optionsMap.value("minHits").toDouble();
    m_ = optionsMap.value("M").toInt();
    convolutionLength_= optionsMap.value("convolutionLength").toInt();;
    return true;
}

void LineIntegralConvolution::generateInputTexture(){ 
    for (int cell = 0; cell < outputs_[0] -> numCells(); cell++){
        texture_[cell] = (rand()%1000)/1000.;        
    }
}

void LineIntegralConvolution::computeStreamline(int cell){
    int forwardSign = 1;
    int backwardSign = -1;
    int c = -1;
    double forward[3] = {0,0,0};
    double backward[3] = {0,0,0};
    double p0[3] = {0,0,0};
    int cellPoints[MAX_CELL_SIZE];    
    
    streamline.clear();
    outputs_[0] -> getCell(cell, cellPoints);
    outputs_[0] -> getPoint(cellPoints[0],p0);
    streamline.setSeed(cell);
   
    forward[0] = p0[0]; forward[1] = p0[1]; forward[2] = p0[2]; 
    backward[0] = p0[0]; backward[1] = p0[1]; backward[2] = p0[2]; 
    
    for (int s = 0 ; s < m_ ; s++){
        c = interpolateEuler(forward,forwardSign*dt_);
        if (c != -1) {
            streamline.addForwardCell(c);
        } else{
            forwardSign *= -1;
            c = interpolateEuler(forward,forwardSign*dt_);
            if (c != -1) streamline.addForwardCell(c);
        }
        c = interpolateEuler(backward,backwardSign*dt_);
        if (c != -1) {
            streamline.addBackwardCell(c);
        } else {
            backwardSign *= -1;
            c = interpolateEuler(forward,backwardSign*dt_);
            if (c != -1) streamline.addBackwardCell(c);
        }
    }
}

void LineIntegralConvolution::computeConvolution(){
    double I0 = 0;
    double norm = 1;
    double Itmp = 0;
    
    for (int i = -convolutionLength_; i <= convolutionLength_ ; i++){
        I0 += texture_[streamline[i]];
    }
    
    norm = 1./(2.*convolutionLength_+1);
    pixelIntensity_[streamline[0]] += I0*norm;
    numHits_[streamline[0]]++;
    
    //forward Convolution
    Itmp = I0*norm;
    for (int m = 1; m < m_-convolutionLength_; m++){
        
        Itmp += norm*(texture_[streamline[m+convolutionLength_]]-texture_[streamline[m-1-convolutionLength_]]); 
        numHits_[streamline[m]]++;  // return seedCell if streamline[m] doesn't exist
        pixelIntensity_[streamline[m]] += Itmp;
    }
    
    //Backward convolution
    Itmp = I0*norm;
    for (int m = -1; m > -m_+convolutionLength_; m--){
        
        Itmp += norm*(texture_[streamline[m-convolutionLength_]]-texture_[streamline[m+1+convolutionLength_]]); 
        numHits_[streamline[m]]++;
        pixelIntensity_[streamline[m]] += Itmp;
    }
}

int LineIntegralConvolution::interpolateEuler(double *p, double dt){
        double vMag = 0;   
        double v[3] = {0,0,0};
        int cell;   
        
        cell = outputs_[0] -> findCell(p);
        if (cell == -1) return -1;
        
        outputs_[0] -> getC1Vector(cell,p,v);
        vMag = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
        if (vMag < 0.000001) return -1;
        
        p[0] += v[0]*dt/vMag;
        p[1] += v[1]*dt/vMag;
        p[2] += v[2]*dt/vMag;
        cell = outputs_[0] -> findCell(p);
        if (cell == -1) return -1;
        return cell;
}