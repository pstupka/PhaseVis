#############################################################################
# Makefile for building: dist/Release/GNU-Linux-x86/PhaseVis
# Generated by qmake (2.01a) (Qt 4.8.4) on: niedz. mar 16 19:49:34 2014
# Project:  nbproject/qt-Release.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake VPATH=. -o qttmp-Release.mk nbproject/qt-Release.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -std=c++11 -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -Inbproject -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4 -Isrc -Isrc/Display -Isrc/Geometry -Isrc/GUI -Isrc/Model -Isrc/Model/Methods -Isrc/Model/Tree\ Model -I/usr/include/libdrm -I/usr/X11R6/include -Imoc -Iui -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -L/usr/X11R6/lib64 -lGLU -lQtOpenGL -lQtGui -lQtCore -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/Release/GNU-Linux-x86/

####### Files

SOURCES       = src/Display/glwidget.cpp \
		src/GUI/MethodChooseDialog.cpp \
		src/GUI/PhaseVis.cpp \
		src/Geometry/GlGlyph.cpp \
		src/Geometry/Grid.cpp \
		src/Geometry/Primitives.cpp \
		src/Model/MethodCreator.cpp \
		src/Model/Methods/ColorMapper.cpp \
		src/Model/Methods/DyeTracking.cpp \
		src/Model/Methods/F.cpp \
		src/Model/Methods/GenerateAndronovHopf.cpp \
		src/Model/Methods/GenerateMorrisLecar.cpp \
		src/Model/Methods/GenerateVanDerPol.cpp \
		src/Model/Methods/GenerateVanDerPolDuffing.cpp \
		src/Model/Methods/Glyphs.cpp \
		src/Model/Methods/GridImporter.cpp \
		src/Model/Methods/Isochron.cpp \
		src/Model/Methods/LineIntegralConvolution.cpp \
		src/Model/Methods/Streamline.cpp \
		src/Model/Tree\ Model/LayerManager.cpp \
		src/Model/Tree\ Model/OptionModel.cpp \
		src/Model/Tree\ Model/TreeItem.cpp \
		src/Model/Tree\ Model/TreeModel.cpp \
		src/main.cpp moc/moc_glwidget.cpp \
		moc/moc_MethodChooseDialog.cpp \
		moc/moc_PhaseVis.cpp \
		moc/moc_LayerManager.cpp \
		moc/moc_OptionModel.cpp \
		moc/moc_TreeModel.cpp
OBJECTS       = build/Release/GNU-Linux-x86/glwidget.o \
		build/Release/GNU-Linux-x86/MethodChooseDialog.o \
		build/Release/GNU-Linux-x86/PhaseVis.o \
		build/Release/GNU-Linux-x86/GlGlyph.o \
		build/Release/GNU-Linux-x86/Grid.o \
		build/Release/GNU-Linux-x86/Primitives.o \
		build/Release/GNU-Linux-x86/MethodCreator.o \
		build/Release/GNU-Linux-x86/ColorMapper.o \
		build/Release/GNU-Linux-x86/DyeTracking.o \
		build/Release/GNU-Linux-x86/F.o \
		build/Release/GNU-Linux-x86/GenerateAndronovHopf.o \
		build/Release/GNU-Linux-x86/GenerateMorrisLecar.o \
		build/Release/GNU-Linux-x86/GenerateVanDerPol.o \
		build/Release/GNU-Linux-x86/GenerateVanDerPolDuffing.o \
		build/Release/GNU-Linux-x86/Glyphs.o \
		build/Release/GNU-Linux-x86/GridImporter.o \
		build/Release/GNU-Linux-x86/Isochron.o \
		build/Release/GNU-Linux-x86/LineIntegralConvolution.o \
		build/Release/GNU-Linux-x86/Streamline.o \
		build/Release/GNU-Linux-x86/LayerManager.o \
		build/Release/GNU-Linux-x86/OptionModel.o \
		build/Release/GNU-Linux-x86/TreeItem.o \
		build/Release/GNU-Linux-x86/TreeModel.o \
		build/Release/GNU-Linux-x86/main.o \
		build/Release/GNU-Linux-x86/moc_glwidget.o \
		build/Release/GNU-Linux-x86/moc_MethodChooseDialog.o \
		build/Release/GNU-Linux-x86/moc_PhaseVis.o \
		build/Release/GNU-Linux-x86/moc_LayerManager.o \
		build/Release/GNU-Linux-x86/moc_OptionModel.o \
		build/Release/GNU-Linux-x86/moc_TreeModel.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/link_pkgconfig.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		nbproject/qt-Release.pro
