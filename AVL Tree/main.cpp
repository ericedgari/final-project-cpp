#include <iostream>
#include "avl.h"
using namespace std;

int main(){
    AVLTree myTree;
    string myData[] = {"James", "George", "Rudolph", "Jonathan", "Avian", "Rasko", "Jester"};
    int myData2[] = {10,40,30,5,50,20,8};
    
    for(int i = 0; i < sizeof(myData2)/sizeof(myData2[0]); i++){
        myTree.insert(myData2[i],myData[i]);
    }
    myTree.printPreOrder();
    myTree.remove(10);
    myTree.printPreOrder();
    
    return 0;
}
