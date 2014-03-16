#include "MethodChooseDialog.h"
#include <iostream>

MethodChooseDialog::MethodChooseDialog(const QMap<QString, int> &data, QWidget* parent) : QDialog(parent){
    setupUi(this);
    
    
    QMap<QString, int>::const_iterator i = data.constBegin();
    while (i != data.constEnd()) {
        methodList -> addItem(i.key());
        ++i;
    }
}

MethodChooseDialog::~MethodChooseDialog(){
    
}