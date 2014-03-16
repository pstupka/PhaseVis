#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QVariant>
#include <QVector>
#include <QMessageBox>

#include "F.h"
#include "OptionModel.h"

/**
 * This class provides functionality of handling the items in tree model. Each tree item has its 
 * own pointer to visualization method wchich will be executed.
 */
class TreeItem
{
public:
    TreeItem(const QString &name, TreeItem *parent = 0);
    ~TreeItem();

    TreeItem *child(int number);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    bool insertChildren(int position, int count, int columns);
    TreeItem *parent();
    bool removeChildren(int position, int count);
    int childNumber() const;
    bool setName(const QString &name);
    
    bool setMethod(F* method);
    
    bool isReady();
    bool execute();
    F*   getMethod() const;
    

private:
    
    F* method_;
    QList<TreeItem*> childItems_;
    QString itemName_;
    TreeItem *parentItem_;
};


#endif
