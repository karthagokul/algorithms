#include <iostream>
#include <list>
using namespace std;

struct HashEntry
{
     string key;
     int value;
};

class HashTable
{
private:
    list<HashEntry*> entries;
    int hashMe(string key)
    {
        return key.size();
    }

public:
    HashTable(int size)
    {
        entries.resize(20);
    }

    void put(string key,int value)
    {
        HashEntry *entry=new HashEntry;
        entry->key=key;
        entry->value=value;
        int position=hashMe(key);
        auto it=entries.begin();
        for(int i=0;i<position;i++) ++it;
        entries.insert(it,entry);
    }
    void print()
    {
        for(auto entry:entries)
            if(entry)
                std::cout<<entry->key<<","<<entry->value<<std::endl;
        std::cout<<std::endl;
    }
};

int main()
{
    HashTable hTable(20);
    hTable.put("On",1);
    hTable.put("Two",2);
    hTable.put("Four",4);
    hTable.print();
    std::cout<<endl;
    return 0;
}

