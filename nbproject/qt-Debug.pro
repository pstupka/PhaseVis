# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = PhaseVis
VERSION = 1.0-rc1
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += link_pkgconfig debug 
PKGCONFIG += glu glproto
QT = core gui opengl
SOURCES += src/Display/glwidget.cpp src/GUI/MethodChooseDialog.cpp src/GUI/PhaseVis.cpp src/Geometry/GlGlyph.cpp src/Geometry/Grid.cpp src/Geometry/Primitives.cpp src/Model/MethodCreator.cpp src/Model/Methods/ColorMapper.cpp src/Model/Methods/DyeTracking.cpp src/Model/Methods/F.cpp src/Model/Methods/GenerateAndronovHopf.cpp src/Model/Methods/GenerateMorrisLecar.cpp src/Model/Methods/GenerateVanDerPol.cpp src/Model/Methods/GenerateVanDerPolDuffing.cpp src/Model/Methods/Glyphs.cpp src/Model/Methods/GridImporter.cpp src/Model/Methods/Isochron.cpp src/Model/Methods/LineIntegralConvolution.cpp src/Model/Methods/Streamline.cpp "src/Model/Tree Model/LayerManager.cpp" "src/Model/Tree Model/OptionModel.cpp" "src/Model/Tree Model/TreeItem.cpp" "src/Model/Tree Model/TreeModel.cpp" src/main.cpp
HEADERS += src/Defines.h src/Display/glwidget.h src/GUI/MethodChooseDialog.h src/GUI/PhaseVis.h src/Geometry/GlGlyph.h src/Geometry/Grid.h src/Geometry/Primitives.h src/Model/MethodCreator.h src/Model/Methods/ColorMapper.h src/Model/Methods/DyeTracking.h src/Model/Methods/F.h src/Model/Methods/GenerateAndronovHopf.h src/Model/Methods/GenerateMorrisLecar.h src/Model/Methods/GenerateVanDerPol.h src/Model/Methods/GenerateVanDerPolDuffing.h src/Model/Methods/Glyphs.h src/Model/Methods/GridImporter.h src/Model/Methods/Isochron.h src/Model/Methods/LineIntegralConvolution.h src/Model/Methods/Streamline.h "src/Model/Tree Model/LayerManager.h" "src/Model/Tree Model/OptionModel.h" "src/Model/Tree Model/TreeItem.h" "src/Model/Tree Model/TreeModel.h"
FORMS += src/GUI/MethodChooseDialog.ui src/GUI/PhaseVis.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = moc
RCC_DIR = rcc
UI_DIR = ui
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
