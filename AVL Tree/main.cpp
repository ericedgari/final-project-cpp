#include <iostream>
#include "avl.h"
using namespace std;

int main(){
    AVLTree myTree;
    while(true){
        cout << "-----------------------" << endl;
        cout << "        AVL TREE       " << endl;
        cout << "-----------------------" << endl;
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Search data" << endl;
        cout << "4. Show data" << endl;
        cout << "5. Exit" << endl;
        cout << "Input >> ";
        int input;
        cin >> input;
        switch(input){
            case 1:
                while(true){
                    int number;
                    cout << "Enter ID: ";
                    cin >> number;
                    cin.clear();
                    if(to_string(number).length() > 9){
                        cout << "ID cannot be longer than 9 integers" << endl;
                        continue;
                    }
                    string name;
                    cout << "Enter name: ";
                    cin.ignore();
                    getline(cin,name);
                    myTree.insert(number,name);
                    break;
                }
                break;
            
            case 2:
                cout << "Enter ID to delete: ";
                int number;
                cin >> number;
                myTree.remove(number);
                break;
            
            case 3:
                cout << "Enter ID to search: ";
                cin >> number;
                if(myTree.search(number) != "NAN"){
                    cout << "The name at the specified ID is " << myTree.search(number) << endl;
                }
                else cout << "Specified ID does not exist!" << endl;
                break;
                  
            case 4:
                myTree.printPreOrder();
                break;
            
            case 5: 
                    exit(0);
            
        }
    }   
    return 0;
}
