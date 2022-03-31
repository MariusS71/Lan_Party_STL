#include <iostream>
#include"Node.h"
#include<string>
using namespace std;

int Node::Height()
{
    if (this == NULL)
        return -1;
    return this->height;
}

int Node::max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

Node* Node::newNode(Team key)
{
//	cout<<"new node 1"<<endl;
    Node* node = new Node;
    node->key= key;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
//	cout<<"new node 1"<<endl; 
    return node;
}


Node* Node::rightRotate(Node *y)
{ // cout<<"test right rotate1"<<endl; 
    Node *x = y->left;
    Node *T2 = x->right;

    // Rotatie  
    x->right = y;
    y->left = T2;

    // Actualizeaza inaltimile  
    y->height = max(y->left->Height(), y->right->Height()) + 1;

    x->height = max(x->left->Height(), x->right->Height()) + 1;
    // cout<<"test right rotate1"<<endl;
    // Returneaza noul node
    return x;
}


Node* Node::leftRotate(Node *x)
{

    Node *y = x->right;
    Node *T2 = y->left;

    // Rotatie  
    y->left = x;
    x->right = T2;

    // Actualizeaza inaltimi  
    x->height = max(x->left->Height(),
                    x->right->Height()) + 1;
    y->height = max(y->left->Height(),
                    y->right->Height()) + 1;
    // cout<<"test leftrotate2"<<endl;

    return y;
}

Node* Node::LRRotate(Node*Z){ //LR  -> rotatie la stanga+rotatie la dreapta  
    Z->left= leftRotate(Z->left);
    return rightRotate(Z);
}

Node* Node::RLRotate(Node*Z){ //RL  rotatie dreapta+stanga 
    Z->right = rightRotate(Z->right);
    return leftRotate(Z);
}



int Node::getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return N->left->Height() - N->right->Height();
}

// Functie recursiva care adauga echipa key in arbore 
Node* Node::insert(Node* node, Team key)
{
    // Adaugare BST normala
    if (node == NULL)
        return(newNode(key));

    if (key.getmedie() < node->key.getmedie())
    {
        node->left = insert(node->left, key);
    }
    else if (key.getmedie() > node->key.getmedie())
    {
        node->right = insert(node->right, key);
    }
    else if(key.getmedie() == node->key.getmedie())
    {

        if(key.getnumeteam() < node->key.getnumeteam())
        {

            node->left = insert(node->left, key);
        }
        else
        {
            node->right = insert(node->right, key);
        }
    }

    //  Actualizare inaltime stramos
    node->height = 1 + max(node->left->Height(), node->right->Height());


    // Echilibreaza stramos si verifica daca nodul introdus nou este neechilibrat
    int balance = getBalance(node);
//	  cout<<"test 8"<<endl; 

    // Daca nodul introdus face ca arborele sa fie neechilibrat sunt 4 cazuri

    // cazul Stanga stanga 
    if (balance > 1 && key.getmedie() < node->left->key.getmedie())
    {
        return rightRotate(node);
    }
    else if(balance > 1 && key.getmedie() ==node->left->key.getmedie())
    {
        return rightRotate(node);
    }
    // cazul Dreapta dreapta  
    if (balance < -1 && key.getmedie() > node->right->key.getmedie())
    {
        return leftRotate(node);
    }
    else if(balance < -1 && key.getmedie() == node->right->key.getmedie())
    {
        return leftRotate(node);
    }

    // cazul stanga dreapta  
    if (balance > 1 && key.getmedie() > node->left->key.getmedie())
    {
        return RLRotate(node);
    }

    // cazul dreapta stanga  
    if (balance < -1 && key.getmedie() < node->right->key.getmedie())
    {
        return LRRotate(node);
    }

    return node;
}


void Node::printGivenLevel(Node* root, int level, ostream & f)
{
    if (root == NULL)
        return;
    if (level == 1)
        f<<root->key.getnumeteam()<<endl;
    else if (level > 1)
    {
        printGivenLevel(root->right, level-1, f);
        printGivenLevel(root->left, level-1, f);
    }
}

void Node::printLevelOrder(Node* root, ostream &f)
{

    int h = root->Height();
    int i;
    cout<<endl;
    for (i=1; i<=h; i++)
    {
        printGivenLevel(root, i, f);
        cout<<endl;
    }
}

void Node::delet(Node*& root)
{
    if (root == NULL) { return; }

    delet(root->left);
    delet(root->right);

    delete root;
    root = NULL;
}