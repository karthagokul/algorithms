
# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
#include <random>
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
        deleteNode(root);
    }

    Node * deleteNode(Node *node)
    {
        if(node==0)
        {
            return 0;
        }
        //std::cout<<std::endl<<"Deleting "<<node->data;
        Node *left=node->left;
        Node *right=node->right;
        if(left!=0)
        {
            deleteNode(left);
        }
        if(right!=0)
        {
            deleteNode(right);
        }
        delete node;
        node=0;
        return 0;
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
                postorder(p->right, indent+2);
            }
            if (indent) {
                std::cout << std::setw(indent) << ' ';
            }
            if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
            std::cout<< p->data << "\n ";
            if(p->left) {
                std::cout << std::setw(indent) << ' ' <<" \\\n";
                postorder(p->left, indent+2);
            }
        }
    }

};

int main()
{
    //generating Random Number
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(2.0, 20.0);

    BST *mytree=new BST(1);
    for(int i=0;i<5;i++)
    {
        mytree->insert(mytree->getRoot(),dist(mt) );
    }

    mytree->print();

    delete mytree;
    std::cout<<std::endl;
    return 0;
}
