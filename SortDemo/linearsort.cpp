#include "linearsort.h"


bool LinearSort::sort()
{
    qDebug()<<"Sorting";
    for(int i=0;i<m_array->count();i++)
    {
        for(int j=i;j<m_array->count();j++)
        {
            if(m_array->at(j)>m_array->at(i))
            {
               m_array->swap(i,j);
            }
        }
    }
    return true;
}
