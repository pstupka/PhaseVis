/* 
 * File:   OptionModel.h
 * Author: stup
 *
 * Created on September 13, 2013, 1:27 PM
 */

#ifndef OPTIONMODEL_H
#define	OPTIONMODEL_H

#include <QAbstractTableModel>


typedef QMap<QString,QVariant> OptionsMap;


/**
 * This class is used to handle the option pipeline. Each visualization method has its own set of options
 * to be set and OptionModel sends informations of any changes to concrete method.
 * 
 */
class OptionModel : public QAbstractTableModel{
    Q_OBJECT
   
    public:            
        OptionModel(OptionsMap& optionsMap, QObject *parent = 0);
        ~OptionModel();

        int rowCount(const QModelIndex &parent = QModelIndex()) const ;
        int columnCount(const QModelIndex &parent = QModelIndex()) const;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
        bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
        Qt::ItemFlags flags(const QModelIndex & index) const ;
    
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
        bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole);
    signals:
        void editCompleted(const QString &);
    
    private:
        QVariant name_;
        OptionsMap& settings_;
        
};

#endif	/* OPTIONMODEL_H */

