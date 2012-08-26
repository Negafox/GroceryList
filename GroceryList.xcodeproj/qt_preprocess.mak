#############################################################################
# Makefile for building: GroceryList.app/Contents/MacOS/GroceryList
# Generated by qmake (2.01a) (Qt 4.8.2) on: Sun Aug 26 10:35:51 2012
# Project:  GroceryList.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/local/Qt4.8/mkspecs/macx-xcode -o GroceryList.xcodeproj/project.pbxproj GroceryList.pro
#############################################################################

MOC       = /Developer/Tools/Qt/moc
UIC       = /Developer/Tools/Qt/uic
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
INCPATH       = -I/usr/local/Qt4.8/mkspecs/macx-xcode -I. -I/Library/Frameworks/QtCore.framework/Versions/4/Headers -I/usr/include/QtCore -I/Library/Frameworks/QtGui.framework/Versions/4/Headers -I/usr/include/QtGui -I/usr/include -I. -I. -I. -I/usr/local/include -I/System/Library/Frameworks/CarbonCore.framework/Headers -F/Library/Frameworks
DEL_FILE  = rm -f
MOVE      = mv -f

IMAGES = 
PARSERS =
preprocess: $(PARSERS) compilers
clean preprocess_clean: parser_clean compiler_clean

parser_clean:
check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compilers: ./moc_ChecklistView.cpp ./moc_ChecklistViewItem.cpp ./moc_ChecklistViewNewItem.cpp\
	 ./moc_mainwindow.cpp ./qrc_Resources.cpp ./ui_mainwindow.h
compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_ChecklistView.cpp moc_ChecklistViewItem.cpp moc_ChecklistViewNewItem.cpp moc_mainwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_ChecklistView.cpp moc_ChecklistViewItem.cpp moc_ChecklistViewNewItem.cpp moc_mainwindow.cpp
moc_ChecklistView.cpp: ChecklistViewItem.h \
		Checklist.h \
		ChecklistViewNewItem.h \
		ChecklistView.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ ChecklistView.h -o moc_ChecklistView.cpp

moc_ChecklistViewItem.cpp: Checklist.h \
		ChecklistViewItem.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ ChecklistViewItem.h -o moc_ChecklistViewItem.cpp

moc_ChecklistViewNewItem.cpp: Checklist.h \
		ChecklistViewNewItem.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ ChecklistViewNewItem.h -o moc_ChecklistViewNewItem.cpp

moc_mainwindow.cpp: Checklist.h \
		ChecklistViewItem.h \
		ChecklistView.h \
		ChecklistViewNewItem.h \
		mainwindow.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ mainwindow.h -o moc_mainwindow.cpp

compiler_rcc_make_all: qrc_Resources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_Resources.cpp
qrc_Resources.cpp: Resources.qrc
	/Developer/Tools/Qt/rcc -name Resources Resources.qrc -o qrc_Resources.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui
	/Developer/Tools/Qt/uic mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

