#ifndef LINEARSORT_H
#define LINEARSORT_H

#include "basesort.h"

class LinearSort : public BaseSort
{
public:
    LinearSort(Array *aArray):
        BaseSort(aArray)
    {

    }

    bool sort();
};

#endif // LINEARSORT_H
