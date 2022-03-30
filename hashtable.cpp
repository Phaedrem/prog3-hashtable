/*********************
Name: Darren Bowers
Coding 06
Purpose: Creating Hash tables of linked lists
**********************/

#include "hashtable.h"

/*********************************
CONSTRUCTORS / DESTRUCTORS
*********************************/

HashTable::HashTable(){
    count = 0;
    for(int i = 0; i < HASHTABLESIZE; i++){
        hashtable[i] = new LinkedList;
    }
}

HashTable::~HashTable(){
    for(int i = 0; i < HASHTABLESIZE; i++){
        delete hashtable[i];
    }
}

/*********************************
PRIVATE
*********************************/

int HashTable::hash(int id){
    return id % HASHTABLESIZE;
}

/*********************************
PUBLIC
*********************************/


bool HashTable::insertEntry(int id , string* data){
    bool inserted = false;
    if((id > 0) && (*data != "" && id)){
        int position = hash(id);
        if(hashtable[position]->addNode(id, data)){
            count++;
            inserted = true;
        }
    }
    return inserted;
}

bool HashTable::getData(int id, Data* dataBox){
    bool found = false;
    if(id > 0){
        int position = hash(id);
        if(hashtable[position]->getNode(id, dataBox)){
            found = true;
        }
    }else{
        dataBox->id = -1;
        dataBox->data = "";
    }
    return found;
}

bool HashTable::removeEntry(int id){
    bool removed = false;
    if(id > 0){
        int position = hash(id);
        if(hashtable[position]->deleteNode(id)){
            count--;
            removed = true;
        }
    }
    return removed;
}

int HashTable::getCount(){
    return count;
}

void HashTable::printTable(){
    for(int i = 0; i < HASHTABLESIZE; i++){
        cout << "Entry " << i << ": "; 
        hashtable[i]->printList();
        cout << endl;
    }
}