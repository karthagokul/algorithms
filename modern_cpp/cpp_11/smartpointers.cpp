#include <iostream>
#include <memory>
//Smart Pointers in C++

class UniqueResource
{
public:
    UniqueResource()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }

    ~UniqueResource()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
};

class SharedResource
{
public:
    SharedResource()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }

    void run()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;

    }
    ~SharedResource()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
};

int main()
{
    {
        std::unique_ptr<UniqueResource> uniqueLocalPointer(new UniqueResource());
        //std::unique_ptr<UniqueResource> uniqueLocalPointerCopy=uniqueLocalPointer; //Can not copy Unique pointer, compilation failure
    }
    std::shared_ptr<SharedResource> sharedLocalPointerCopy;
    {
        std::shared_ptr<SharedResource> sharedLocalPointer(new SharedResource());
        std::cout<<sharedLocalPointer.use_count()<< " Is the Reference Count"<<std::endl; //Print 1
        sharedLocalPointerCopy=sharedLocalPointer;
        std::cout<<sharedLocalPointer.use_count()<< " Is the Reference Count"<<std::endl; //Print 2
        {
            std::shared_ptr<SharedResource> sharedLocalPointerCopyTwo;
            sharedLocalPointerCopyTwo=sharedLocalPointer;
            std::cout<<sharedLocalPointer.use_count()<< " Is the Reference Count"<<std::endl; //Print 3
        }
    }
    std::cout<<sharedLocalPointerCopy.use_count()<< " Is the Reference Count"<<std::endl; //Print 1
    sharedLocalPointerCopy->run(); //sharedLocalPointer went out of scope, but the Object Remains until the last reffered object goes out of scope , Super Ah?
    //Shared Pointer and Array Problem , till C++17 there was no option to delete []
    {
        //std::shared_ptr<SharedResource> sharedIntPtr(new SharedResource[2]());
    }
    return 0;
}

