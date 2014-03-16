/* 
 * File:   GenerateMorrisLecar.h
 * Author: stup
 *
 * Created on September 29, 2013, 11:22 PM
 */

#ifndef GENERATEMORRISLECAR_H
#define	GENERATEMORRISLECAR_H

#include "F.h"

/**
 * Generator of Morris - Lecar model. 
 */
class GenerateMorrisLecar : public F{
    public: 
        GenerateMorrisLecar();
        ~GenerateMorrisLecar();
    
        bool execute();
        
    private:
        double MWinf(double V, double V1, double V2);
        double Tw(double V, double V1, double V2, double T0);
};

#endif	/* GENERATEMORRISLECAR_H */

