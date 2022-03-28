/*********************
Name: Darren Bowers
Coding 06
Purpose: Creating Hash tables of linked lists
**********************/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include "linkedlist.h"

#define HASHTABLESIZE 15

using std::cout;
using std::endl;

class HashTable {

public:
    HashTable();
    ~HashTable();
    bool insertEntry(int, string*);
    bool getData(int, Data*);
    bool removeEntry(int);
    int getCount();
    void printTable();

private:
    int hash(int);

    Data *hashtable[HASHTABLESIZE];
    int count; 


};



#endif //HASH_TABLE_H