QMAKE_TARGET  = PhaseVis
DESTDIR       = dist/Release/GNU-Linux-x86/
TARGET        = dist/Release/GNU-Linux-x86/PhaseVis

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: qttmp-Release.mk $(TARGET)

$(TARGET): ui/ui_MethodChooseDialog.h ui/ui_PhaseVis.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) dist/Release/GNU-Linux-x86/ || $(MKDIR) dist/Release/GNU-Linux-x86/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

qttmp-Release.mk: nbproject/qt-Release.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/link_pkgconfig.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/x86_64-linux-gnu/libQtOpenGL.prl \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) VPATH=. -o qttmp-Release.mk nbproject/qt-Release.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/link_pkgconfig.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/opengl.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/x86_64-linux-gnu/libQtOpenGL.prl:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) VPATH=. -o qttmp-Release.mk nbproject/qt-Release.pro

dist: 
	@$(CHK_DIR_EXISTS) build/Release/GNU-Linux-x86/PhaseVis1.0.0 || $(MKDIR) build/Release/GNU-Linux-x86/PhaseVis1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/Release/GNU-Linux-x86/PhaseVis1.0.0/ && $(COPY_FILE) --parents src/Defines.h src/Display/glwidget.h src/GUI/MethodChooseDialog.h src/GUI/PhaseVis.h src/Geometry/GlGlyph.h src/Geometry/Grid.h src/Geometry/Primitives.h src/Model/MethodCreator.h src/Model/Methods/ColorMapper.h src/Model/Methods/DyeTracking.h src/Model/Methods/F.h src/Model/Methods/GenerateAndronovHopf.h src/Model/Methods/GenerateMorrisLecar.h src/Model/Methods/GenerateVanDerPol.h src/Model/Methods/GenerateVanDerPolDuffing.h src/Model/Methods/Glyphs.h src/Model/Methods/GridImporter.h src/Model/Methods/Isochron.h src/Model/Methods/LineIntegralConvolution.h src/Model/Methods/Streamline.h src/Model/Tree Model/LayerManager.h src/Model/Tree Model/OptionModel.h src/Model/Tree Model/TreeItem.h src/Model/Tree Model/TreeModel.h build/Release/GNU-Linux-x86/PhaseVis1.0.0/ && $(COPY_FILE) --parents src/Display/glwidget.cpp src/GUI/MethodChooseDialog.cpp src/GUI/PhaseVis.cpp src/Geometry/GlGlyph.cpp src/Geometry/Grid.cpp src/Geometry/Primitives.cpp src/Model/MethodCreator.cpp src/Model/Methods/ColorMapper.cpp src/Model/Methods/DyeTracking.cpp src/Model/Methods/F.cpp src/Model/Methods/GenerateAndronovHopf.cpp src/Model/Methods/GenerateMorrisLecar.cpp src/Model/Methods/GenerateVanDerPol.cpp src/Model/Methods/GenerateVanDerPolDuffing.cpp src/Model/Methods/Glyphs.cpp src/Model/Methods/GridImporter.cpp src/Model/Methods/Isochron.cpp src/Model/Methods/LineIntegralConvolution.cpp src/Model/Methods/Streamline.cpp src/Model/Tree Model/LayerManager.cpp src/Model/Tree Model/OptionModel.cpp src/Model/Tree Model/TreeItem.cpp src/Model/Tree Model/TreeModel.cpp src/main.cpp build/Release/GNU-Linux-x86/PhaseVis1.0.0/ && $(COPY_FILE) --parents src/GUI/MethodChooseDialog.ui src/GUI/PhaseVis.ui build/Release/GNU-Linux-x86/PhaseVis1.0.0/ && (cd `dirname build/Release/GNU-Linux-x86/PhaseVis1.0.0` && $(TAR) PhaseVis1.0.0.tar PhaseVis1.0.0 && $(COMPRESS) PhaseVis1.0.0.tar) && $(MOVE) `dirname build/Release/GNU-Linux-x86/PhaseVis1.0.0`/PhaseVis1.0.0.tar.gz . && $(DEL_FILE) -r build/Release/GNU-Linux-x86/PhaseVis1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) qttmp-Release.mk


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc/moc_glwidget.cpp moc/moc_MethodChooseDialog.cpp moc/moc_PhaseVis.cpp moc/moc_LayerManager.cpp moc/moc_OptionModel.cpp moc/moc_TreeModel.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc/moc_glwidget.cpp moc/moc_MethodChooseDialog.cpp moc/moc_PhaseVis.cpp moc/moc_LayerManager.cpp moc/moc_OptionModel.cpp moc/moc_TreeModel.cpp
moc/moc_glwidget.cpp: src/Display/glwidget.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/Display/glwidget.h -o moc/moc_glwidget.cpp

