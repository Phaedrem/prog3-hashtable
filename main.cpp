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

    /***********************************************************************
     * Now you have two parallel arrays with ids and strings for test data.*
     * START HERE and create your hash table and use the test data to show *
     * it works.                                                           *
     **********************************************************************/
    
    //temporary data holder and tempID for testing and creating empty table 
    Data tempData;
    int testId;
    //setting tempData info to verify it changes after an attempt to getData
    tempData.id = 9999;
    tempData.data = "nothing";
    

    cout << "Creating Hashtable" << endl << endl;
    HashTable table;

    
    cout << "Printing current count and entire table " << endl << endl;
    cout << "Current count is " << table.getCount() << endl;
    table.printTable();
    cout << endl;

    cout << "Attempting to put all test data into table" << endl << endl;
    for(int i = 0; i < testdatasize; i++){
        if(table.insertEntry(ids[i], &strs[i])){
            cout << "Inserted " << ids[i] << ": " << strs[i] << " successfully" << endl;
        }else{
            cout << "Failed to insert " << ids[i] << ": " << strs[i] << endl;
        }
    }

    cout << endl << "Printing current count and entire table " << endl << endl;
    cout << "Current count is " << table.getCount() << endl;
    table.printTable();

    cout << endl << "Grabbing a few random testdata ids" << endl << endl;
    for(int i = 0; i < 5; i++){
        int testId = ids[rand() % testdatasize];
        cout << "Attempting to grab data for id " << testId << endl;
        if(table.getData(testId, &tempData)){
            cout << "getData succesful" << endl;
            cout <<"id " << tempData.id << " has " << tempData.data << " in it." << endl << endl;
        }else{
            cout << "getData failed" << endl;
            cout << "tempData now has an id of " << tempData.id << " and a data of '" << tempData.data << "'" << endl << endl;
        }
    }

    //Printing count and whole table to show no changes
    cout << "The current count is " << table.getCount() << endl;
    table.printTable();

    cout << endl << "Attemping to remove a few random ids" << endl;
    for(int i = 0; i < 5; i++){
        testId = ids[rand() % testdatasize];
        cout << endl << "Attemping to remove entry " << testId << endl;
        if(table.removeEntry(testId)){
            cout << "Removed" << endl;
        }else{
            cout << "failed to removed" << endl;
        }
    }
    
    cout << endl << "attempting to use getData to find removed id " << testId << endl;
    if(table.getData(testId, &tempData)){
        cout << "getData succesful" << endl;
        cout << endl <<"id " << tempData.id << " has " << tempData.data << " in it." << endl << endl;
    }else{
        cout << "getData failed" << endl;
        cout << "tempData now has an id of " << tempData.id << " and a data of '" << tempData.data << "'" << endl << endl;
    }

    //Printing count and whole table to show changes
    cout << endl <<"The current count is " << table.getCount() << endl;
    table.printTable();

    //Trying to remove an id that isn't in the list
    cout << endl << "Attemping to remove nonexisting entry 8888" << endl;
    
    if(table.removeEntry(8888)){
        cout << "Removed" << endl;
    }else{
        cout << "failed to removed" << endl;
    }

    //Printing count and whole table to show changes
    cout << endl << "The current count is " << table.getCount() << endl;
    table.printTable();

    //Trying to remove an id that is out of range
    cout << endl << "Attemping to removing entry out of acceptable range -1" << endl;
    
    if(table.removeEntry(-1)){
        cout << "Removed" << endl;
    }else{
        cout << "failed to removed" << endl;
    }

    //Printing count and whole table to show changes
    cout << endl << "The current count is " << table.getCount() << endl;
    table.printTable();


    cout << endl << "Attempting to remove all test data, including duplicate and out of range" << endl << endl;
    for(int i = 0; i < testdatasize; i++){
        if(table.removeEntry(ids[i])){
            cout << "id " << ids[i] << " removed" << endl;
        }else{
            cout << "id " << ids[i] << " failed to remove" << endl;
        }
    }
    
    cout << endl << "The current count is " << table.getCount() << endl;
    table.printTable();
    cout << endl << endl;

    cout << endl << "======================================================================" << endl;
    cout << "Random Test" << endl;
    cout << "======================================================================" << endl << endl;


    int choice = rand() % CHOICES + 1;
    for(int i = 0; i < HASHTABLESIZE*RANDOM_MULTIPLIER; i++){
        switch (choice){
            case 1:
            case 2:
                testId = rand() % testdatasize; 
                if(table.insertEntry(ids[testId], &strs[testId])){
                    cout << "Succesfully inserted " << ids[testId] << ": " << strs[testId] << endl;
                }else{
                    cout << "Failed to insert " << testId <<endl;
                }
                break;
            case 3:
            case 4:
                testId = ids[rand() % testdatasize];
                if(table.removeEntry(testId)){
                    cout << "Removed " << testId << endl;
                }else{
                    cout << "Failed to remove " << testId << endl;
                }
                break;
            case 5:
                testId = ids[rand() % testdatasize];
                if(table.getData(testId, &tempData)){
                    cout << "getting id " << testId << ": " << tempData.data << endl;
                }else{
                    cout << "Failed to get id " << testId <<endl;
                }
                break;
            case 6:
                cout << "Current count is " << table.getCount() << endl;
                break;
        }
        choice = rand() % CHOICES +1;
    }

    cout << endl << "The current count is " << table.getCount() << endl;
    table.printTable();
    cout << endl << endl;

    
    return 0;
}
