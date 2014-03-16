#include "TreeModel.h"

#include <QtGui>
#include <iostream>

/**
 * Constructor
 * @param parent Pointer to parent object.
 */
TreeModel::TreeModel(QObject *parent)
        : QAbstractItemModel(parent){

    rootItem = new TreeItem("Header");
    
}

/**
 * Destructor
 */

TreeModel::~TreeModel()
{
    SAFE_DELETE(rootItem);
}

/**
 * 
 * @param parent Reference to specific index in model.
 * @return Number of columns in TreeModel.
 */

int TreeModel::columnCount(const QModelIndex & parent) const
{
    return rootItem->columnCount();
}

/**
 * Function returns data from concrete item in tree model.
 * @param index Index of item in tree model.
 * @param role Role of item in tree model.
 * @return Data of concrete item.
 */
QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    TreeItem *item = getItem(index);

    return item->data(index.column());
}

/**
 * Function returns Qt flags for concrete item in tree model.
 * @param index Index of item in tree model.
 * @return Flags for concrete item in tree model.
 */
Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) return 0;

    return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}


/**
 * 
 * @param index Index of item in tree model.
 * @return Pointer to concrete item in tree model.
 */
TreeItem *TreeModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
        TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
        if (item) return item;
    }
    return rootItem;
}

/**
 * 
 * @param section Number of row/column
 * @param orientation 
 * @param role 
 * @return Header data of root item.
 */
QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);
    return QVariant();
}

/**
 * Converts item coordinates to specific index.
 * @param row Row number.
 * @param column Column number.
 * @param parent Index of parent item.
 * @return Index in tree model.
 */
QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();


    TreeItem *parentItem = getItem(parent);

    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}


/**
 * Insert new row in specific coordinates in tree model.
 * @param position Position of new row
 * @param rows Number of new rows.
 * @param parent Index of parent item.
 * @return True if success and false if failure.
 */
bool TreeModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    TreeItem *parentItem = getItem(parent);
    bool success;

    beginInsertRows(parent, position, position + rows - 1);
    success = parentItem->insertChildren(position, rows, rootItem->columnCount());
    endInsertRows();

    return success;
}

/**
 * 
 * @param index Index of item in tree model.
 * @return Index of parent item.
 */
QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = getItem(index);
    TreeItem *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->childNumber(), 0, parentItem);
}

/**
 * 
 * @param position Position of row in tree model.
 * @param rows Number of rows.
 * @param parent Index of parent item.
 * @return Delete status.
 */
bool TreeModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    TreeItem *parentItem = getItem(parent);
    bool success = true;

    beginRemoveRows(parent, position, position + rows - 1);
    success = parentItem->removeChildren(position, rows);
    endRemoveRows();

    return success;
}

/**
 * 
 * @param parent Paretnt of current item.
 * @return Number of child rows of item.
 */
int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem = getItem(parent);

    return parentItem->childCount();
}


/**
 * Sets data in specific item.
 * @param index Index of current item.
 * @param value Value to set in item.
 * @param role Role of item.
 * @return Status of setting data.
 */
bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole ) return false;
    TreeItem *item = getItem(index);
    bool result = false;
    QString name = value.toString();
    /*int i=0;
    
    while (listOfNames_.indexOf(name) != -1 ){
        name = value.toString()+QString::number(i);
        i++;
    }
    listOfNames_.push_back(name);*/
    result = item->setName(name);
    if (result) emit dataChanged(index, index);
    
    return result;
}

/**
 * Setting data in header item.
 * @param section Section to set data.
 * @param orientation Orientation of tree model.
 * @param value Value to set in header.
 * @param role Role of header item
 * @return Status of setting data in header.
 */
bool TreeModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (role != Qt::EditRole || orientation != Qt::Horizontal) return false;

    bool result = rootItem->setName(value.toString());
    return result;
}

/**
 * Setting method into visualization pipeline in specific item.
 * @param index Index of specific item.
 * @param method Method to set into item.
 * @return Status of setting method.
 */
bool TreeModel::setMethod(const QModelIndex& index, F* method){
    if (index.isValid()){
        TreeItem *item = getItem(index);
        item -> setMethod(method);
        return true;
    } else return false;
}

/**
 * This method connects output from parent item with input from current item. Then it executes visualization method in current item.
 * @param index Index of current item.
 */
void TreeModel::execute(const QModelIndex &index){
    if (!index.isValid()) return;
    TreeItem *item = getItem(index);
    
        //tutaj można kiedy zmienić sposób wywoływania metod
        if (item -> parent() == rootItem) {
            if(!item -> execute()) QMessageBox::warning(NULL, "Warning","Error in executing "+item -> data(0).toString());      
            else QMessageBox::information(NULL, "Information",item -> data(0).toString()+" executed");
        } else if (item -> parent() -> isReady()){
            item -> getMethod() -> setInput(item -> parent() -> getMethod() -> getOutput(0));
            if(!item -> execute()) QMessageBox::warning(NULL, "Warning","Something is wrong with "+item -> data(0).toString());
            else QMessageBox::information(NULL, "Information",item -> data(0).toString()+" executed");
        }
        else{
            QMessageBox::warning(NULL, "Warning",item -> parent() -> data(0).toString()+" is not ready...");
        }
    
}

/**
 * Get pointer to option model which contain visualization parameters.
 * @param index Index of item in model.
 * @return Return option model.
 */
OptionModel* TreeModel::getOptionsModel(const QModelIndex &index) const{
    if (index.isValid()){
        TreeItem* item = getItem(index);
        OptionModel* model = item -> getMethod() -> optionModel;
        return model;
    }
    else return 0;
}


/**
 * Get visualization method which is included in tree item.
 * @param index Index of item in tree model.
 * @return Visualization method which is included in item.
 */
F* TreeModel::getMethod(const QModelIndex &index) const{
    if(index.isValid()){
        return getItem(index) -> getMethod();
    }
    else return 0;
}