moc/moc_MethodChooseDialog.cpp: ui/ui_MethodChooseDialog.h \
		src/GUI/MethodChooseDialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/GUI/MethodChooseDialog.h -o moc/moc_MethodChooseDialog.cpp

moc/moc_PhaseVis.cpp: ui/ui_PhaseVis.h \
		src/GUI/PhaseVis.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/GUI/PhaseVis.h -o moc/moc_PhaseVis.cpp

moc/moc_LayerManager.cpp: src/Model/Tree\ Model/LayerManager.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/Model/Tree\ Model/LayerManager.h -o moc/moc_LayerManager.cpp

moc/moc_OptionModel.cpp: src/Model/Tree\ Model/OptionModel.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/Model/Tree\ Model/OptionModel.h -o moc/moc_OptionModel.cpp

moc/moc_TreeModel.cpp: src/Model/Tree\ Model/TreeItem.h \
		src/Model/Tree\ Model/OptionModel.h \
		src/Model/Tree\ Model/TreeModel.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/Model/Tree\ Model/TreeModel.h -o moc/moc_TreeModel.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: ui/qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) ui/qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui/ui_MethodChooseDialog.h ui/ui_PhaseVis.h
compiler_uic_clean:
	-$(DEL_FILE) ui/ui_MethodChooseDialog.h ui/ui_PhaseVis.h
ui/ui_MethodChooseDialog.h: src/GUI/MethodChooseDialog.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic src/GUI/MethodChooseDialog.ui -o ui/ui_MethodChooseDialog.h

ui/ui_PhaseVis.h: src/GUI/PhaseVis.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic src/GUI/PhaseVis.ui -o ui/ui_PhaseVis.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

build/Release/GNU-Linux-x86/glwidget.o: src/Display/glwidget.cpp src/Display/glwidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/glwidget.o src/Display/glwidget.cpp

build/Release/GNU-Linux-x86/MethodChooseDialog.o: src/GUI/MethodChooseDialog.cpp src/GUI/MethodChooseDialog.h \
		ui/ui_MethodChooseDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/MethodChooseDialog.o src/GUI/MethodChooseDialog.cpp

build/Release/GNU-Linux-x86/PhaseVis.o: src/GUI/PhaseVis.cpp ui/ui_PhaseVis.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/PhaseVis.o src/GUI/PhaseVis.cpp

build/Release/GNU-Linux-x86/GlGlyph.o: src/Geometry/GlGlyph.cpp src/Geometry/GlGlyph.h \
		src/Geometry/Primitives.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/GlGlyph.o src/Geometry/GlGlyph.cpp

build/Release/GNU-Linux-x86/Grid.o: src/Geometry/Grid.cpp src/Geometry/Grid.h \
		src/Geometry/Primitives.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/Grid.o src/Geometry/Grid.cpp

build/Release/GNU-Linux-x86/Primitives.o: src/Geometry/Primitives.cpp src/Geometry/Primitives.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/Primitives.o src/Geometry/Primitives.cpp

build/Release/GNU-Linux-x86/MethodCreator.o: src/Model/MethodCreator.cpp src/Model/MethodCreator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/MethodCreator.o src/Model/MethodCreator.cpp

build/Release/GNU-Linux-x86/ColorMapper.o: src/Model/Methods/ColorMapper.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/ColorMapper.o src/Model/Methods/ColorMapper.cpp

build/Release/GNU-Linux-x86/DyeTracking.o: src/Model/Methods/DyeTracking.cpp src/Model/Methods/DyeTracking.h \
		src/Model/Methods/F.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/DyeTracking.o src/Model/Methods/DyeTracking.cpp

build/Release/GNU-Linux-x86/F.o: src/Model/Methods/F.cpp src/Model/Methods/F.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/F.o src/Model/Methods/F.cpp

build/Release/GNU-Linux-x86/GenerateAndronovHopf.o: src/Model/Methods/GenerateAndronovHopf.cpp src/Model/Methods/GenerateAndronovHopf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/GenerateAndronovHopf.o src/Model/Methods/GenerateAndronovHopf.cpp

