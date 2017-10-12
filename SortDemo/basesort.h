#ifndef BASESORT_H
#define BASESORT_H

#include <QObject>
#include "array.h"

class BaseSort:public QObject
{
    Q_OBJECT
public:
    BaseSort(Array *mArray);
    Q_INVOKABLE virtual bool sort(){return true;}
    void print();


protected:
    Array *m_array;
};

#endif // BASESORT_H
