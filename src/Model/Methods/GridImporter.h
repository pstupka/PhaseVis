/* 
 * File:   Import.h
 * Author: stup
 *
 * Created on August 14, 2013, 7:40 PM
 */
#ifndef GRIDIMPORTER_H
#define	GRIDIMPORTER_H

#include "F.h"

class GridImporter : public F {
    public: 
        GridImporter();
        ~GridImporter();
    
        bool execute();
};

#endif	

