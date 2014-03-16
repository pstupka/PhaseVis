#include "MethodCreator.h"

MethodCreator::MethodCreator(){
    data_.insert("Isochron", MethodCreator::IsochronMethod);
    data_.insert("Line Integral Convolution", MethodCreator::LineIntegralConvolutionMethod);
    data_.insert("Glyphs", MethodCreator::GlyphsMethod);
    data_.insert("Streamline", MethodCreator::StreamlineMethod);
    data_.insert("Dye Tracking", MethodCreator::DyeTrackingMethod);
    data_.insert("Color Mapper", MethodCreator::ColorMapperMethod);
}

MethodCreator::~MethodCreator(){
    
}

bool MethodCreator::createMethod(int method){   
    switch(method){
        case MethodCreator::IsochronMethod:  
            method_ = new Isochron();
            break;
        case MethodCreator::LineIntegralConvolutionMethod:
            method_ = new LineIntegralConvolution();
            break; 
        case MethodCreator::GlyphsMethod: 
            method_ = new Glyphs();
            break;
        case MethodCreator::StreamlineMethod: 
            method_ = new Streamline();
            break;
        case MethodCreator::DyeTrackingMethod: 
            method_ = new DyeTracking();
            break;
        case MethodCreator::ColorMapperMethod: 
            method_ = new ColorMapper();
            break;
        case MethodCreator::GridImporterMethod:
            method_ = new GridImporter(); 
            name_ = "Grid Importer";
            break;
        case MethodCreator::GenerateVanDerPolMethod:
            method_ = new GenerateVanDerPol(); 
            name_ = "VDPGenerator";
            break;    
        case MethodCreator::GenerateVanDerPolDuffingMethod:
            method_ = new GenerateVanDerPolDuffing(); 
            name_ = "VDPDGenerator";
            break; 
        case MethodCreator::GenerateMorrisLecarMethod:
            method_ = new GenerateMorrisLecar(); 
            name_ = "MLGenerator";
            break; 
        case MethodCreator::GenerateAndronovHopfMethod:
            method_ = new GenerateAndronovHopf(); 
            name_ = "AHGenerator";
            break; 
        default: break;   
    }

    if (method) return true;
    return false;
}

bool MethodCreator::createMethod(){
    MethodChooseDialog chooseDialog(data_);
    if (!chooseDialog.exec()) return false;
    int method = data_.value(chooseDialog.methodList -> currentText());
    name_ = chooseDialog.methodName->text();
    if (name_.isEmpty()) name_ = data_.key(method);    
    return createMethod(method);
   
}

QString& MethodCreator::chosenName(){
    return name_;
}

F* MethodCreator::chosenMethod(){
    return method_;   
}