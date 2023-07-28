QT -= gui

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Cells/AbstractCell.cpp \
    Cells/EndOfMap.cpp \
    Cells/Ground.cpp \
    Cells/Home.cpp \
    Cells/Live.cpp \
    LifeCore.cpp \
    Map/GameMap.cpp \
    Map/MapEngine.cpp \
    PlayerInterface.cpp

HEADERS += \
    Cells/AbstractCell.h \
    Cells/CellType.h \
    Cells/EndOfMap.h \
    Cells/Ground.h \
    Cells/Home.h \
    Cells/Live.h \
    LifeCore.h \
    Map/GameMap.h \
    Map/MapEngine.h \
    PlayerInterface.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
