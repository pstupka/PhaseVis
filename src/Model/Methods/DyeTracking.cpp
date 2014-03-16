#include "DyeTracking.h"
#include <iostream>

/**
 * Function converts colour from (H,S,V) space to (R,G,B) space.
 * @param h Hue parameter.
 * @param s Saturation parameter.
 * @param v Value parameter.
 * @param r Reference to Red value.
 * @param g Reference to Green value.
 * @param b Reference to Blue value.
 */
void hsv2rgb(float h, float s, float v, float& r, float& g, float& b){
    int hueCase = (int)(h*6);
    float frac = 6*h - hueCase;
    float lx = v*(1-s);
    float ly = v*(1-s*frac);
    float lz = v*(1-s*(1-frac));
    
    switch(hueCase){
        case 0: 
        case 6: r = v; g = lz; b = lx; break;
        case 1: r = ly; g = v; b = lx; break;
        case 2: r = lx; g = v; b = lz; break;
        case 3: r = lx; g = ly; b = v; break;
        case 4: r = lz; g = lx; b = v; break;
        case 5: r = v; g = lx; b = ly; break;
    }
}

/**
 * Default constructor
 */
DyeTracking::DyeTracking() {
        
    dt_ = 0.011;
    maxTime_ = 1;
    cLimit_ = 0.05;
    colorHue_ =  0;
    colorBrightness_ = 0;
    
    setOption("dt",dt_);
    setOption("maxTime",maxTime_);
    setOption("cLimit",cLimit_);
    setOption("colorHue",colorHue_);
    setOption("colorBrightness",colorBrightness_);
    

}

/**
 * Default destructor
 */
DyeTracking::~DyeTracking(){
		 
}

/**
 * Execute Dye Tracking method.
 * @return Execute status.
 */
bool DyeTracking::execute(){
    ready_ = false;
    if(outputs_.size() == 0 || !updateOptions()) return false;
    
    int cell = 0; 
    int cellPoints[MAX_CELL_SIZE];
    
    double p0[3] = {0,0,0};
    double p[3] = {0,0,0};
    double v[3] = {0,0,0};
    
    double vMag = 1;
    
    C_.clear();
    C_.resize(outputs_[0] -> numCells());
    
    double t;
    double l;
    //outputs_[0] -> numCells()
    for (int c = 0; c < outputs_[0] -> numCells(); c++ ){
        if(!(c%(int)(outputs_[0] -> numCells()/100)))std::cout<<c*100./outputs_[0] -> numCells()<<" %"<<std::endl;
        outputs_[0] -> getCell(c,cellPoints);
        outputs_[0] -> getPoint(cellPoints[0],p0);       
        outputs_[0] -> getPoint(cellPoints[2],p);
        p0[0] = (p[0] + p0[0])*0.5;
        p0[1] = (p[1] + p0[1])*0.5;
        p0[2] = (p[2] + p0[2])*0.5;
        cell = c;

        t = 0; 
        l = 0;
        for (;; t += fabs(dt_), p[0] = p0[0], p[1] = p0[1], p[2] = p0[2]){
            if (cell == -1 || t >= maxTime_) break;            
            C_[cell] += 0.00001;
            
            outputs_[0] -> getC1Vector(cell,p0,v);
            //if (v[0]<0.001 && v[0]>-0.001 && v[1]<0.001 && v[1]>-0.001) break;
            //vMag = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
            //if (vMag > 0.0000000000001){        
                p0[0] += v[0]*dt_;///vMag;
                p0[1] += v[1]*dt_;///vMag;
                p0[2] += v[2]*dt_;///vMag;
            //}
            cell = outputs_[0] -> findCell(p0);
        }
        
    }
    

    ready_ = true;
    return ready_;
}

/**
 * This method updates options of Color Mapper.
 * @return Update status
 */
bool DyeTracking::updateOptions(){

    dt_ = optionsMap.value("dt").toDouble();
    maxTime_ = optionsMap.value("maxTime").toDouble();
    cLimit_= optionsMap.value("cLimit").toDouble(); 
    colorHue_ = optionsMap.value("colorHue").toDouble(); 
    colorBrightness_ = optionsMap.value("colorBrightness").toDouble(); 
    return true;
}

/**
 * This function overrides default draw function. It is because sometimes there is no 
 * need to recalculate every streamline. 
 */
void DyeTracking::draw(){
    updateOptions();
    float r = 0;
    float g = 0;
    float b = 0;
    double coeff;
    
    double scale = *std::max_element(C_.begin(),C_.end());
    if (cLimit_ > 0) scale = cLimit_;
    for (int i = 0; i< outputs_[0] -> numCells(); i++){
        if (C_[i] >= scale) coeff = scale;
        else coeff = C_[i];
        
        hsv2rgb(colorHue_,coeff/scale,colorBrightness_,r,g,b);
        outputs_[0] -> setC0Color(i,r,g,b,coeff/scale);
    }    
    
    if (outputs_[0]) outputs_[0] -> getGlDefinition();
}