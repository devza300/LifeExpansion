include(../LifeExpansion.pri)

QT += core gui widgets

CONFIG += c++20
CONFIG += lrelease
CONFIG += embed_translations

attachStaticLib(../, lifeCore)

SOURCES += \
        Forms/MainWindow.cpp \
        main.cpp

TRANSLATIONS += \
    translations/client_ru_RU.ts

FORMS += \
    Forms/MainWindow.ui

HEADERS += \
    Forms/DemoMaps.h \
    Forms/MainWindow.h
