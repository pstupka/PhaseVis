#include "LayerManager.h"
#include "Defines.h"
#include <iostream>
#include <qt4/QtCore/qabstractitemmodel.h>

LayerManager::LayerManager(QObject *parent)
        : QAbstractTableModel(parent){
} 

LayerManager::~LayerManager(){
}

int LayerManager::rowCount(const QModelIndex& ) const {
    return layers_.count();
}

int LayerManager::columnCount(const QModelIndex& ) const{
    return 3;
}

QVariant LayerManager::data(const QModelIndex &index, int role) const{
    
    if (role == Qt::DisplayRole){
        switch (index.column()){
            case 0: return layers_.keys().value(index.row()).second; 
            case 1: return layers_.keys().value(index.row()).first->getLayer();
            case 2: return layers_.values().value(index.row());
            default: break;
        }
    }
    else return QVariant();
}

bool LayerManager::setData(const QModelIndex & index, const QVariant & value, int role){
    if (role == Qt::EditRole){
        if (value == QVariant("")) return false;
        switch (index.column()){
            case 1: layers_.keys().value(index.row()).first->setLayer(value.toInt());break;
            case 2: layers_.insert(layers_.keys().value(index.row()),value.toInt());break;
            default: break;
        }
        emit dataChanged(index,index);
    }
    return true;
}

Qt::ItemFlags LayerManager::flags(const QModelIndex & index) const {
    if (index.column()) return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled ;
    else return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant LayerManager::headerData(int section, Qt::Orientation orientation, int role) const{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole){
        switch (section){
            case 0: return QVariant("Layer"); 
            case 1: return QVariant("Layer number");
            case 2: return QVariant("Display mode");
            default: break;
        }
    }

    return QVariant();
}

bool LayerManager::addToLayer(F* method, const QString& name, const QModelIndex& parent){
    QPair<F*, QString> tmp(method, name);
    if (!layers_.contains(tmp)){
        beginInsertRows(parent, 0, 0);
            tmp.first->setLayer(layers_.count());
            layers_.insert(tmp, 1);
        endInsertRows();
    }
    return true;
}

bool LayerManager::removeLayer(int row, const QModelIndex& parentIndex){
    bool success = false;
    if (row != -1){
        beginRemoveRows(parentIndex, row, row);
        layers_.remove(layers_.keys().at(row));
        endRemoveRows();
        success = true;
        emit dataChanged(parentIndex,parentIndex);
    }
    return success;
}


 void LayerManager::draw(){
    QList<F*> list;
    
    LayerMap::const_iterator i = layers_.constBegin();
    while (i != layers_.constEnd()) {
        if(i.key().first != 0 && i.value() > 0)
        if(i.key().first -> isReady()){
        list.insert(i.key().first->getLayer(),i.key().first);
        }
        ++i;
    }
    if (list.count())emit builLists(list);

 }
 