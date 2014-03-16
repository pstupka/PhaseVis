
#ifndef GENERATEOSCILLATOR_H
#define	GENERATEOSCILLATOR_H

#include "F.h"

/**
 * Generator of van der Pol model.
 */
class GenerateVanDerPol : public F{
    public: 
        GenerateVanDerPol();
        ~GenerateVanDerPol();
    
        bool execute();

};

#endif	

