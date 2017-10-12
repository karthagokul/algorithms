#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "linearsort.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;

    Array *array=new Array(10);
    BaseSort *s=new LinearSort(array);
    viewer.showExpanded();

    viewer.rootContext()->setContextProperty("arrayStr", array->m_stringRepresentation);
    viewer.rootContext()->setContextProperty("sorter", s);

    viewer.setMainQmlFile(QStringLiteral("qml/SortDemo/main.qml"));


  //  s->print();
  //  s->sort();
  //  s->print();


    return app.exec();
}
