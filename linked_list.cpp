#include<bits/stdc++.h>
using namespace std;
class Node
{
        int data;
        Node *next;
    public:
        Node *getNode(){
            Node *newNode=new Node();
            cout<<"Enter the data for node : ";
            cin>>newNode->data;
            newNode->next=NULL;
            return newNode;
        }
        /*
        getdata()
        insertFromFront()
        insertFromBack()
        insetFromMid()
        deleteFromFront()
        deleteFromBack()
        deleteFromMid()
        display()
        */ 



};


int main()

{
    return 0;
}