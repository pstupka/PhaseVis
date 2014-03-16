#ifndef ISOCHRON_H
#define ISOCHRON_H

#include "F.h"



class Isochron : public F{

public:
	Isochron();
	~Isochron();
	bool execute();
        bool updateOptions();
        void draw();
        
private:
        //Streamline
        double dt_;  
        double maxTime_;
        double blurStep_;
        
        int filter_;
        
        int filterKernelLength_;
        std::vector <int> C_;
        std::vector <int> texture_;

};


#endif