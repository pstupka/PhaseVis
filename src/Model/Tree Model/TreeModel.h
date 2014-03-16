#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include "TreeItem.h"
#include "OptionModel.h"

/**
 * Tree Model is a part of model-view programming. It contains references to all
 * items in visualization pipeline. It is useful to manage visualization pipeline.
 * @anchor TreeModel
 */

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    TreeModel( QObject *parent = 0);
    ~TreeModel();


    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole);

    bool insertRows(int position, int rows, const QModelIndex &parent = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &parent = QModelIndex());

    bool setMethod(const QModelIndex &index, F* method);
    void execute(const QModelIndex &index);
    
    //void setSetting(const QModelIndex &index, QMap<QString, QVariant> settings);
    OptionModel* getOptionsModel(const QModelIndex &index) const;
    
    F* getMethod(const QModelIndex &index) const;
    

private:
    TreeItem *getItem(const QModelIndex &index) const;
    
    TreeItem *rootItem;

};

#endif

