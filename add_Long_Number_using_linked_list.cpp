#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};
node *getnode(){
    node *newnode=new node();
    newnode->next=NULL;
    return newnode;
}
node* createlist(string s,node *start){
    int size=s.length();
    node *newnode;
    for(int i=size-1;i>=0;i--){
        newnode=getnode();
        newnode->data=int(s[i]-'0');
        if(start==NULL){
            start=newnode;
        }   
        else{
            node *temp=start;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    return start;
}
node* addNumber(node *start1,node *start2){
    node *start=NULL;
    int carry=0;
    node *newnode,*temp1=start1,*temp2=start2;
    while(temp1!=NULL && temp2!=NULL){
        newnode=getnode();
        int sum=temp1->data + temp2->data+carry;
        carry=sum/10;
        sum=sum%10;
        newnode->data=sum;
        if(start==NULL)
            start=newnode;
        else{
            newnode->next=start;
            start=newnode;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while(temp1!=NULL){
        newnode=getnode();
        int sum=temp1->data+carry;
        carry=sum/10;
        sum=sum%10;
        newnode->data=sum;
        newnode->next=start;
        start=newnode;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        newnode=getnode();
        int sum=temp2->data+carry;
        carry=sum/10;
        sum=sum%10;
        newnode->data=sum;
        newnode->next=start;
        start=newnode;
        temp2=temp2->next;
    }
    if(carry){
        newnode=getnode();
        int sum=carry;
        carry=sum/10;
        sum=sum%10;
        newnode->data=sum;
        newnode->next=start;
        start=newnode;
    }
    return start;
}
void display(node *start){
    node *temp=start;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=NULL);
    cout<<endl;
}
int main()
{
    string s1,s2;
    node *start1=NULL,*start2=NULL;
    cout<<"enter the first no.\n";;
    cin>>s1;
    node *num1=createlist(s1,start1);
    cout<<"enter the second no.\n";;
    cin>>s2;
    node *num2=createlist(s2,start2);
    display(num1);
    display(num2);
    node *res=addNumber(num1,num2);
    cout<<"sum:\n";
    display(res);
    return 0;
}