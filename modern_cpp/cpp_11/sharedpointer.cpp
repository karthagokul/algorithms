#include <iostream>
#include <memory>

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

class SharedFactory
{
public:
    std::shared_ptr<SharedResource> get()
    {
        std::shared_ptr<SharedResource> sharedLocalPointer(new SharedResource());
        return sharedLocalPointer;
    }


};

class ResourceMan
{
public:
    ResourceMan()
    {
        SharedFactory f;
        localResource=f.get();
        localResource->run();
        std::cout<<localResource.use_count()<< " Is the Reference Count"<<std::endl; //Print 2
    }

private:
    std::shared_ptr<SharedResource> localResource;

};

int main()
{
   ResourceMan r;
    return 0;
}

