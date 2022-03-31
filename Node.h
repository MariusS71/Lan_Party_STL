#include<iostream>
#include"Match.h"
#include<fstream>
using namespace std;

class Node
{

    Team key;
    Node *left;
    Node *right;
    int height;

public:
    int Height();
    int max(int , int );
    Node* newNode(Team);
    Node* rightRotate(Node *);
    Node* leftRotate(Node *);
    Node* LRRotate(Node*Z);
    Node* RLRotate(Node*Z);
    int getBalance(Node *);
    Node* insert(Node*, Team);

    void printGivenLevel(Node* , int , ostream &);
    void printLevelOrder(Node*, ostream &) ; //afisare arbore intreg
    void delet(Node*&);
};