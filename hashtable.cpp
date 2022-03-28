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
        hashtable[i] = nullptr;
    }
}

HashTable::~HashTable(){
    for(int i = 0; i < HASHTABLESIZE; i++){
        if(hashtable[i]){
            delete hashtable[i];
        }
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
    return true;
}

bool HashTable::getData(int id, Data* dataBox){
    return true;
}

bool HashTable::removeEntry(int id){
    return true;
}

int HashTable::getCount(){
    return count;
}

void HashTable::printTable(){

}