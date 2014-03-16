/*
 * File:   PhaseVis.cpp
 * Author: stup
 *
 * Created on July 11, 2013, 11:08 PM
 */

#include <qt4/QtCore/qnamespace.h>
#include <qt4/QtCore/qabstractitemmodel.h>

#include "GUI/PhaseVis.h"
#include "ui_PhaseVis.h"

#include "MethodCreator.h"
#include "LayerManager.h"


PhaseVis::PhaseVis(QMainWindow* parent) : QMainWindow(parent){
    
    setupUi(this);

    model_ = new TreeModel(this);
    selectionModel_ = new QItemSelectionModel(model_);

    treePipeline->setModel(model_);
    treePipeline -> setSelectionModel(selectionModel_);
    
    layerManager_ = new LayerManager(this);
    layerManager_ ->  setHeaderData(0,Qt::Horizontal, tr("Layer"));
    layerManager_ -> setHeaderData(1,Qt::Horizontal, tr("Visible"));
    layerView -> setModel(layerManager_);
    
    connect(layerManager_, SIGNAL(builLists(QList<F*>)), Display, SLOT(buildLists(QList<F*>)));
    
    connect(treePipeline -> selectionModel(),SIGNAL(selectionChanged(const QItemSelection &,const QItemSelection &)),this, SLOT(updateActions()));
    connect(treePipeline -> model(), SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(updateActions()));
    
    connect(treePipeline -> selectionModel(),SIGNAL(selectionChanged(const QItemSelection &,const QItemSelection &)),this, SLOT(updateOptions()));

    connect(importGridAction, SIGNAL(triggered()), this, SLOT(insertGridImporter()));
    connect(addMethodAsRowAction, SIGNAL(triggered()), this, SLOT(insertRow()));
    connect(addMethodAsChildAction, SIGNAL(triggered()), this, SLOT(insertChild()));
    connect(executeButton, SIGNAL(clicked()), this, SLOT(execute()));
    connect(addToLayersButton, SIGNAL(clicked()), this, SLOT(sendToDraw()));  
    
    connect(drawButton, SIGNAL(clicked()), layerManager_, SLOT(draw()));  
    connect(removeLayerButton, SIGNAL(clicked()), this, SLOT(removeLayer()));  

    connect(removeMethodAction, SIGNAL(triggered()), this, SLOT(removeRow()));
    
    connect(actionVanDerPol, SIGNAL(triggered()), this, SLOT(insertVanDerPol()));   
    connect(actionVanDerPolDuffing, SIGNAL(triggered()), this, SLOT(insertVanDerPolDuffing()));   
    connect(actionMorrisLecar, SIGNAL(triggered()), this, SLOT(insertMorrisLecar())); 
    connect(actionAndronovHopf, SIGNAL(triggered()), this, SLOT(insertAndronovHopf()));   
    
    insertGridImporter();
    
    updateActions();
}

PhaseVis::~PhaseVis(){
}

/**
 * This method create new visualization method and puts it to pipeline.
 * @param type Type of method 
 */
void PhaseVis::insertTopLevelItem(int type){
    
    MethodCreator creator;
    QModelIndex index;
    
    if (creator.createMethod(type)){
        if (!model_->insertRow(index.row()+1, index.parent())){
            return;
        }

        QModelIndex child = model_ -> index(index.row()+1, 0, index.parent());
            model_ -> setMethod(child, creator.chosenMethod());
            model_ -> setData(child, creator.chosenName(),Qt::EditRole);
        treePipeline->selectionModel()->setCurrentIndex(model_->index(0, 0, index),QItemSelectionModel::ClearAndSelect);
    }
    updateActions();
}

/**
 * Inserts child component to selected method in pipeline. 
 */
void PhaseVis::insertChild()
{
    MethodCreator creator;
    QModelIndex index = treePipeline->selectionModel()->currentIndex();
    
    if (creator.createMethod()){
        if (!model_->insertRow(0, index)){
            return;
        }

        QModelIndex child = model_->index(0, 0, index);
            model_ -> setMethod(child, creator.chosenMethod());
            model_ -> setData(child, creator.chosenName(),Qt::EditRole);
        treePipeline->selectionModel()->setCurrentIndex(model_->index(0, 0, index),QItemSelectionModel::ClearAndSelect);
    }
    updateActions();
}

