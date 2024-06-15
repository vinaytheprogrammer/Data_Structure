#include<bits/stdc++.h>
using namespace std;
char stack1[50];
int top=-1;
void push(char ch)
{
    top++;
    stack1[top]=ch;
}
void pop()
{
    top--;
}
int operator1(char ch)
{
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/')
        return 2;
    else if(ch=='^')
        return 3;
    else 
        return -1;
}
void info_prefix(string st)
{
    string prefix="";
    char ch;
    int i=0,l=st.length();
    while(i<l)
    {
        ch=st[i];
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
            prefix+=ch;
        else if(ch=='(')
            push(ch);
        else if(ch==')')
        {
            while(stack1[top]!='(')
            {
                prefix+=stack1[top];
                pop();
            }
            pop();
        }
        else
        {
            if(operator1(ch)<=operator1(stack1[top]))
            {
                prefix+=stack1[top];
                pop();
                push(ch);
            }else{
                push(ch);
            }
        }
        i++;
    }
    reverse(prefix.begin(),prefix.end());
    cout<<prefix;
}
int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
   string st;
    cin>>st;
    reverse(st.begin(),st.end());
    for(int i=0;i<st.length();i++)
    {
        if(st[i]=='(')
            st[i]=')';
        else if(st[i]==')')
            st[i]='(';
    }
    info_prefix(st);
    return 0;
}