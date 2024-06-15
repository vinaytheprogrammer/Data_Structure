#include<bits/stdc++.h>
using namespace std;
int top=-1;
char stack1[50];
void push(char ch)
{
    top++;
    stack1[top]=ch;
}
void pop()
{
    top--;
}
int operator1(char st)
{
    if(st=='+'||st=='-')
        return 1;
    else if(st=='*'||st=='/')
        return 2;
    else if(st=='^')
        return 3;
    else 
        return -1;
}
void postfix_conve(string st)
{
    string post="";
    char ch;
    int i=0,l=st.length();
    while(i<l)
    {
        ch=st[i];
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
            post+=ch;
        else if(ch=='(')
            push(ch);
        else if(ch==')')
        {
            while(stack1[top]!='(')
            {
                post+=stack1[top];
                pop();
            }
            pop();
        }
        else
        {
            if(operator1(ch)<=operator1(stack1[top]))
            {
                post+=stack1[top];
                pop();
                push(ch);
            }else{
                push(ch);
            }
        }
        i++;
    }
    cout<<post;
}
int main()
{
        // freopen("input.txt","r",stdin);

    // freopen("output.txt","w",stdout);
    string st;
    cin>>st;
    postfix_conve(st);
}