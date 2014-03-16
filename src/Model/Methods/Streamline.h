/* 
 * File:   Streamline.h
 * Author: stup
 *
 * Created on July 22, 2013, 1:19 PM
 */

#ifndef STREAMLINE_H
#define	STREAMLINE_H

#include "F.h"


class Streamline : public F {
    public:
        Streamline();
        ~Streamline();
        bool execute();
        bool updateOptions();
        
    private:
        //Streamline
        double dt_;  
        double maxTime_;
        double maxLength_;
        
        int nSeeds_ ;
        double seedPoint_[3];
        double seedRadius_;
        
};

#endif	/* STREAMLINE_H */

