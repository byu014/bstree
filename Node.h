#include <iostream>
#include <string>
using namespace std;

struct Node{
    Node * left;
    Node * right;
    string data;
    int counter;
    Node(string userString);//:left(0),right(0),data(userString),counter(1){
//};
};