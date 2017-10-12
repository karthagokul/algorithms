#ifndef ARRAY_H
#define ARRAY_H

#include <QList>
#include <QObject>
#include <QStringListModel>
#include <QDebug>

class Array:public QObject
{
    Q_OBJECT
public:
    Array(int size);
signals:
    void itemUpdated();

private:
    QList<int> m_array;

public:
    QStringListModel *m_stringRepresentation;
    int& operator[] (const int index);
    void updateString();
    void add(int data);
    void swap(int i,int j);
    int count()
    {
        m_array.count();
    }
    int at(int index)
    {
        return m_array[index];
    }
};

#endif // ARRAY_H
