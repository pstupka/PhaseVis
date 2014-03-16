/* 
 * File:   MethodCreator.h
 * Author: stup
 *
 * Created on September 23, 2013, 7:23 PM
 */

#ifndef METHODCREATOR_H
#define	METHODCREATOR_H

#include "GUI/MethodChooseDialog.h"

#include "LineIntegralConvolution.h"
#include "Glyphs.h"
#include "Streamline.h"
#include "Isochron.h"
#include "DyeTracking.h"
#include "GridImporter.h"
#include "ColorMapper.h"
#include "GenerateVanDerPol.h"
#include "GenerateVanDerPolDuffing.h"
#include "GenerateMorrisLecar.h"
#include "GenerateAndronovHopf.h"


/**
 * This class is used to create dialog to choose visualization method.
 */
class MethodCreator{
    public:
        
    enum MethodTypes{
        LineIntegralConvolutionMethod = 1,
        GlyphsMethod,
        StreamlineMethod,
        DyeTrackingMethod,
        IsochronMethod,
        ColorMapperMethod,
        GridImporterMethod,
        GenerateVanDerPolMethod,
        GenerateVanDerPolDuffingMethod,
        GenerateMorrisLecarMethod,
        GenerateAndronovHopfMethod
    };
    
        MethodCreator();
        ~MethodCreator();
    
        bool createMethod(int method);
        bool createMethod();
    
        QString& chosenName();
        F* chosenMethod();
        
    private:
        QMap<QString, int> data_;
        QString name_;
        F* method_;
};

#endif	/* METHODCREATOR_H */

