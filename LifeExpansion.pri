# версия от релиза из git-а
GIT_VERSION = $$system( git --git-dir $$PWD/.git --work-tree $$PWD describe --always --tags )

# версия сборки - задается вручную
MAJOR = 0
MINOR = 01
VERSION = "$$MAJOR"."$$MINOR"

# глобальные переменные
DEFINES += ORGANIZATION_NAME='\\"CppLessons2023\\"'
DEFINES += ORGANIZATION_DOMAIN='\\"https://github.com/devza300/LifeExpansion\\"'
DEFINES += GIT_VERSION='\\"$$GIT_VERSION\\"'
DEFINES += VERSION='\\"$$VERSION\\"'
DEFINES += PROJECT_NAME='\\"LifeExpansion\\"'

# флаг препроцессора для определения сборки в режиме дебага
CONFIG(debug, debug|release): DEFINES += DEBUG

# переменные для сборки программ
win32: CONFIG(release, debug|release): OUTPWD_MOD = $$OUT_PWD/release
win32: CONFIG(debug, debug|release): OUTPWD_MOD = $$OUT_PWD/debug
unix: OUTPWD_MOD = $$OUT_PWD

# определение архитектуры сборки
!contains(QT_ARCH, x86_64){
    ARCH="i386"
} else {
    ARCH="amd64"
}

# оптимизация сборки
CONFIG(release, debug|release) {
    QMAKE_LFLAGS += -s
    QMAKE_CXXFLAGS += -fpermissive
    QMAKE_CXXFLAGS += -fno-sized-deallocation
    CONFIG += qt release
    CONFIG -= qml_debug
}

# подключение статических библиотек: attachStaticLib(RELATIVE_PATH, NAME)
defineTest(attachStaticLib) {
    RELATIVE_PATH = $$1
    NAME = $$2

    # добавочный путь к библиотекам
    win32: {
        CONFIG(release, debug|release): LIB_APPEND_PATH = release
        CONFIG(debug, debug|release): LIB_APPEND_PATH = debug
    }

    INCLUDEPATH += $$PWD/$$RELATIVE_PATH/$$NAME
    DEPENDPATH += $$PWD/$$RELATIVE_PATH/$$NAME
    LIBS += -L$$OUT_PWD/$$RELATIVE_PATH/$$NAME/$$LIB_APPEND_PATH -l$$NAME
    win32:!win32-g++: PRE_TARGETDEPS += $$OUT_PWD/$$RELATIVE_PATH/$$NAME/$$LIB_APPEND_PATH/$${NAME}.lib
    else: PRE_TARGETDEPS += $$OUT_PWD/$$RELATIVE_PATH/$$NAME/$$LIB_APPEND_PATH/lib$${NAME}.a

    export(INCLUDEPATH)
    export(DEPENDPATH)
    export(LIBS)
    export(PRE_TARGETDEPS)

    return(true)
}
