#include "Isochron.h"
#include <iostream>

Isochron::Isochron() {
        
    dt_ = 0.011;
    maxTime_ = 1;
    blurStep_ = 0.001;
    
    filterKernelLength_ = 5;
    
    filter_ = 10;
    
    setOption("dt",dt_);
    setOption("maxTime",maxTime_);
    
    setOption("blurStep", blurStep_);
    setOption("filter",filter_);
    setOption("filterKernelLength",filterKernelLength_);
}

Isochron::~Isochron(){
	 
}


bool Isochron::execute(){
    ready_ = false;
    if(outputs_.size() == 0 || !updateOptions()) return false;
    
    int cell = 0; 
    int cellPoints[MAX_CELL_SIZE];
    
    double p0[3] = {0,0,0};
    double v[3] = {0,0,0};
    
    double vMag = 1;
    
    double t;
    
    texture_.clear();
    texture_.resize(outputs_[0] -> numCells());
    UniformGrid* grid = dynamic_cast<UniformGrid*>(outputs_[0]);
    int color;   
    
    for (int i = 0; i < grid -> getDimension1()-filter_; i++)
    for (int j = 0; j < grid -> getDimension2()-filter_; j++){
        if (!(i%filter_) && !(j%filter_)){
            color = (rand())%16777215;
            for( int f = 0; f < filter_; f++)
            for( int g = 0; g < filter_; g++)
                //if (j+g < grid->getDimension1()-1 || i+f < grid->getDimension2()-1)
                texture_[(i+f)*(grid -> getDimension1()-1)+j+g] = color;
        }
        //texture[c] = (c/(double)outputs_[0] -> numCells())*16777215;
    }
    C_.clear();
    C_.resize(outputs_[0] -> numCells());
    for (int c = 0; c < outputs_[0] -> numCells(); c++ ){
        if(!(c%(int)(outputs_[0] -> numCells()/100)))std::cout<<c*100./outputs_[0] -> numCells()<<" %"<<std::endl;

        outputs_[0] -> getCell(c,cellPoints);
        outputs_[0] -> getPoint(cellPoints[0],p0);       

        cell = c;

        t = 0; 
        for (;; t += fabs(dt_)){
            if (cell == -1 || t >= maxTime_) break;
                        
            outputs_[0] -> getC1Vector(cell,p0,v);
            if (vMag){        
                p0[0] += v[0]*dt_;
                p0[1] += v[1]*dt_;
                p0[2] += v[2]*dt_;
            }

            cell = outputs_[0] -> findCell(p0);
        }
        C_[c] = cell;
    }
    
    ready_ = true;
    return ready_;
}

bool Isochron::updateOptions(){

    dt_ = optionsMap.value("dt").toDouble();
    maxTime_ = optionsMap.value("maxTime").toDouble();
    blurStep_ = optionsMap.value("blurStep").toDouble();
    filterKernelLength_ = optionsMap.value("filterKernelLength").toDouble();
    filter_ = optionsMap.value("filter").toInt();
    return true;
}

void Isochron::draw(){
    updateOptions();
    int cell = 0; 
    int cellPoints[MAX_CELL_SIZE];
    double p0[3] = {0,0,0};
    double p[3] = {0,0,0};
    
    double Rc = 0;
    double Gc = 0;
    double Bc = 0;
    
    for (int c = 0; c < outputs_[0] -> numCells(); c++ ){
        outputs_[0] -> getCell(c,cellPoints);
        outputs_[0] -> getPoint(cellPoints[0],p0);  
        
        Rc = 0;
        Gc = 0;
        Bc = 0;
        for (int i = 0; i < filterKernelLength_; i++)
        for (int j = 0; j < filterKernelLength_; j++){
            p[0] = p0[0] + (i - filterKernelLength_/2)*blurStep_+0.00000000001;
            p[1] = p0[1] + (j - filterKernelLength_/2)*blurStep_+0.00000000001;
            p[2] = 0;
            cell = outputs_[0] -> findCell(p);
            if (cell != -1){ 
                Rc += (((texture_[C_[cell]]/256)/256)%256)/256.;
                Gc += ((texture_[C_[cell]]/256)%256)/256.;
                Bc += (texture_[C_[cell]]%256)/256.;
            }
        }
        outputs_[0] -> setC0Color(c,Rc/(double)(filterKernelLength_*filterKernelLength_),
                Gc/(double)(filterKernelLength_*filterKernelLength_),
                Bc/(double)(filterKernelLength_*filterKernelLength_),1);
     }
    
    if (outputs_[0]) outputs_[0] -> getGlDefinition();
}
