#include<bits/stdc++.h>
using namespace std;


// by VINAY GUPTA__________


struct node
{
    int data=0;
    node* next,*prev;
};
node* start=NULL;
int t=0;//for caring number of elements in DLL

node *getdata()
{
    node* newnode =new node;
    // cout<<"ENTER NODE ";
    cin>>newnode->data;
    newnode->next=NULL;
    newnode->prev=NULL;

    return newnode;
}
 
void display()
{
    node *temp;
    if(start==NULL)
    {
        cout<<"List is Empty "<<endl;
        return; 
    }
    temp=start;
    cout<<"DLL Elements are : ";
    while(temp->next!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
}

void create(int n)
{
    node* newnode;
    node* temp;
    cout<<"Enter The Elements of DLL : "<<endl;
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
            newnode->prev=temp;
            temp=temp->next;

        }
        t++;
    }
    cout<<endl;
}

void insert_begin()
{
    node* newnode,*temp;
    cout<<"Enter ";
    newnode=getdata();
    if(start==NULL)
    {
        start=newnode;
        return;
    }
    temp=start;
    newnode->next=temp;
    temp->prev=newnode;
    start=newnode;
    t++;
}

void insert_last()
{
    node* newnode,*temp;
    cout<<"Enter ";
    newnode=getdata();
    if(start==NULL)
    {
        start=newnode;
        return;
    }
    temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    t++;

}

void insert_intermediate()
{
    int pos;
    cout<<"In which Position Node to be inserted "<<endl;
    cin>>pos;
    if(t==0 || t==1)
    {
        // cout<<t;
        insert_begin();
        return;
        //t++;
    }
    else if(pos>t)
    {
        cout<<"Invalid Input "<<endl;
        return;
    }
    else if(pos==t)
    {
        insert_last();
        return;
    }
    node* newnode,*temp;
    temp=start;
    cout<<"Enter ";
    newnode=getdata();
    for(int i=1;i<pos;i++)
    {
        temp=temp->next;
    }
    
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next->prev=newnode;
    t++;

}

void delete_begin()
{
    node* temp,*ptr;
    if(start==NULL)
    {
        cout<<"List is Empty "<<endl;
        return;
    }

    temp=start;
    if(temp->next==temp->prev)
    {
        start=NULL;
        cout<<"\nNow, DLL is Underflow \n"<<endl;
        return;
    }
    ptr=temp->next;
    ptr->prev=NULL;
    start=ptr;
    free(temp);
    t--;

}

void delete_last()
{
    node* temp,*ptr;
    if(start==NULL)
    {
        cout<<"List is Empty "<<endl;
        return;
    }
    temp=start;
    if(temp->next==temp->prev)
    {
        start=NULL;
        cout<<"\nNow, DLL is Underflow \n"<<endl;
        return;
    }
    while(temp->next!=NULL)
    {
        ptr=temp;
        temp=temp->next;
    }
    //ptr=temp;
    ptr->next=NULL;
    free(temp);
    t--;

}

void delete_intermediate()
{
    int pos;
    cout<<"Enter the position of the node to delete ";
    cin>>pos;
    if(start==NULL)
    {
        cout<<"List is Empty "<<endl;
        return;
    }
    else if(pos>t)
    {
        cout<<"Invalid Input "<<endl;
        return;
    }
    node* temp=start;
    if(temp->next==temp->prev)
    {
        start=NULL;
        cout<<"\nNow, DLL is Underflow \n"<<endl;
        return;
    }
    for(int i=1;i<pos;i++)
    {
        // ptr=temp;
        temp=temp->next;
    }
    if(temp==start)
    {
        delete_begin();
    }
    else if(temp->next==NULL)
    {
        delete_last();
    }
    else
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }

t--;

}


int main()
{
    cout<<"\n\n--------------------DLL--------------------\n\n";
    cout<<"\n\n----------------__CONTRIBUTED BY VINAY GUPTA__----------------\n\n";
   
    int n,ch;
    cout<<"Enter the Number of Nodes ";
    cin>>n;
    create(n);

    while(1)
    {
        cout<<"1. Insert_begin\n2. Insert_end\n3. Insert_intermediate\n4. Delete_begin\n5. Delete_end\n6. Delete_intermediate\n7. Display\n8. Exit\n\nEnter the Choice\n";
        cin>>ch;

        switch(ch)
        {
            case 1:
                insert_begin();
                break;
            case 2:
                insert_last();
                break;
            case 3:
                insert_intermediate();
                break;
            case 4:
                delete_begin();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                delete_intermediate();
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