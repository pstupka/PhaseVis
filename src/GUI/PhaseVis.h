/* 
 * File:   PhaseVis.h
 * Author: stup
 *
 * Created on July 11, 2013, 11:08 PM
 */

#ifndef _PHASEVIS_H
#define	_PHASEVIS_H

#include "ui_PhaseVis.h"
#include <QObject>

#include "TreeModel.h"
#include "MethodChooseDialog.h"
#include "TreeItem.h"
#include "LayerManager.h"


/**
 * Main class in application. It gathers references to all components and connect them. 
 * Here a model-view pattern was used.
 */
class PhaseVis : public QMainWindow, public Ui::PhaseVis{
    Q_OBJECT
    public:
        PhaseVis(QMainWindow* parent = 0);
        ~PhaseVis();
           
    public slots:
        void updateActions();
        void execute();
        void sendToDraw();

    public slots:
        void insertGridImporter();
        void insertVanDerPol();
        void insertVanDerPolDuffing();
        void insertMorrisLecar();
        void insertAndronovHopf();
        
        void insertChild();
        void insertRow();
        void removeRow();   
        
        void removeLayer();
        
        void updateOptions();
    
    private:
        void insertTopLevelItem(int type);
        TreeModel *model_;
        QItemSelectionModel *selectionModel_;
        LayerManager* layerManager_;

};


#endif	/* _PHASEVIS_H */
