#include "Streamline.h"
#include <iostream>

Streamline::Streamline(){
    dt_ = 0.0001;
    maxTime_ = 1;
    maxLength_ = 1;
    nSeeds_ = 100;
    seedPoint_[0] = 0.0;
    seedPoint_[1] = 0.0;
    seedPoint_[2] = 0.0;
    seedRadius_ = 1.0;
    
    setOption("dt",0.0001);
    setOption("maxTime",1);
    setOption("maxLength",1);
    setOption("nSeeds",100);
    setOption("seedPoint_x",0);
    setOption("seedPoint_y",0);
    setOption("seedPoint_z",0);
    setOption("seedRadius",1);
}

Streamline::~Streamline(){
}

bool Streamline::execute(){
    ready_ = false;
    if (!updateOptions()) return false; //Obligatory
   
    int cell = 0; 
    
    double p0[3] = {0,0,0};
    double p[3] = {0,0,0};
    double v[3] = {0,0,0};
    
    double t;
    double l;
    
    for (int i = 0; i< outputs_[0] -> numCells(); i++)
        outputs_[0] -> setC0Color(i, 0,0,0,0);
    
    for(int i = 0; i < nSeeds_; i++){
        
        setProgress(((double)i/nSeeds_)*100+1);
        
        p[0] = p0[0] = (seedPoint_[0] - seedRadius_) + 2*seedRadius_*((rand()%1000)/1000.);
        p[1] = p0[1] = (seedPoint_[1] - seedRadius_) + 2*seedRadius_*((rand()%1000)/1000.);
        p[2] = p0[2] = 0;        
                
        cell = input_ -> findCell(p0);
        t = 0;
        l = 0;
        
        for (;; t += fabs(dt_), p[0] = p0[0], p[1] = p0[1], p[2] = p0[2] ){
            if (cell == -1 || t >= maxTime_ || l >= maxLength_) break;
            
            outputs_[0] -> setC0Color(cell, 0,0,t/(maxTime_+0.000000001),t/(maxTime_+0.000000001));
            
            input_ -> getC1Vector(cell,p0,v);
            p0[0] += v[0]*dt_;
            p0[1] += v[1]*dt_;
            p0[2] += v[2]*dt_;
            
            l += sqrt((p0[0]-p[0])*(p0[0]-p[0])+(p0[1]-p[1])*(p0[1]-p[1])+(p0[2]-p[2])*(p0[2]-p[2]));
            
            cell = input_ -> findCell(p0);
            
            
        }
    }
    
    ready_ = true;
    return ready_;
}


bool Streamline::updateOptions(){
    dt_ = optionsMap.value("dt").toDouble();
    maxTime_ = optionsMap.value("maxTime").toDouble();
    maxLength_ = optionsMap.value("maxLength").toDouble();    
    nSeeds_ = optionsMap.value("nSeeds").toInt(); 
    seedPoint_[0] = optionsMap.value("seedPoint_x").toDouble(); 
    seedPoint_[1] = optionsMap.value("seedPoint_y").toDouble(); 
    seedPoint_[2] = optionsMap.value("seedPoint_z").toDouble(); 
    seedRadius_ = optionsMap.value("seedRadius").toDouble();
    return true;
}