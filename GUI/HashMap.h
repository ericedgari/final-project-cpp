#include<bits/stdc++.h>
#include"Linked List.h"
#include <vector>
using namespace std;
//this hashmap use 20 linked list to split the data while the linked_list_all is used to store all of the data in 1 linked list to sort all the data with name
class Hash{
    const static int tableSize=20;
    linked_list l[20];
    linked_list all;
    vector<string> nameList;
    vector<string> searchNameList;
    vector<int> searchIDList;
public:
    Hash(){
        }
    //function to get the index from name
    int hashFunction(string x){
        int sum = 0; 
        for (int i = 0; i < x.length(); i++) { 
            sum = sum + int(x[i]);
        }
        return (sum % tableSize);
    }
    //add a name and id in the linked list with the index we get from hashfunction
    void insertItem(string x, int id){
        l[hashFunction(x)].add_node(x,id);
        l[hashFunction(x)].sort();
        all.add_node(x,id);
        all.sort();
    }
    //to print the data in console
    void results(){
        for(int i=0;i<tableSize;i++){
            if(l[i].get_head() != NULL){
                l[i].display(l[i].get_head());
                cout<<endl;}
            }
        }
    //deletion of a name by using the hashfunction and the linked list search function
    void delete_string(string x){
        if(l[hashFunction(x)].search(x) == -1){
            cout << "Name not found" << endl;
        }
        else{
        l[hashFunction(x)].delete_node(x);}
    }
    //return the id of searched name
    int searchName(string x){
        int index = hashFunction(x);
        int result = l[index].search(x);
        return result;
    }
    //return a vector of a name that we searched
    vector<string> searchNameVector(string x){
        searchNameList = l[hashFunction(x)].searchAllName(x);
        return searchNameList;
    }
    //return a vector of a id that searched by name
    vector<int> searchIDVector(string x){
        searchIDList = l[hashFunction(x)].searchAllID(x);
        return searchIDList;
    }
    //vector with name of all the data sorted through name
    vector<string> getNameList(){
        nameList = all.store(all.get_head());
        return nameList;
    }
    //print the vector of an String in console
    void vector_print(vector<string> a){
        for(int i=0; i<a.size();i++){
            cout << a.at(i)<<endl;
        }
    }
    //print the vector of an integer in console
    void vector_print_int(vector<int> a){
        for(int i=0; i<a.size();i++){
            cout << a.at(i)<<endl;
        }
    }
};
