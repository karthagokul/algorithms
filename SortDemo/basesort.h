#ifndef BASESORT_H
#define BASESORT_H



class BaseSort
{
public:
    BaseSort();
    virtual bool sort(){};
    void print();

protected:
    const int count=10;
    static int array[];
};

#endif // BASESORT_H
