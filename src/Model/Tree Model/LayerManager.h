/* 
 * File:   LayerManager.h
 * Author: stup
 *
 * Created on September 24, 2013, 10:38 PM
 */

#ifndef LAYERMANAGER_H
#define	LAYERMANAGER_H

#include <QAbstractTableModel>
#include "F.h"

typedef QMap< QPair<F*, QString>, int> LayerMap;

class LayerManager : public QAbstractTableModel{
    Q_OBJECT
   
    public:            
        LayerManager(QObject *parent = 0);
        ~LayerManager();

        int rowCount(const QModelIndex &parent = QModelIndex()) const ;
        int columnCount(const QModelIndex &parent = QModelIndex()) const;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
        bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
        Qt::ItemFlags flags(const QModelIndex & index) const ;
    
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
        
        bool addToLayer(F* method, const QString& name, const QModelIndex& parent);
        bool removeLayer(int row, const QModelIndex& parent);
        
   signals:
        void editCompleted(const QString &);
        void builLists(QList<F*> f);
        
   public slots:    
        void draw();

    private:
        QVariant name_;
        LayerMap layers_;  //inta wykorzystać do wyboru flagi mieszania warstw: 0 - invisible, 1 - add itp.
        
};

#endif	/* LAYERMANAGER_H */

