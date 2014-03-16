#include "GenerateAndronovHopf.h"
/**
 * Default constructor.
 */
GenerateAndronovHopf::GenerateAndronovHopf(){
    
    setOption("N1",200);
    setOption("N2",200);
    
    setOption("m1",-5);
    setOption("M1",5);

    setOption("m2",-5);
    setOption("M2",5);
    
    setOption("alpha", 1);
    setOption("beta", 1);
    setOption("gamma", 1);
    setOption("delta", 1);
    setOption("Eqn Number", 0);
    //setOption("Parameter f", 1);
}

/**
 * Default destructor.
 */
GenerateAndronovHopf::~GenerateAndronovHopf(){
    
}

bool GenerateAndronovHopf::execute(){
    int N1 = optionsMap.value("N1").toInt();
    int N2 = optionsMap.value("N2").toInt();

    double m1 = optionsMap.value("m1").toDouble();   
    double M1 = optionsMap.value("M1").toDouble();
    
    double m2 = optionsMap.value("m2").toDouble();    
    double M2 = optionsMap.value("M2").toDouble();
    
    double a = optionsMap.value("alpha").toDouble();
    double b = optionsMap.value("beta").toDouble();
    double c = optionsMap.value("gamma").toDouble();
    double d = optionsMap.value("delta").toDouble();
    
    int eqn = optionsMap.value("Eqn Number").toInt();
        
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
                        
			switch (eqn){
                            case 0:{
                                v[0] = (-y + a*x*(1- y*y-x*x))/((M1-m1)/(1+1));
                                v[1] =  ((x + a*y*(1- y*y-x*x)))/((M2-m2)/(1+1)) ;
                                v[2] = 0;
                                break;
                            }
                            case 1:{
                                v[0] = (x*(a + c*y*y + c*x*x) - y*(b + d*x*x + d*y*y))/((M1-m1)/(1+1));
                                v[1] = (y*(a + c*y*y + c*x*x) + x*(b + d*x*x + d*y*y))/((M2-m2)/(1+1));
                                v[2] = 0;
                                break;
                            }
                            default: {
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
