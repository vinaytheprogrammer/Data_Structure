#include<bits/stdc++.h>

using namespace std;
struct node
{
    int data=0;
    node *next;
};
node *start=NULL;

node *getnode()
{
    node *newnode;
    newnode =new node;
    cout<<"Enter data\n";
    cin>>newnode->data;
    newnode->next=NULL;

    return newnode;
}

void create(int n)
{
    node *newnode,*temp;
    for(int i=0;i<n;i++)
    {
        newnode=getnode();

        if(start==NULL)
        {
           start=newnode;

        }
        else{ 
            temp=start;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;

        }

    }

}


void display()
{
node *newnode;
newnode = start;
if(newnode==NULL)
{
    cout<<"List is empty\n";
    return ;
}
do
{
    cout<<newnode->data<<" ";
    newnode=newnode->next;    
} while (newnode!=NULL);

}


int main()
{
    int n;
    cin>>n;
    create(n);
    display();
    return 0;
}