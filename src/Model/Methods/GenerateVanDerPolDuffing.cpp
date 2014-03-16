#include "GenerateVanDerPolDuffing.h"


/**
 * Default constructor.
 */
GenerateVanDerPolDuffing::GenerateVanDerPolDuffing(){
    
    setOption("N1",200);
    setOption("N2",200);
    
    setOption("m1",-5);
    setOption("M1",5);

    setOption("m2",-5);
    setOption("M2",5);
    
    setOption("Parameter alpha", 1);
    setOption("Parameter mu", 1);
    setOption("Parameter f", 1);
    setOption("Parameter d", 1);
    setOption("Parameter e", 1);
    setOption("Lienard eqn type", 0);
}

/**
 * Default destructor.
 */
GenerateVanDerPolDuffing::~GenerateVanDerPolDuffing(){
    
}

bool GenerateVanDerPolDuffing::execute(){
    int N1 = optionsMap.value("N1").toInt();
    int N2 = optionsMap.value("N2").toInt();

    double m1 = optionsMap.value("m1").toDouble();   
    double M1 = optionsMap.value("M1").toDouble();
    
    double m2 = optionsMap.value("m2").toDouble();    
    double M2 = optionsMap.value("M2").toDouble();
    
    double mu = optionsMap.value("Parameter mu").toDouble();
    double alpha = optionsMap.value("Parameter alpha").toDouble();
    double f = optionsMap.value("Parameter f").toDouble();
    double d = optionsMap.value("Parameter d").toDouble();
    double e = optionsMap.value("Parameter e").toDouble();
    int lienardType = optionsMap.value("Lienard eqn type").toInt();
    //double I_ext = optionsMap.value("Parameter I_ext").toDouble();
    
    double x = 0;
    double y = 0;
    
    double v[3] = {0,0,0};
    
    ready_ = false;
    if(outputs_.size()){
        SAFE_DELETE(outputs_[0]);
        outputs_.pop_back();
    }
    outputs_.push_back(new UniformGrid(N1, N2, -1, 1, -1, 1));
	for (int i = 0; i< N2; i++){
		for (int j = 0; j< N1; j++){
			x = m1 + (M1 - m1) * j / (N1-1.0f);
			y = m2 + (M2 - m2) * i / (N2-1.0f);
                        
                        switch (lienardType){
                            case 0:{
                                v[0] = y/((M1-m1)/(1+1));
                                v[1] = (alpha*(mu - x*x)*y - f*x*(x+d)*(x+e))/((M2-m2)/(1+1));
                                v[2] = 0;
                                break;
                            }
                            case 1:{
                                v[0] = alpha *(mu*x-x*x*x/3.-y)/((M1-m1)/(1+1));
                                v[1] =  +f*x*(x+d)*(x+e)/(alpha*((M2-m2)/(1+1)));
                                v[2] = 0;
                                break;
                            }
                            default:{ 
                                return false;
                                break;
                            }
                        }
                        
                        outputs_[0] -> setPointVector(i*N1+j,v); 
		}
	}

    
    ready_ = true;
    return ready_;
}