build/Release/GNU-Linux-x86/GenerateMorrisLecar.o: src/Model/Methods/GenerateMorrisLecar.cpp src/Model/Methods/GenerateMorrisLecar.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/GenerateMorrisLecar.o src/Model/Methods/GenerateMorrisLecar.cpp

build/Release/GNU-Linux-x86/GenerateVanDerPol.o: src/Model/Methods/GenerateVanDerPol.cpp src/Model/Methods/GenerateVanDerPol.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/GenerateVanDerPol.o src/Model/Methods/GenerateVanDerPol.cpp

build/Release/GNU-Linux-x86/GenerateVanDerPolDuffing.o: src/Model/Methods/GenerateVanDerPolDuffing.cpp src/Model/Methods/GenerateVanDerPolDuffing.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/GenerateVanDerPolDuffing.o src/Model/Methods/GenerateVanDerPolDuffing.cpp

build/Release/GNU-Linux-x86/Glyphs.o: src/Model/Methods/Glyphs.cpp src/Model/Methods/Glyphs.h \
		src/Model/Methods/F.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/Glyphs.o src/Model/Methods/Glyphs.cpp

build/Release/GNU-Linux-x86/GridImporter.o: src/Model/Methods/GridImporter.cpp src/Model/Methods/GridImporter.h \
		src/Model/Methods/F.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/GridImporter.o src/Model/Methods/GridImporter.cpp

build/Release/GNU-Linux-x86/Isochron.o: src/Model/Methods/Isochron.cpp src/Model/Methods/Isochron.h \
		src/Model/Methods/F.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/Isochron.o src/Model/Methods/Isochron.cpp

build/Release/GNU-Linux-x86/LineIntegralConvolution.o: src/Model/Methods/LineIntegralConvolution.cpp src/Model/Methods/LineIntegralConvolution.h \
		src/Model/Methods/F.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/LineIntegralConvolution.o src/Model/Methods/LineIntegralConvolution.cpp

build/Release/GNU-Linux-x86/Streamline.o: src/Model/Methods/Streamline.cpp src/Model/Methods/Streamline.h \
		src/Model/Methods/F.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/Streamline.o src/Model/Methods/Streamline.cpp

build/Release/GNU-Linux-x86/LayerManager.o: src/Model/Tree\ Model/LayerManager.cpp src/Model/Tree\ Model/LayerManager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/LayerManager.o src/Model/Tree\ Model/LayerManager.cpp

build/Release/GNU-Linux-x86/OptionModel.o: src/Model/Tree\ Model/OptionModel.cpp src/Model/Tree\ Model/OptionModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/OptionModel.o src/Model/Tree\ Model/OptionModel.cpp

build/Release/GNU-Linux-x86/TreeItem.o: src/Model/Tree\ Model/TreeItem.cpp src/Model/Tree\ Model/TreeItem.h \
		src/Model/Tree\ Model/OptionModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/TreeItem.o src/Model/Tree\ Model/TreeItem.cpp

build/Release/GNU-Linux-x86/TreeModel.o: src/Model/Tree\ Model/TreeModel.cpp src/Model/Tree\ Model/TreeModel.h \
		src/Model/Tree\ Model/TreeItem.h \
		src/Model/Tree\ Model/OptionModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/TreeModel.o src/Model/Tree\ Model/TreeModel.cpp

build/Release/GNU-Linux-x86/main.o: src/main.cpp src/GUI/PhaseVis.h \
		ui/ui_PhaseVis.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/main.o src/main.cpp

build/Release/GNU-Linux-x86/moc_glwidget.o: moc/moc_glwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/moc_glwidget.o moc/moc_glwidget.cpp

build/Release/GNU-Linux-x86/moc_MethodChooseDialog.o: moc/moc_MethodChooseDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/moc_MethodChooseDialog.o moc/moc_MethodChooseDialog.cpp

build/Release/GNU-Linux-x86/moc_PhaseVis.o: moc/moc_PhaseVis.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/moc_PhaseVis.o moc/moc_PhaseVis.cpp

build/Release/GNU-Linux-x86/moc_LayerManager.o: moc/moc_LayerManager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/moc_LayerManager.o moc/moc_LayerManager.cpp

build/Release/GNU-Linux-x86/moc_OptionModel.o: moc/moc_OptionModel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/moc_OptionModel.o moc/moc_OptionModel.cpp

build/Release/GNU-Linux-x86/moc_TreeModel.o: moc/moc_TreeModel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Release/GNU-Linux-x86/moc_TreeModel.o moc/moc_TreeModel.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
