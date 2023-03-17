QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += sql
QT += charts

CONFIG += c++11

SOURCES += \
    chart.cpp \
    chart_drawing.cpp \
    data_parser_impl.cpp \
    error.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    chart.h \
    chart_drawing.h \
    data_parser_impl.h \
    error.h \
    i_chart_drawing.h \
    i_data_parser.h \
    ioc_container.h \
    mainwindow.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
