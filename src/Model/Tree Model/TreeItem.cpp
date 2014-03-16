#include "TreeItem.h"
#include "Defines.h"
#include <iostream>

#include "TreeItem.h"

TreeItem::TreeItem(const QString &name, TreeItem *parent) : method_(0)
{
    parentItem_ = parent;
    itemName_ = name;
}

TreeItem::~TreeItem()
{
    qDeleteAll(childItems_);
    if(method_ != 0) SAFE_DELETE(method_);
}

TreeItem *TreeItem::child(int number)
{
    return childItems_.value(number);
}

int TreeItem::childCount() const
{
    return childItems_.count();
}

int TreeItem::childNumber() const
{
    if (parentItem_)
        return parentItem_ -> childItems_.indexOf(const_cast<TreeItem*>(this));
    return 0;
}

int TreeItem::columnCount() const
{
    return 1;
}

QVariant TreeItem::data(int column) const
{
    if (column) return QVariant();
    return itemName_;
}

bool TreeItem::insertChildren(int position, int count, int /*columns*/)
{
    if (position < 0 || position > childItems_.size()) return false;

    for (int row = 0; row < count; ++row) {
        TreeItem *item = new TreeItem("", this);
        childItems_.insert(position, item);
    }

    return true;
}

TreeItem *TreeItem::parent()
{
    return parentItem_;
}

bool TreeItem::removeChildren(int position, int count)
{
    if (position < 0 || position + count > childItems_.size())
        return false;

    for (int row = 0; row < count; ++row)
        delete childItems_.takeAt(position);
    
    return true;
}

bool TreeItem::setName(const QString &name)
{
    itemName_ = name;
    return true;
}

bool TreeItem::setMethod(F* method){
    
    if (method_ != 0){
        SAFE_DELETE(method_);
    }
    method_ = method;
    return true;
}


bool TreeItem::isReady(){
    if (method_ == 0) return false;
    return method_ -> isReady();
}

bool TreeItem::execute(){
    if (method_ == 0){
        QMessageBox::information(NULL,"Warning" ,"There is no method in "+data(0).toString());
        return false;        
    }
    return method_ -> execute();
}

F*   TreeItem::getMethod() const{
   return method_;
}