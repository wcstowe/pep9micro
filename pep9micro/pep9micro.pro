# -------------------------------------------------
# Project created by Matthew McRaven, 12/30/2018
# -------------------------------------------------
TEMPLATE = app
TARGET = Pep9Micro
#Prevent Windows from trying to parse the project three times per build.
CONFIG -= debug_and_release \
    debug_and_release_target
#Flag for enabling C++17 features.
#Due to support for C++17 features being added before the standard was finalized, and the placeholder text of "C++1z" has remained
CONFIG += c++1z
win32{
    #MSVC doesn't recognize c++1z flag, so use the MSVC specific flag here
    win32-msvc*: QMAKE_CXXFLAGS += /std:c++17
    #Flags needed to generate PDB information in release. Necessary information to profile program.
    #Flags also picked to provide a ~15% speed increase in release mode (at the cost of increased compile times).
    QMAKE_LFLAGS_RELEASE +=/MAP
    QMAKE_CFLAGS_RELEASE -= O2
    QMAKE_CFLAGS_RELEASE += /O3 /MD /zi
    QMAKE_LFLAGS_RELEASE +=/debug /opt:ref
}
QT += widgets webenginewidgets printsupport concurrent
# Mac icon/plist
ICON = images/icon.icns
QMAKE_INFO_PLIST = app.plist
QMAKE_MAC_SDK = macosx10.14

#Windows RC file for icon:
RC_FILE = pep9resources.rc

FORMS += \
    addrmodedialog.ui \
    addrmodewidget.ui \
    helpdialog.ui \
    mainwindow.ui \

HEADERS += \
    addrmodedialog.h \
    addrmodewidget.h \
    helpdialog.h \
    mainwindow.h \
    fullmicrocodedcpu.h \
    fullmicrocodedmemoizer.h

SOURCES += \
    addrmodedialog.cpp \
    addrmodewidget.cpp \
    helpdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    fullmicrocodedcpu.cpp \
    fullmicrocodedmemoizer.cpp \

OTHER_FILES += help/images/registeraddresssignals.png \
    help/figures/exer1204.pepcpu \
    help/figures/exer1206.pepcpu \
    help/usingpep9cpu.html \
    help/pep9reference.html \
    help/pep9os.txt \
    help/microcode.html \
    help/exercises.html \
    help/examples.html \
    help/debugging.html \
    help/cpu.html
RESOURCES += \
    ../PepStyles/pepstyles.qrc \
    #../pep9common/dark_style.qrc \
    ../pep9common/pep9common-resources.qrc\
    pep9micro-resources.qrc \
    micro_helpresources.qrc \
    ../pep9cpu/cpu_helpresources.qrc \
    ../pep9cpu/pep9cpu-resources.qrc \
    ../pep9asm/asm_helpresources.qrc \
    ../pep9asm/pep9asm-resources.qrc

DISTFILES += \
    ..\package/package.xml \
    ..\packages/package.xml \
    ..\packages/pep9cpu/meta/package.xml \
    ..\packages/pep9cpu/package.xml \
    ..\packages/pep9cpu/License.txt \
    ..\packages/pep9cpu/control.qs \
    ..\config/configwin32.xml \
    ..\config/configlinux.xml \
    ..\config/control.js \
    ..\packages/pep9cpu/installscript.js \
    ..\rc/License.md \
    ProjectDefs.pri \
    help/osunalignedsymbols.txt \

INCLUDEPATH += $$PWD/../pep9common
INCLUDEPATH += $$PWD/../pep9asm
INCLUDEPATH += $$PWD/../pep9cpu

#Include own directory in VPATH, otherwise qmake might accidentally import files with
#the same name from other directories.
VPATH += $$PWD
VPATH += $$PWD/../pep9common
VPATH += $$PWD/../pep9asm
VPATH += $$PWD/../pep9cpu
include(../pep9common/pep9common.pro)
include(../pep9asm/pep9asm-common.pro)
include(../pep9cpu/pep9cpu-common.pro)
#Add this include to the bottom of your project to enable automated installer creation
#Include the definitions file that sets all variables needed for the InstallerConfig Script
#include("ProjectDefs.pri")

#Lastly, include and run the installer config script
#include("Installer/InstallerConfig.pri")



