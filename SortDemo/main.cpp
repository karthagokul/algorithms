#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"

#include "linearsort.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/SortDemo/main.qml"));
    viewer.showExpanded();

    BaseSort *s=new LinearSort();
    s->print();
    s->sort();
    s->print();

    return app.exec();
}
