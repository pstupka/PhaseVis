#include <iostream>
#include <QVariant>

#include "GridImporter.h"
#include "glwidget.h"

GridImporter::GridImporter(){
    setOption(QString("Input file"),QVariant("data/vf.txt"));

    setOption("numCells",0);
    setOption("numPoints",0);
}

GridImporter::~GridImporter(){
    
}

bool GridImporter::execute(){
    ready_ = false;
    std::cerr<<"GridImporter executed\n";
    std::cerr<<optionsMap.value("Input file").toString().toStdString();
    std::ifstream data(optionsMap.value("Input file").toByteArray());
    if(data.good()){
        if(outputs_.size()){
            SAFE_DELETE(outputs_[0]);
            outputs_.pop_back();
        }
        outputs_.push_back(new UniformGrid(data, -1., 1., -1.,1.) );
        data.close();
        ready_ = true;
        setOption("numCells",outputs_[0] -> numCells());
        setOption("numPoints",outputs_[0] -> numPoints());
    } else {
        std::cerr<<"Loading fail";
        ready_ = false;
    }
    
    return ready_;
}
