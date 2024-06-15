#include<bits/stdc++.h>
using namespace std;
// class node
// {
//     int data;
//     node *next;
//     public:
//     node(int d=0,node* next =NULL)
//     {
//         data=d;
//         this->next=next;
//     }

// };

struct node
{
    int data;
    node* next;
};
node *start=NULL;


node* getdata()
{
    node *newnode;
    newnode =new node;
    // cout<<"Enter data\n";
    cin>>newnode->data;
    newnode->next=NULL;

    return newnode; 
}

void create(int n)
{
    node* newnode;
    node* temp;
    for(int i=0;i<n;i++)
    {
        newnode=getdata();
        if(start==NULL)
        {
            start=newnode;
            temp=start;

            
        }
         else{
            temp->next=newnode;
            temp=temp->next;

        }

    }
}

void insert_begin()
{
    node *newnode;
    newnode =getdata();
    if(start==NULL)
    {
        start=newnode;
    }
    else{
        newnode->next=start;
        start=newnode;
    }
}

void insert_mid()
{
    int pos;
    node *newnode,*temp;
    temp=start;
    cout<<"Enter the position after which node to be inserted\n";
    cin>>pos;
    for(int i=1;i<pos;i++)
        temp=temp->next;
    newnode=getdata();
    newnode->next=temp->next;
    temp->next=newnode;

}

void insert_last()
{
    node* newnode,*temp;
    newnode =getdata();

    if(start==NULL)
    {
        start=newnode;
    }
    else{
        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}


void delete_front()
{
    node* temp;
    if(start==NULL)
    {
        cout<<"empty\n";
        return;
    }
    else{
        temp=start;
        start=temp->next;
        free(temp);
    }
}

void delete_last()
{
    node *temp,*ptr;
    if(start==NULL)
    {
        cout<<"empty\n";
        return;
    }
    else{
        ptr=start;
        temp=start;
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        free(ptr);
    }
}


void delete_mid()
{
    int x;
    node *ptr,*temp;
    ptr=temp=start;
    cout<<"Enter the data of the node to be deleted\n";
    cin>>x;
    while(ptr->data!=x)
    {
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    free(ptr);
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
cout<<endl;
}
int main()
{
    int ch,n;
    cout<<"Enter Number of Nodes for SLL "<<endl;
    cin>>n;
    create(n);
    while(1)
    {
        cout<<"1. Insert_begin\n2. Insert_mid\n3. Insert_end\n4. Delete_begin\n5. Delete_end\n6. Delete_mid\n7. Display\n8. Exit\n\nEnter your Choice  ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                insert_begin();
                break;
            case 2:
                insert_mid();
                break;
            case 3:
                insert_last();
                break;
            case 4:
                delete_front();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                delete_mid();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                break;

        }
    }
    return 0;
}