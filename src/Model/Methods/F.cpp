#include "F.h"

/**
 * Default constructor.
 */
F::F(): input_(0), progress_(0), layer_(0), ready_(false){
    optionModel = new OptionModel(optionsMap);
}

/**
 * Default destructor.
 */

F::~F(){
    for(uint i = 0; i< outputs_.size(); i++) if(outputs_[i] != 0) SAFE_DELETE(outputs_[i]);
    if(optionModel != 0) SAFE_DELETE(optionModel);
}

/**
 * Replace old reference to input grid with new one. Also clones it and adds to 
 * output vector. 
 * @param g Grid to set in input.
 * @return Setting status.
 */
bool F::setInput(Grid* g){
        input_ = g;
        if(outputs_.size()) {
            SAFE_DELETE(outputs_[0]);
            outputs_.pop_back();
        }
        outputs_.push_back(input_ -> clone()); 
        if (input_ == g)return true;
        return false;
}

/**
 * Gets pointer to grid, that is set as an output.
 * @param i Index of output grid.
 * @return Setting status.
 */
Grid* F::getOutput(int i){
    if ((int)outputs_.size() > i)return outputs_[i];
    return 0;
}

/**
 * Default draw method in OpenGL.
 */
void F::draw(){
    if (outputs_[0]) outputs_[0] -> getGlDefinition();
}

/**
 * Method sets value of specific setting in visualization method.
 * @param key Name of setting.
 * @param value Value of setting.
 */
void F::setOption(const QString key, QVariant value){
    optionsMap.insert(key,value);    
}

/**
 * 
 * @return Number of layer
 */
int F::getLayer(){
    return layer_;
}

/**
 * Sets new number of layer for current visualization method.
 * @param layer Number of layer.
 * @return Layer setting status.
 */
bool F::setLayer(int layer){
    layer_ = layer;
    return true;
}

/**
 * Check if current method is ready to visualize e.g. if it is executed without errors.
 * @return Ready status. 
 */
bool F::isReady(){
    return ready_;
}

/**
 * Prototype for updating options.
 * @return 
 */
bool F::updateOptions(){
    return true;
}

/**
 * This method sets percentage o execution of method.
 * @todo Implement this in Qt GUI as progress indicator.
 * @param progress % of executing method.
 */
void F::setProgress(int progress){
    if (progress_ != progress) {
        if(progress > 100) progress_ = 100;
        if(progress < 0) progress_ = 0;
        progress_ = progress;
    }
}