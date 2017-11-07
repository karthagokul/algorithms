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
        size_t h(0);
        for (int i=0; i<key.length(); i++)
           h = (h << 6) ^ (h >> 26) ^ key[i];
        return h;
    }

public:
    HashTable()
    {
    }

    void put(string key,int value)
    {
        HashEntry *entry=new HashEntry;
        entry->key=key;
        entry->value=value;
        int position=hashMe(key);
        std::cout<<key<<" , Position is "<<position<<std::endl;
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
    HashTable hTable;
    hTable.put("On",1);
    hTable.put("Two",2);
    hTable.put("Four",4);
    hTable.print();
    std::cout<<endl;
    return 0;
}

