/********************************************************************************
** Form generated from reading UI file 'PhaseVis.ui'
**
** Created: Fri Mar 14 12:57:37 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHASEVIS_H
#define UI_PHASEVIS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTreeView>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "Display/glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_PhaseVis
{
public:
    QAction *actionExit;
    QAction *actionAuthor;
    QAction *addMethodAsChildAction;
    QAction *removeMethodAction;
    QAction *actionVisualization_Pipeline;
    QAction *actionVisualization_Options;
    QAction *actionDisplay_Options;
    QAction *importGridAction;
    QAction *actionApplication;
    QAction *addMethodAsRowAction;
    QAction *saveFrameBufferAction;
    QAction *actionVanDerPol;
    QAction *actionVanDerPolDuffing;
    QAction *actionMorrisLecar;
    QAction *actionModels;
    QAction *actionLayer_Manager;
    QAction *actionAndronovHopf;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    GLWidget *Display;
    QStatusBar *statusbar;
    QMenuBar *MenuBar;
    QMenu *menuMain;
    QMenu *menuAbout;
    QMenu *menuActions;
    QMenu *menuView;
    QMenu *menuGenerate_Data;
    QDockWidget *dockVisPipeline;
    QWidget *dockWidgetContents_2;
    QHBoxLayout *horizontalLayout;
    QTreeView *treePipeline;
    QDockWidget *dockPipelineOptions;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout;
    QTableView *optionsView;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *executeButton;
    QPushButton *addToLayersButton;
    QDockWidget *dockDisplayOptions;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_4;
    QTreeWidget *treeWidget_2;
    QPushButton *saveScreenshotButton;
    QDockWidget *dockLayer_Manager;
    QWidget *dockWidgetContents_5;
    QVBoxLayout *verticalLayout_2;
    QTableView *layerView;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *drawButton;
    QPushButton *removeLayerButton;

    void setupUi(QMainWindow *PhaseVis)
    {
        if (PhaseVis->objectName().isEmpty())
            PhaseVis->setObjectName(QString::fromUtf8("PhaseVis"));
        PhaseVis->resize(1152, 801);
        PhaseVis->setMaximumSize(QSize(3000, 3000));
        PhaseVis->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionExit = new QAction(PhaseVis);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAuthor = new QAction(PhaseVis);
        actionAuthor->setObjectName(QString::fromUtf8("actionAuthor"));
        addMethodAsChildAction = new QAction(PhaseVis);
        addMethodAsChildAction->setObjectName(QString::fromUtf8("addMethodAsChildAction"));
        removeMethodAction = new QAction(PhaseVis);
        removeMethodAction->setObjectName(QString::fromUtf8("removeMethodAction"));
        actionVisualization_Pipeline = new QAction(PhaseVis);
        actionVisualization_Pipeline->setObjectName(QString::fromUtf8("actionVisualization_Pipeline"));
        actionVisualization_Pipeline->setCheckable(true);
        actionVisualization_Options = new QAction(PhaseVis);
        actionVisualization_Options->setObjectName(QString::fromUtf8("actionVisualization_Options"));
        actionVisualization_Options->setCheckable(true);
        actionDisplay_Options = new QAction(PhaseVis);
        actionDisplay_Options->setObjectName(QString::fromUtf8("actionDisplay_Options"));
        actionDisplay_Options->setCheckable(true);
        importGridAction = new QAction(PhaseVis);
        importGridAction->setObjectName(QString::fromUtf8("importGridAction"));
        actionApplication = new QAction(PhaseVis);
        actionApplication->setObjectName(QString::fromUtf8("actionApplication"));
        addMethodAsRowAction = new QAction(PhaseVis);
        addMethodAsRowAction->setObjectName(QString::fromUtf8("addMethodAsRowAction"));
        saveFrameBufferAction = new QAction(PhaseVis);
        saveFrameBufferAction->setObjectName(QString::fromUtf8("saveFrameBufferAction"));
        actionVanDerPol = new QAction(PhaseVis);
        actionVanDerPol->setObjectName(QString::fromUtf8("actionVanDerPol"));
        actionVanDerPolDuffing = new QAction(PhaseVis);
        actionVanDerPolDuffing->setObjectName(QString::fromUtf8("actionVanDerPolDuffing"));
        actionMorrisLecar = new QAction(PhaseVis);
        actionMorrisLecar->setObjectName(QString::fromUtf8("actionMorrisLecar"));
        actionModels = new QAction(PhaseVis);
        actionModels->setObjectName(QString::fromUtf8("actionModels"));
        actionLayer_Manager = new QAction(PhaseVis);
        actionLayer_Manager->setObjectName(QString::fromUtf8("actionLayer_Manager"));
        actionLayer_Manager->setCheckable(true);
        actionAndronovHopf = new QAction(PhaseVis);
        actionAndronovHopf->setObjectName(QString::fromUtf8("actionAndronovHopf"));
        centralwidget = new QWidget(PhaseVis);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Display = new GLWidget(centralwidget);
        Display->setObjectName(QString::fromUtf8("Display"));
        Display->setMinimumSize(QSize(480, 480));
        Display->setMaximumSize(QSize(2000, 2000));

        horizontalLayout_2->addWidget(Display);

        PhaseVis->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(PhaseVis);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PhaseVis->setStatusBar(statusbar);
        MenuBar = new QMenuBar(PhaseVis);
        MenuBar->setObjectName(QString::fromUtf8("MenuBar"));
        MenuBar->setGeometry(QRect(0, 0, 1152, 20));
        MenuBar->setDefaultUp(false);
        MenuBar->setNativeMenuBar(false);
        menuMain = new QMenu(MenuBar);
        menuMain->setObjectName(QString::fromUtf8("menuMain"));
        menuAbout = new QMenu(MenuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuActions = new QMenu(MenuBar);
        menuActions->setObjectName(QString::fromUtf8("menuActions"));
        menuView = new QMenu(MenuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuGenerate_Data = new QMenu(MenuBar);
        menuGenerate_Data->setObjectName(QString::fromUtf8("menuGenerate_Data"));
        PhaseVis->setMenuBar(MenuBar);
        dockVisPipeline = new QDockWidget(PhaseVis);
        dockVisPipeline->setObjectName(QString::fromUtf8("dockVisPipeline"));
        dockVisPipeline->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockVisPipeline->setWindowTitle(QString::fromUtf8("Visualization Pipeline"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        horizontalLayout = new QHBoxLayout(dockWidgetContents_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treePipeline = new QTreeView(dockWidgetContents_2);
        treePipeline->setObjectName(QString::fromUtf8("treePipeline"));
        treePipeline->setAlternatingRowColors(true);
        treePipeline->header()->setVisible(false);

        horizontalLayout->addWidget(treePipeline);

        dockVisPipeline->setWidget(dockWidgetContents_2);
        PhaseVis->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockVisPipeline);
        dockPipelineOptions = new QDockWidget(PhaseVis);
        dockPipelineOptions->setObjectName(QString::fromUtf8("dockPipelineOptions"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        optionsView = new QTableView(dockWidgetContents_3);
        optionsView->setObjectName(QString::fromUtf8("optionsView"));
        optionsView->setDragEnabled(false);
        optionsView->setDragDropMode(QAbstractItemView::NoDragDrop);
        optionsView->setAlternatingRowColors(true);
        optionsView->setSelectionMode(QAbstractItemView::SingleSelection);
        optionsView->setSelectionBehavior(QAbstractItemView::SelectRows);
        optionsView->setShowGrid(true);
        optionsView->horizontalHeader()->setCascadingSectionResizes(false);
        optionsView->horizontalHeader()->setStretchLastSection(true);
        optionsView->verticalHeader()->setVisible(false);
        optionsView->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(optionsView);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        executeButton = new QPushButton(dockWidgetContents_3);
        executeButton->setObjectName(QString::fromUtf8("executeButton"));
        executeButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(executeButton);

        addToLayersButton = new QPushButton(dockWidgetContents_3);
        addToLayersButton->setObjectName(QString::fromUtf8("addToLayersButton"));
        addToLayersButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(addToLayersButton);


        verticalLayout->addLayout(horizontalLayout_8);

        dockPipelineOptions->setWidget(dockWidgetContents_3);
        PhaseVis->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockPipelineOptions);
        dockDisplayOptions = new QDockWidget(PhaseVis);
        dockDisplayOptions->setObjectName(QString::fromUtf8("dockDisplayOptions"));
        dockDisplayOptions->setEnabled(true);
        dockDisplayOptions->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        treeWidget_2 = new QTreeWidget(dockWidgetContents_4);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("Option"));
        treeWidget_2->setHeaderItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget_2);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem2->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem2);
        __qtreewidgetitem3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem2);
        __qtreewidgetitem4->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem2);
        __qtreewidgetitem5->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(__qtreewidgetitem2);
        __qtreewidgetitem6->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(__qtreewidgetitem7);
        __qtreewidgetitem8->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem9 = new QTreeWidgetItem(__qtreewidgetitem7);
        __qtreewidgetitem9->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem10 = new QTreeWidgetItem(__qtreewidgetitem7);
        __qtreewidgetitem10->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem11 = new QTreeWidgetItem(__qtreewidgetitem7);
        __qtreewidgetitem11->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem12 = new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem13 = new QTreeWidgetItem(__qtreewidgetitem12);
        __qtreewidgetitem13->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem14 = new QTreeWidgetItem(__qtreewidgetitem12);
        __qtreewidgetitem14->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem15 = new QTreeWidgetItem(__qtreewidgetitem12);
        __qtreewidgetitem15->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem16 = new QTreeWidgetItem(__qtreewidgetitem12);
        __qtreewidgetitem16->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem17 = new QTreeWidgetItem(treeWidget_2);
        QTreeWidgetItem *__qtreewidgetitem18 = new QTreeWidgetItem(__qtreewidgetitem17);
        QTreeWidgetItem *__qtreewidgetitem19 = new QTreeWidgetItem(__qtreewidgetitem18);
        __qtreewidgetitem19->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem20 = new QTreeWidgetItem(__qtreewidgetitem18);
        __qtreewidgetitem20->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem21 = new QTreeWidgetItem(__qtreewidgetitem18);
        __qtreewidgetitem21->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem22 = new QTreeWidgetItem(__qtreewidgetitem17);
        __qtreewidgetitem22->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        treeWidget_2->setObjectName(QString::fromUtf8("treeWidget_2"));
        treeWidget_2->setAlternatingRowColors(true);

        verticalLayout_4->addWidget(treeWidget_2);

        saveScreenshotButton = new QPushButton(dockWidgetContents_4);
        saveScreenshotButton->setObjectName(QString::fromUtf8("saveScreenshotButton"));

        verticalLayout_4->addWidget(saveScreenshotButton);

        dockDisplayOptions->setWidget(dockWidgetContents_4);
        PhaseVis->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockDisplayOptions);
        dockLayer_Manager = new QDockWidget(PhaseVis);
        dockLayer_Manager->setObjectName(QString::fromUtf8("dockLayer_Manager"));
        dockLayer_Manager->setMinimumSize(QSize(226, 150));
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QString::fromUtf8("dockWidgetContents_5"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        layerView = new QTableView(dockWidgetContents_5);
        layerView->setObjectName(QString::fromUtf8("layerView"));
        layerView->setAlternatingRowColors(true);
        layerView->setSelectionMode(QAbstractItemView::SingleSelection);
        layerView->setSelectionBehavior(QAbstractItemView::SelectRows);
        layerView->setShowGrid(false);
        layerView->horizontalHeader()->setStretchLastSection(true);
        layerView->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(layerView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        drawButton = new QPushButton(dockWidgetContents_5);
        drawButton->setObjectName(QString::fromUtf8("drawButton"));

        horizontalLayout_3->addWidget(drawButton);

        removeLayerButton = new QPushButton(dockWidgetContents_5);
        removeLayerButton->setObjectName(QString::fromUtf8("removeLayerButton"));

        horizontalLayout_3->addWidget(removeLayerButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        dockLayer_Manager->setWidget(dockWidgetContents_5);
        PhaseVis->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockLayer_Manager);

        MenuBar->addAction(menuMain->menuAction());
        MenuBar->addAction(menuActions->menuAction());
        MenuBar->addAction(menuGenerate_Data->menuAction());
        MenuBar->addAction(menuView->menuAction());
        MenuBar->addAction(menuAbout->menuAction());
        menuMain->addAction(saveFrameBufferAction);
        menuMain->addSeparator();
        menuMain->addAction(actionExit);
        menuAbout->addAction(actionAuthor);
        menuAbout->addAction(actionApplication);
        menuAbout->addAction(actionModels);
        menuActions->addAction(importGridAction);
        menuActions->addSeparator();
        menuActions->addAction(addMethodAsChildAction);
        menuActions->addAction(addMethodAsRowAction);
        menuActions->addSeparator();
        menuActions->addAction(removeMethodAction);
        menuView->addAction(actionVisualization_Pipeline);
        menuView->addAction(actionVisualization_Options);
        menuView->addAction(actionDisplay_Options);
        menuView->addAction(actionLayer_Manager);
        menuGenerate_Data->addAction(actionVanDerPol);
        menuGenerate_Data->addAction(actionVanDerPolDuffing);
        menuGenerate_Data->addAction(actionMorrisLecar);
        menuGenerate_Data->addAction(actionAndronovHopf);

        retranslateUi(PhaseVis);
        QObject::connect(actionExit, SIGNAL(triggered()), PhaseVis, SLOT(close()));
        QObject::connect(actionVisualization_Pipeline, SIGNAL(triggered(bool)), dockVisPipeline, SLOT(setVisible(bool)));
        QObject::connect(dockVisPipeline, SIGNAL(visibilityChanged(bool)), actionVisualization_Pipeline, SLOT(setChecked(bool)));
        QObject::connect(actionVisualization_Options, SIGNAL(triggered(bool)), dockPipelineOptions, SLOT(setVisible(bool)));
        QObject::connect(dockPipelineOptions, SIGNAL(visibilityChanged(bool)), actionVisualization_Options, SLOT(setChecked(bool)));
        QObject::connect(actionDisplay_Options, SIGNAL(triggered(bool)), dockDisplayOptions, SLOT(setVisible(bool)));
        QObject::connect(dockDisplayOptions, SIGNAL(visibilityChanged(bool)), actionDisplay_Options, SLOT(setChecked(bool)));
        QObject::connect(saveScreenshotButton, SIGNAL(clicked()), Display, SLOT(saveImage()));
        QObject::connect(saveFrameBufferAction, SIGNAL(triggered()), Display, SLOT(saveImage()));
        QObject::connect(actionLayer_Manager, SIGNAL(triggered(bool)), dockLayer_Manager, SLOT(setVisible(bool)));
        QObject::connect(dockLayer_Manager, SIGNAL(visibilityChanged(bool)), actionLayer_Manager, SLOT(setChecked(bool)));

        QMetaObject::connectSlotsByName(PhaseVis);
    } // setupUi

    void retranslateUi(QMainWindow *PhaseVis)
    {
        PhaseVis->setWindowTitle(QApplication::translate("PhaseVis", "PhaseVis", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("PhaseVis", "Exit", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("PhaseVis", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionAuthor->setText(QApplication::translate("PhaseVis", "Author", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAuthor->setToolTip(QApplication::translate("PhaseVis", "Author", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addMethodAsChildAction->setText(QApplication::translate("PhaseVis", "Add Method as Child", 0, QApplication::UnicodeUTF8));
        addMethodAsChildAction->setShortcut(QApplication::translate("PhaseVis", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        removeMethodAction->setText(QApplication::translate("PhaseVis", "Remove Method", 0, QApplication::UnicodeUTF8));
        actionVisualization_Pipeline->setText(QApplication::translate("PhaseVis", "Visualization Pipeline", 0, QApplication::UnicodeUTF8));
        actionVisualization_Options->setText(QApplication::translate("PhaseVis", "Visualization Options", 0, QApplication::UnicodeUTF8));
        actionDisplay_Options->setText(QApplication::translate("PhaseVis", "Display Options", 0, QApplication::UnicodeUTF8));
        importGridAction->setText(QApplication::translate("PhaseVis", "Import Grid", 0, QApplication::UnicodeUTF8));
        actionApplication->setText(QApplication::translate("PhaseVis", "Application", 0, QApplication::UnicodeUTF8));
        addMethodAsRowAction->setText(QApplication::translate("PhaseVis", "Add Method as Row", 0, QApplication::UnicodeUTF8));
        saveFrameBufferAction->setText(QApplication::translate("PhaseVis", "Save Frame Buffer as...", 0, QApplication::UnicodeUTF8));
        actionVanDerPol->setText(QApplication::translate("PhaseVis", "Van Der Pol Oscillator", 0, QApplication::UnicodeUTF8));
        actionVanDerPolDuffing->setText(QApplication::translate("PhaseVis", "Van Der Pol - Duffing Oscillator", 0, QApplication::UnicodeUTF8));
        actionMorrisLecar->setText(QApplication::translate("PhaseVis", "Morris - Lecar Model", 0, QApplication::UnicodeUTF8));
        actionModels->setText(QApplication::translate("PhaseVis", "Models", 0, QApplication::UnicodeUTF8));
        actionLayer_Manager->setText(QApplication::translate("PhaseVis", "Layer Manager", 0, QApplication::UnicodeUTF8));
        actionAndronovHopf->setText(QApplication::translate("PhaseVis", "Andronov - Hopf Oscillator", 0, QApplication::UnicodeUTF8));
        menuMain->setTitle(QApplication::translate("PhaseVis", "Main", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("PhaseVis", "About", 0, QApplication::UnicodeUTF8));
        menuActions->setTitle(QApplication::translate("PhaseVis", "Vis", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("PhaseVis", "View", 0, QApplication::UnicodeUTF8));
        menuGenerate_Data->setTitle(QApplication::translate("PhaseVis", "Generate Data", 0, QApplication::UnicodeUTF8));
        dockPipelineOptions->setWindowTitle(QApplication::translate("PhaseVis", "Visualization Options", 0, QApplication::UnicodeUTF8));
        executeButton->setText(QApplication::translate("PhaseVis", "Execute", 0, QApplication::UnicodeUTF8));
        addToLayersButton->setText(QApplication::translate("PhaseVis", "Add to Layers", 0, QApplication::UnicodeUTF8));
        dockDisplayOptions->setWindowTitle(QApplication::translate("PhaseVis", "Display Options", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_2->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("PhaseVis", "Value", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = treeWidget_2->isSortingEnabled();
        treeWidget_2->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget_2->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("PhaseVis", "Lighting Options", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("PhaseVis", "Light Position", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(1, QApplication::translate("PhaseVis", "0", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem3->setText(0, QApplication::translate("PhaseVis", "x", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem2->child(1);
        ___qtreewidgetitem4->setText(1, QApplication::translate("PhaseVis", "0", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem4->setText(0, QApplication::translate("PhaseVis", "y", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem2->child(2);
        ___qtreewidgetitem5->setText(1, QApplication::translate("PhaseVis", "0", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem5->setText(0, QApplication::translate("PhaseVis", "z", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem2->child(3);
        ___qtreewidgetitem6->setText(1, QApplication::translate("PhaseVis", "0", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem6->setText(0, QApplication::translate("PhaseVis", "w", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem7->setText(0, QApplication::translate("PhaseVis", "Ambient Light", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem7->child(0);
        ___qtreewidgetitem8->setText(1, QApplication::translate("PhaseVis", "0", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem8->setText(0, QApplication::translate("PhaseVis", "R", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem7->child(1);
        ___qtreewidgetitem9->setText(1, QApplication::translate("PhaseVis", "0", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem9->setText(0, QApplication::translate("PhaseVis", "G", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem7->child(2);
        ___qtreewidgetitem10->setText(1, QApplication::translate("PhaseVis", "0", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem10->setText(0, QApplication::translate("PhaseVis", "B", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem7->child(3);
        ___qtreewidgetitem11->setText(1, QApplication::translate("PhaseVis", "1", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem11->setText(0, QApplication::translate("PhaseVis", "A", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem12->setText(0, QApplication::translate("PhaseVis", "Diffuse Light", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem12->child(0);
        ___qtreewidgetitem13->setText(1, QApplication::translate("PhaseVis", "0", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem13->setText(0, QApplication::translate("PhaseVis", "R", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem12->child(1);
        ___qtreewidgetitem14->setText(1, QApplication::translate("PhaseVis", "0", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem14->setText(0, QApplication::translate("PhaseVis", "G", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem15 = ___qtreewidgetitem12->child(2);
        ___qtreewidgetitem15->setText(1, QApplication::translate("PhaseVis", "0", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem15->setText(0, QApplication::translate("PhaseVis", "B", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem16 = ___qtreewidgetitem12->child(3);
        ___qtreewidgetitem16->setText(1, QApplication::translate("PhaseVis", "1", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem16->setText(0, QApplication::translate("PhaseVis", "A", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem17 = treeWidget_2->topLevelItem(1);
        ___qtreewidgetitem17->setText(0, QApplication::translate("PhaseVis", "Orientation & scaling", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem18 = ___qtreewidgetitem17->child(0);
        ___qtreewidgetitem18->setText(0, QApplication::translate("PhaseVis", "Rotation", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem18->child(0);
        ___qtreewidgetitem19->setText(0, QApplication::translate("PhaseVis", "X rotatiom", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem20 = ___qtreewidgetitem18->child(1);
        ___qtreewidgetitem20->setText(0, QApplication::translate("PhaseVis", "Y rotation", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem21 = ___qtreewidgetitem18->child(2);
        ___qtreewidgetitem21->setText(0, QApplication::translate("PhaseVis", "Z rotation", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem22 = ___qtreewidgetitem17->child(1);
        ___qtreewidgetitem22->setText(0, QApplication::translate("PhaseVis", "Scale", 0, QApplication::UnicodeUTF8));
        treeWidget_2->setSortingEnabled(__sortingEnabled);

        saveScreenshotButton->setText(QApplication::translate("PhaseVis", "Take screenshot", 0, QApplication::UnicodeUTF8));
        dockLayer_Manager->setWindowTitle(QApplication::translate("PhaseVis", "Layers Options", 0, QApplication::UnicodeUTF8));
        drawButton->setText(QApplication::translate("PhaseVis", "Draw", 0, QApplication::UnicodeUTF8));
        removeLayerButton->setText(QApplication::translate("PhaseVis", "Remove from layer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PhaseVis: public Ui_PhaseVis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHASEVIS_H
