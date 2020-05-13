#include <iostream>
using namespace std;
#include<HashMap.h>

int main()
{
       
    Hash h;
    h.insertItem("test");
    h.insertItem("estt");
    h.insertItem("yowen");
    h.insertItem("newoy");
    h.insertItem("burung");
    h.insertItem("sapi");
    h.insertItem("bebek");
    h.insertItem("ayam");
    h.delete_string("ayam");
    h.delete_string("estt");
    h.results();
    
    return 0;
}
