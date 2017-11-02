#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void add(Node *&rootNode,int data)
{
    Node *n=rootNode;
    while(n->next!=0)
    {
        n=n->next;
    }
    Node *newNode=new Node;
    newNode->data=data;
    n->next=newNode;
    newNode->next=0;
}

void remove(Node *&rootNode,int data)
{
    Node *n=rootNode;
    Node *prevNode=n;
    while(n->next!=0)
    {
        if(n->data==data)
        {
            prevNode->next=n->next;
            delete n;
            n=0;
            break;
        }
        prevNode=n;
        n=n->next;
    }

}

void print(Node *&rootNode)
{
    if(rootNode==NULL)
    {
        std::cout<<"[ Empty ]"<<std::endl;
        return;
    }
    Node *n=rootNode;
    while(n!=NULL)
    {
        std::cout<<n->data<<"->";
        n=n->next;
    }
    std::cout<<"[END]"<<std::endl;
}

void removeAll(Node *&rootNode)
{
    Node *next=rootNode->next;
    Node *temp;
    while(next!=NULL)
    {
        temp=next->next;
        std::cout<<"Deleting " << next->data<<std::endl;
        delete next;
        next=NULL;
        next=temp;
    }

    delete rootNode;
    rootNode=NULL;
    if(rootNode)
        std::cout<<"Shit here as well";
}

/* The logic here is to sendone pointer ahead and the other one normal
 *
 * */
int findMiddleElement(Node *&rootNode)
{
    Node *next=rootNode->next;

    Node *fastMoving=next->next;

    while(fastMoving!=NULL)
    {
       if(fastMoving->next==NULL)
            break;
        fastMoving=fastMoving->next->next;
        next=next->next;
    }
    return next->data;
}

int main()
{
    Node *root=new Node;
    root->data=0;
    root->next=0;

    for(int i=1;i<100;i++)
    {
        add(root,i);
    }
    print(root);

    std::cout<<"MiddleElement data is "<<findMiddleElement(root)<<std::endl;

    return 0;
}

