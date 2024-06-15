#include <bits/stdc++.h>
using namespace std;

// by VINAY GUPTA__________

class node
{
    int data;
    node *next, *prev;

public:
    node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    friend class dq;
};

class dq
{
     
    int t; // for caring number of elements in DLL
    node *start;
    
public:

    dq()
    {
        t = 0;
        start = NULL;
    }

    node *getdata()
    {
        node *newnode = new node;
        cin >> newnode->data;
        newnode->next = NULL;
        newnode->prev = NULL;
        t++;
        return newnode;
    }

    void display()
    {
        int i=t-1;
        
        node *temp;
        if (start == NULL)
        {
            
            cout << "List is Empty " << endl;
            return;
        }
        
        temp = start;
        cout << "DLL Elements are : ";
        while (temp->next != NULL)
        {
            cout << temp->data << "x^"<<i<<" ";
            temp = temp->next;i--;
        }
        cout << temp->data<<"x^"<<i<<" ";i--;
        cout << endl;
    }

    void create(int n)
    {
        node *newnode;
        node *temp;
        for (int i = n; i > 0; i--)
        {
            cout << "Enter The Coefficient of x ^" << i - 1 << endl;

            newnode = getdata();
        
            if (start == NULL)
            {
                start = newnode;
                temp = start;
            }
            else
            {
                temp->next = newnode;
                newnode->prev = temp;
                temp = temp->next;
            }
            
        }
        cout << endl;
    }

    void  insert_back(int n)
    {
        node *newnode=new node;
        newnode->data=n;
        newnode->next=NULL;
        newnode->prev=NULL;
        node *temp = start;

        if(start == NULL)
        {
            start=newnode;
        }
        else{
            while(temp->prev!=NULL)
            {
                temp=temp->prev;
            }
            temp->prev=newnode;
            newnode->next=temp;
            start=newnode;
        }t++;
    }
    dq  operator+(dq p2);
};



dq dq :: operator+(dq p2)
{
    cout<<"---The Resultant Polynomial is ---";
    node *temp1=start,*temp2=p2.start;
    dq ret;
    while(temp1->next!=NULL)
        temp1=temp1->next;
    while(temp2->next!=NULL)
        temp2=temp2->next;
   
    
   
    if(t>=p2.t)
    {
        while(temp2!=NULL)
        {
            int tt= temp1->data + temp2->data;
            ret.insert_back(tt);
            temp2=temp2->prev;
            temp1=temp1->prev;
        }
        while(temp1!=NULL)
        {
            int tt= temp1->data;
            ret.insert_back(tt);
            temp1=temp1->prev;

        }
    }
    else{
        while(temp1!=NULL)
        {
            int tt= temp1->data + temp2->data;
            ret.insert_back(tt);
            temp2=temp2->prev;
            temp1=temp1->prev;
        }
        while(temp2!=NULL)
        {
            int tt= temp2->data;
            ret.insert_back(tt);
            temp2=temp2->prev;

        }

    }
  

return ret;
}

void choice(dq &q)
{
  
    int n, ch;
    cout << "Enter the Highest Degree of the Polynomial ";
    cin >> n;
    q.create(n + 1);
}

int main()
{
    cout << "\n\n----------------__CONTRIBUTED BY VINAY GUPTA__----------------\n\n";

    dq p1, p2, p3;
    cout << "---------Enter First Polynomial -----" << endl;
    // cin>>p1;
    choice(p1);
    p1.display();
    cout << "---------Enter Second Polynomial -----" << endl;
    // cin>>p2;
    choice(p2);
    p2.display();
    p3=p1+p2;
    p3.display();
    return 0;
}