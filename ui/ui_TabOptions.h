/********************************************************************************
** Form generated from reading UI file 'TabOptions.ui'
**
** Created: Tue Aug 13 15:24:37 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABOPTIONS_H
#define UI_TABOPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabOptions
{
public:

    void setupUi(QWidget *TabOptions)
    {
        if (TabOptions->objectName().isEmpty())
            TabOptions->setObjectName(QString::fromUtf8("TabOptions"));
        TabOptions->resize(400, 300);

        retranslateUi(TabOptions);

        QMetaObject::connectSlotsByName(TabOptions);
    } // setupUi

    void retranslateUi(QWidget *TabOptions)
    {
        TabOptions->setWindowTitle(QApplication::translate("TabOptions", "TabOptions", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TabOptions: public Ui_TabOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABOPTIONS_H
