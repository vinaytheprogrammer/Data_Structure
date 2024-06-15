#include<bits/stdc++.h>
using namespace std;

class A
{
    public:
    void print()
    {
        cout<<"A "<<endl;
    }
};

class B: public A{
    public:
    void print(){
        cout<<"B "<<endl;
    }
};
int main()
{
A *a;
B b;
a=&b;
a->print(); //Object Slicing  --  
b.print(); //Overriding  -- new defition of print method is using 
return 0;
}