#-------------------------------------------------
#
# Project created by QtCreator 2019-08-30T00:01:47
#
#-------------------------------------------------

QT       += core gui
win32{
    QT += winextras
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TemplateQtWidgets
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

TRANSLATIONS += app_ru.ts
RC_FILE = rc.rc
include(Utils/utils.pri)

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

HEADERS += \
        mainwindow.h

SOURCES += \
        main.cpp \
        mainwindow.cpp

FORMS += \
        mainwindow.ui

RESOURCES += res.qrc

#Раздел, в котором указываем директории, в которых хранятся собранные и промежуточные файлы
CONFIG(debug, debug|release) {
    #debug
} else {
    #release - выпуск
    #В режиме выпуска необходимо так же собрать нужные библиотеки рядом с исполнительным файлом

    win32 {
        #Windows x32 and x64

        #Указываем папку, в которую будет помещён исполнительный файл с библиотеками, в зависимости от архитектуры
        contains(QT_ARCH, i386) {
            #Для Windows x32
            DESTDIR = $$_PRO_FILE_PWD_/deploy/windows_x86_32
        } else {
            #Для Windows x64
            DESTDIR = $$_PRO_FILE_PWD_/deploy/windows_x86_64
        }

        #Запуск утилиты "windeployqt", которая собирает нужные dll в папку с исполнительным файлом
        #ToDo: Замечен баг в windeployqt версии Qt 5.12.4 как для x32, так и x64 версии:
        #Не копирует файлы из директории "mingw73_32/qml/Qt/labs/platform", которые нужны, если подключить модуль "Qt.labs.platform" в QML коде.
        #Поэтому эти файлы нужно скопировать вручную. Внимание: файл "qtlabsplatformplugind.dll" (с "d" на конце имени без расширения) не копировать в релизную версию,
        #так как он будет бесполезен и занимать много места
        QMAKE_POST_LINK = $$(QTDIR)/bin/windeployqt --release --qmldir $$(QTDIR)/qml $$DESTDIR
        message("Building will be in \""$$DESTDIR"\"")
    }

    unix {
        message("Building for unix")
        DESTDIR = $$_PRO_FILE_PWD_/deploy/unix#Папка, куда кладётся конечный билд
        #ToDo: реализовать вызов linuxdeployqt
    }
    macx {
        message("Building for macx")
        DESTDIR = $$_PRO_FILE_PWD_/deploy/macx#Папка, куда кладётся конечный билд
        #ToDo: реализовать вызов macdeployqt
    }
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
