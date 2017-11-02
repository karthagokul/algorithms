
# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

#include <iomanip>


using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BST
{
private:
    Node *root=0;

public:
    Node *getRoot() const
    {
        return root;
    }
    BST(int rootData)
    {
        root=new Node();
        root->data=rootData;
        root->left=0;
        root->right=0;
    }
    ~BST()
    {
        if(root)
            delete root;
    }

    Node* insert(Node *node,int value)
    {
        if(node==0)
        {
            Node *n=new Node();
            n->data=value;
            n->left=0;
            n->right=0;
            return n;
        }
        if(node->data<value)
            node->right=insert(node->right,value);
        else
            node->left=insert(node->left,value);
        return node;
    }

    Node* search(Node *node,int value)
    {
        if(node==0||node->data==value)
            return node;
        if(node->data<value)
            return search(node->right,value);
        else
            return search(node->left,value);
    }


    void print()
    {
        postorder(root,0);
    }

    void postorder(Node* p, int indent)
    {
        if(p != NULL) {
            if(p->right) {
                postorder(p->right, indent+4);
            }
            if (indent) {
                std::cout << std::setw(indent) << ' ';
            }
            if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
            std::cout<< p->data << "\n ";
            if(p->left) {
                std::cout << std::setw(indent) << ' ' <<" \\\n";
                postorder(p->left, indent+4);
            }
        }
    }

};

int main()
{
    BST *mytree=new BST(2);
    mytree->insert(mytree->getRoot(),1);
    mytree->insert(mytree->getRoot(),3);
    mytree->insert(mytree->getRoot(),7);
    mytree->insert(mytree->getRoot(),10);
    mytree->insert(mytree->getRoot(),2);
    mytree->insert(mytree->getRoot(),5);
    mytree->insert(mytree->getRoot(),8);
    mytree->insert(mytree->getRoot(),6);
    mytree->insert(mytree->getRoot(),4);

    mytree->print();
   // delete mytree;
    return 0;
}
