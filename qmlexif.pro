TEMPLATE = lib
TARGET = QMLExif
QT += qml quick

mac {
    PKG_CONFIG = /usr/local/bin/pkg-config
    QT_CONFIG -= no-pkg-config
}

CONFIG += plugin c++11 link_pkgconfig
PKGCONFIG += libexif

TARGET = $$qtLibraryTarget($$TARGET)
uri = me.wanqingyang.qmlexif

# Input
SOURCES += \
    qmlexif.cpp \
    qmlexif_plugin.cpp

HEADERS += \
    qmlexif.h \
    qmlexif_plugin.h

DISTFILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}
