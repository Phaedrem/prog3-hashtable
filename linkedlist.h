/*********************
Name: Darren Bowers
Coding 06
Purpose: Creating Hash tables of linked lists
**********************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "data.h" 

#define COUNTSTART 0
#define PRINTSTART 1

using std::cout;
using std::endl;

class LinkedList {

public:
    LinkedList();
    ~LinkedList();
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);


private:
    Node *head;

    void fillNode(int, string*, Node**);
    void addHead(int, string*, Node*, Node*);
    void addTail(int, string*, Node*, Node*);
    void addMiddle(int, string*, Node*, Node*);
    void findId(int, Node**);





};

#endif //LINKED_LIST_H