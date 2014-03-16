#include "GenerateMorrisLecar.h"
#include<cmath>
/**
 * Default constructor.
 */
GenerateMorrisLecar::GenerateMorrisLecar(){
    
    setOption("N1",200);
    setOption("N2",200);
    
    setOption("m1",-100);
    setOption("M1",100);

    setOption("m2",-0.1);
    setOption("M2",1);
    
    setOption("Parameter gCa", 4.4);
    setOption("Parameter VCa", 120.0);
    setOption("Parameter gK", 8.0);
    setOption("Parameter VK", -80.0);
    setOption("Parameter gL", 2.0); 
    setOption("Parameter VL", -60.0);
    setOption("Parameter V1", -1.2);
    setOption("Parameter V2", 18.0);
    setOption("Parameter V3", 2.0);
    setOption("Parameter V4", 30.0);
    setOption("Parameter T0", 25.0);
    setOption("Parameter Iapp", 70);
    setOption("Parameter C", 20.0);
    
    setOption("Lienard eqn type", 0);
}

/**
 * Default destructor.
 */
GenerateMorrisLecar::~GenerateMorrisLecar(){
    
}

bool GenerateMorrisLecar::execute(){
    int N1 = optionsMap.value("N1").toInt();
    int N2 = optionsMap.value("N2").toInt();

    double m1 = optionsMap.value("m1").toDouble();   
    double M1 = optionsMap.value("M1").toDouble();
    
    double m2 = optionsMap.value("m2").toDouble();    
    double M2 = optionsMap.value("M2").toDouble();
    
    double gCa = optionsMap.value("Parameter gCa").toDouble();
    double VCa = optionsMap.value("Parameter VCa").toDouble();
    double gK = optionsMap.value("Parameter gK").toDouble();
    double VK = optionsMap.value("Parameter VK").toDouble();
    double gL = optionsMap.value("Parameter gL").toDouble();
    double VL = optionsMap.value("Parameter VL").toDouble();
    
    double V1 = optionsMap.value("Parameter V1").toDouble();
    double V2 = optionsMap.value("Parameter V2").toDouble();    
    double V3 = optionsMap.value("Parameter V3").toDouble();
    double V4 = optionsMap.value("Parameter V4").toDouble();
    double T0 = optionsMap.value("Parameter T0").toDouble();
    double Iapp = optionsMap.value("Parameter Iapp").toDouble();
    double C = optionsMap.value("Parameter C").toDouble();
    
    int lienardType = optionsMap.value("Lienard eqn type").toInt();
    
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
                                  v[0] = ( (-gCa*MWinf(x,V1,V2)*(x-VCa)-gK*y*(x-VK)-gL*(x-VL) + Iapp )/C )*((1.+1.)/(M1-m1)); 
                                  v[1] = ( (MWinf(x,V3,V4) - y)/(Tw(x,V3,V4,T0)))*((1.+1.)/(M2-m2));
                                v[2] = 0;
                                break;
                            }
                            case 1:{
                                v[0] = y*(1.+1.)/(M1-m1);
                                v[1] = (  pow(y,2)/(x - VK) + (y*(-2*gL - (2*Iapp)/(x - VK) + (gCa*x)/(x - VK) + (2*gL*x)/(x - VK) - (gCa*VCa)/(x - VK) - (2*gL*VL)/(x - VK) - (4*C*cosh((x - V3)/(2.*V4)))/T0 + 
        (gCa*(-x + VCa)*pow(cosh((x - V1)/V2),-2))/V2 + (gCa*(x - VCa)*tanh((x - V1)/V2))/(x - VK) - gCa*(1 + tanh((x - V1)/V2))))/(2.*C) + 
   ((4*Iapp*cosh((x - V3)/(2.*V4)))/T0 - (2*gCa*x*cosh((x - V3)/(2.*V4)))/T0 - (2*gK*x*cosh((x - V3)/(2.*V4)))/T0 - (4*gL*x*cosh((x - V3)/(2.*V4)))/T0 + (2*gCa*VCa*cosh((x - V3)/(2.*V4)))/T0 + 
      (2*gK*VK*cosh((x - V3)/(2.*V4)))/T0 + (4*gL*VL*cosh((x - V3)/(2.*V4)))/T0 + (2*gCa*(-x + VCa)*cosh((x - V3)/(2.*V4))*tanh((x - V1)/V2))/T0 + 
      (2*gK*(-x + VK)*cosh((x - V3)/(2.*V4))*tanh((x - V3)/V4))/T0)/(2.*C))*(1.+1.)/(M2-m2);
                                v[2] = 0;
                                break;
                            }
                            case 2:{
                                v[0] = y*(1.+1.)/(M1-m1);
                                v[1] = ( (y*(-2*gL - (2*Iapp)/(x - VK) + (gCa*x)/(x - VK) + (2*gL*x)/(x - VK) - (gCa*VCa)/(x - VK) - (2*gL*VL)/(x - VK) - (4*C*cosh((x - V3)/(2.*V4)))/T0 + 
        (gCa*(-x + VCa)*pow(cosh((x - V1)/V2),-2))/V2 + (gCa*(x - VCa)*tanh((x - V1)/V2))/(x - VK) - gCa*(1 + tanh((x - V1)/V2))))/(2.*C) + 
   ((4*Iapp*cosh((x - V3)/(2.*V4)))/T0 - (2*gCa*x*cosh((x - V3)/(2.*V4)))/T0 - (2*gK*x*cosh((x - V3)/(2.*V4)))/T0 - (4*gL*x*cosh((x - V3)/(2.*V4)))/T0 + (2*gCa*VCa*cosh((x - V3)/(2.*V4)))/T0 + 
      (2*gK*VK*cosh((x - V3)/(2.*V4)))/T0 + (4*gL*VL*cosh((x - V3)/(2.*V4)))/T0 + (2*gCa*(-x + VCa)*cosh((x - V3)/(2.*V4))*tanh((x - V1)/V2))/T0 + 
      (2*gK*(-x + VK)*cosh((x - V3)/(2.*V4))*tanh((x - V3)/V4))/T0)/(2.*C))*(1.+1.)/(M2-m2);
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

/**
 * Computes helping stationary function in Morris - Lecar model.
 */
double GenerateMorrisLecar::MWinf(double V, double V1, double V2){
    return 0.5*(1.+tanh((V-V1)/V2));
}

/**
 * Computes helping stationary function in Morris - Lecar model.
 */
double GenerateMorrisLecar::Tw(double V, double V1, double V2, double T0){
    return T0/cosh((V-V1)/(2*V2));
}
