#include "array.h"
#include <iostream>
#include <QTime>


Array::Array(int size)
{
    m_stringRepresentation=new QStringListModel(this);
    int high=100;
    int low=0;
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    for(int i=0;i<size;i++)
    {
        add(qrand() % ((high + 1) - low) + low);
    }
}


int& Array::operator[] (const int index)
{
    return m_array[index];
}


void Array::updateString()
{
    //qDebug()<<Q_FUNC_INFO;
    m_stringRepresentation->setStringList(QStringList());
    QStringList strings;
    foreach (int data, m_array) {
        strings<<QString::number(data);
    }
    m_stringRepresentation->setStringList(strings);
    qDebug()<<m_stringRepresentation->stringList();

}

void Array::add(int data)
{
    m_array.append(data);
    updateString();
}

void Array::swap(int i,int j)
{
    int temp=m_array[j];
    m_array[j]=m_array[i];
    m_array[i]=temp;
    updateString();
}