/**
 * This method inserts new visualization method as row. New method is inserted below the selected one.
 */
void PhaseVis::insertRow()
{
    MethodCreator creator;
    QModelIndex index = treePipeline->selectionModel()->currentIndex();
    
    if (creator.createMethod()){
        if (!model_->insertRow(index.row()+1, index.parent())){
            return;
        }

        QModelIndex child = model_->index(index.row()+1, 0, index.parent());
            model_ -> setMethod(child, creator.chosenMethod());
            model_ -> setData(child, creator.chosenName(),Qt::EditRole);
        treePipeline->selectionModel()->setCurrentIndex(child,QItemSelectionModel::ClearAndSelect);
    }
    updateActions();
}


/**
 * This method removes selected item in visualization pipeline.
 */
void PhaseVis::removeRow()
{
    QModelIndex index = treePipeline->selectionModel()->currentIndex();
    if (model_->removeRow(index.row(), index.parent()))
        updateActions();
}

/**
 * This method updates status of all actions in menu bar and in method creator.
 */
void PhaseVis::updateActions()
{
    QModelIndex currentIndex = treePipeline->selectionModel()->currentIndex();
    
    bool hasValidParent = currentIndex.parent().isValid();
    bool hasCurrent = currentIndex.isValid();
    addMethodAsRowAction -> setEnabled(hasCurrent);
    addMethodAsChildAction -> setEnabled(hasCurrent);

    if(hasCurrent){
        addMethodAsRowAction -> setEnabled(hasValidParent);
        importGridAction -> setEnabled(!hasValidParent);
    }
    
        
}

/**
 * Method executes selected visualization item.
 */
void PhaseVis::execute(){
    QModelIndex currentIndex = treePipeline->selectionModel()->currentIndex();
    if(currentIndex.isValid() && currentIndex.column() == 0){
        model_ -> execute(currentIndex);
        //draw();
    }
}

/**
 * This method sends information to OpenGL display about all components to be draw.
 */
void PhaseVis::sendToDraw(){
    
    QModelIndex currentIndex = treePipeline -> selectionModel() -> currentIndex();
    F* method = model_ -> getMethod(currentIndex);
    layerManager_ -> addToLayer(method,model_ -> data(currentIndex).toString(), layerView -> selectionModel() -> currentIndex().parent());
    //layerView->selectionModel()->setCurrentIndex(currentIndex.row(),QItemSelectionModel::ClearAndSelect);
}

/**
 * Method removes layer in display table.
 */
void PhaseVis::removeLayer(){
    QModelIndex currentIndex = layerView -> selectionModel() -> currentIndex();

    layerManager_ -> removeLayer(currentIndex.row(),currentIndex.parent());
}

/**
 * Inserts Grid Importer method to visualization pipeline. It is generator of vector field.
 */
void PhaseVis::insertGridImporter(){
    insertTopLevelItem(MethodCreator::GridImporterMethod);
}

/**
 * Inserts as top level item van der Pol data generator.
 */
void PhaseVis::insertVanDerPol(){
    insertTopLevelItem(MethodCreator::GenerateVanDerPolMethod);
}
/**
 * Inserts as top level item van der Pol-Duffing data generator.
 */
void PhaseVis::insertVanDerPolDuffing(){
    insertTopLevelItem(MethodCreator::GenerateVanDerPolDuffingMethod);
}
/**
 * Inserts as top level item Morris-Lecar data generator.
 */
void PhaseVis::insertMorrisLecar(){
    insertTopLevelItem(MethodCreator::GenerateMorrisLecarMethod);
}
/**
 * Inserts as top level item Andronov-Hopf data generator.
 */
void PhaseVis::insertAndronovHopf(){
    insertTopLevelItem(MethodCreator::GenerateAndronovHopfMethod);
}

/**
 * This method updates options in selected visualization method in pipeline.
 */
void PhaseVis::updateOptions(){
    QModelIndex currentIndex = treePipeline -> selectionModel() -> currentIndex();
    if(!currentIndex.column()){
        model_ -> getOptionsModel(currentIndex) -> setHeaderData(0,Qt::Horizontal,model_ -> data(currentIndex));
        optionsView -> setModel(model_ -> getOptionsModel(currentIndex));
    }

}