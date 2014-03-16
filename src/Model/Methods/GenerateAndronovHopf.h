/* 
 * File:   GenerateAndronovHopf.h
 * Author: stup
 *
 * Created on October 8, 2013, 11:31 AM
 */

#ifndef GENERATEANDRONOVHOPF_H
#define	GENERATEANDRONOVHOPF_H

#include "F.h"

/**
 * Generator of Andronov - Hopf model. 
 */
class GenerateAndronovHopf : public F {
    public: 
        GenerateAndronovHopf();
        ~GenerateAndronovHopf();
    
        bool execute();

};

#endif	/* GENERATEANDRONOVHOPF_H */

