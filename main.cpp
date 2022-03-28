/*********************
Name: Darren Bowers
Coding 06
Purpose: Creating Hash tables of linked lists
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    //making temporary data holder for testing
    Data tempData;

    //Creating empty hash table
    HashTable table;

    //Printing count and contents of new table
    cout << "The current count is " << table.getCount() << endl;
    table.printTable();
    cout << endl << endl;

    //Putting all data into table
    for(int i = 0; i < testdatasize; i++){
        table.insertEntry(ids[i], &strs[i]);
    }

    //Printing table after contents added
    cout << "The current count is " << table.getCount() << endl;
    table.printTable();

    //Grabbing a random id from test data
    int testId = ids[rand() % testdatasize];

    //setting tempData info to verify it changes after an attempt to getData
    tempData.id = 9999;
    tempData.data = "nothing";

    //Grabbing data 
    table.getData(testId, &tempData);

    //Printing results
    cout << endl <<"id " << tempData.id << " has " << tempData.data << " in it." << endl;

    // create your hash table object here
    
    // show it is empty by calling getCount and printTable
    
    // try and put ALL the test data into the table and show what happens

    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    
    
    
    
    return 0;
}
