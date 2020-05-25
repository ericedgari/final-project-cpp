#include <iostream>
#include "avl.h"
#include "HashMap.h"
using namespace std;

int main(){
    AVLTree myTree;
    Hash myHash;
    while(true){
        cout << "-----------------------" << endl;
        cout << "        AVL TREE       " << endl;
        cout << "-----------------------" << endl;
        cout << "1. Add data" << endl;
        cout << "2. Delete by ID" << endl;
        cout << "3. Delete by name" << endl;
        cout << "4. Search by ID" << endl;
        cout << "5. Search by name" << endl;
        cout << "6. Show data in ID order" << endl;
        cout << "7. Show data in name order" << endl;
        cout << "8. Exit" << endl;
        cout << "Input >> ";
        int input;
        int result_int;
        string result_string;
        int number;
        string name;
        cin >> input;
        switch(input){
            case 1:
                while(true){
                    cout << "Enter ID: ";
                    cin >> number;
                    cin.clear();
                    if(to_string(number).length() > 9){
                        cout << "ID cannot be longer than 9 integers" << endl;
                        continue;
                    }
                    if(number < 0){
                        cout << "ID cannot be a negative number" << endl;
                    }
                    cout << "Enter name: ";
                    cin.ignore();
                    getline(cin,name);
                    myTree.insert(number,name);
                    myHash.insertItem(name,number);
                    break;
                }
                break;
            
            case 2:
                cout << "Enter ID to delete: ";
                cin >> number;
                result_string = myTree.search(number);
                if(result_string == "NAN"){
                    cout << "ID does not exist" << endl;
                }
                else{
                    myTree.remove(number);
                    myHash.delete_string(result_string);
                }
                break;
            
            case 3:
                cout << "Enter name to delete: ";
                cin >> name;
                result_int = myHash.searchName(name);
                if(result_int == -1){
                    cout << "Name does not exist" << endl;
                }
                else{
                    myHash.delete_string(name);
                    myTree.remove(result_int);
                }
                break;
            case 4:
                cout << "Enter ID to search: ";
                cin >> number;
                if(myTree.search(number) != "NAN"){
                    cout << "The name at the specified ID is " << myTree.search(number) << endl;
                }
                else cout << "Specified ID does not exist!" << endl;
                break;
                  
            case 5:
                cout << "Enter name to search: ";
                cin >> name;
                if(myHash.searchName(name) == -1){
                    cout << "Specified name does not exist!" << endl;
                }
                else{
                    cout << "The ID of the specified name is " << myHash.searchName(name) << endl;
                }
                break;
            case 6:
                myTree.printInOrder();
                break;
            
            case 7:
                myHash.results();
                break;
            case 8: 
                    exit(0);
            
        }
    }   
    return 0;
}