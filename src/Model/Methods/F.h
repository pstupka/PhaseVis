#ifndef F_H
#define F_H


#include <iostream>

#include <QMap>

#include "Grid.h"
#include "Defines.h"
#include "OptionModel.h"

/**
 * Prototype for visualization methods. It provides all necessary functionality of 
 * every method.
 */

class F{
    
public:
                                F();
        virtual                 ~F();
	virtual bool            setInput(Grid*);
	Grid*                   getOutput(int);
        virtual void            draw();
        void                    setOption(const QString key, QVariant value);
        int                     getLayer();
        bool                    setLayer(int layer);
        bool                    isReady();
        /** Executes computation in visualization method class.*/
	virtual bool		execute() = 0;
        virtual bool            updateOptions();
        
        OptionsMap              optionsMap; 
        OptionModel*            optionModel;
        
protected:
        void                    setProgress(int progress);    
        Grid*                   input_;
	std::vector<Grid*>	outputs_;
        int                     progress_;
        int                     layer_;
        bool                    ready_;
};
#endif