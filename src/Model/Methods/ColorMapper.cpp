#include "ColorMapper.h"

/**
 * Default constructor
 */
ColorMapper::ColorMapper(){
    factor1_ = 1;
    factor2_ = 1;
    factor3_ = 1;
    
    setOption("Factor 1",factor1_);
    setOption("Factor 2",factor2_);
    setOption("Factor 3",factor3_);
    
    setOption("Bottom value",0);
    setOption("Top value",1);
    setOption("Color map",0);
}

/**
 * Default destructor
 */
ColorMapper::~ColorMapper(){
    
}

/**
 * Execute Color Mapper method.
 * @return Execute status.
 */
bool ColorMapper::execute(){
    ready_ = false;
    if (!updateOptions() && !outputs_.size()) return false;
    
    double p[3] = {0,0,0};
    double v[3] = {0,0,0}; 
    std::vector <double> vMag(outputs_[0] -> numCells());
    
    for (int i = 0; i< outputs_[0] -> numCells(); i++){
        outputs_[0] -> getC1Vector(i,p,v);
        vMag[i] = sqrt(factor1_*v[0]*v[0] + factor2_*v[1]*v[1] + factor3_*v[2]*v[2]);
    }
    
    double scale = *std::max_element(vMag.begin(), vMag.end());
    if (fabs(scale) < 0.00000001) scale = 0.00000001; 
    for (int i = 0; i< outputs_[0] -> numCells(); i++){
        outputs_[0] -> setC0Color(i,0,0,vMag[i]/scale,1);
    }
    
    ready_ = true;
    return ready_;
}

/**
 * This method updates options of Color Mapper.
 * @return Update status
 */
bool ColorMapper::updateOptions(){
    factor1_ = optionsMap.value("Factor 1").toInt();
    factor2_ = optionsMap.value("Factor 2").toInt();
    factor3_ = optionsMap.value("Factor 3").toInt();
    return true;
}