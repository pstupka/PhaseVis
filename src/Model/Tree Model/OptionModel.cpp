#include "OptionModel.h"
#include "Defines.h"
#include <iostream>
#include <qt4/QtCore/qnamespace.h>

OptionModel::OptionModel(OptionsMap &optionsMap, QObject *parent)
        : QAbstractTableModel(parent), settings_(optionsMap){
} 

OptionModel::~OptionModel(){
    //if(settings_ != 0) SAFE_DELETE(settings_);
}

int OptionModel::rowCount(const QModelIndex& ) const {
    return settings_.count();
}

int OptionModel::columnCount(const QModelIndex& ) const{
    return 2;
}

QVariant OptionModel::data(const QModelIndex &index, int role) const{
    
    if (role == Qt::DisplayRole){
        if (index.column()) return settings_.values().value(index.row());
        else return settings_.keys().value(index.row());
    }
    else return QVariant();
}

bool OptionModel::setData(const QModelIndex & index, const QVariant & value, int role){
    if (role == Qt::EditRole){
        if(index.column()) {
            if (value == QVariant("")) return false;
            settings_.insert(settings_.keys().value(index.row()),value);
        }
        emit dataChanged(index,index);
    }
    return true;
}

Qt::ItemFlags OptionModel::flags(const QModelIndex & index) const {
    if (index.column()) return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled ;
    else return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant OptionModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole){
        if (section)return QVariant("Value");
        return name_;
    }

    return QVariant();
}

bool OptionModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role){
    if (orientation == Qt::Horizontal && role == Qt::EditRole && section == 0){
        name_ = value;
    }
}