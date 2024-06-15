#include<iostream>
using namespace std;


// DS quesstion midsem
int i=0;
int fun (int a,int b)
{
    // cout<<fun(a,b)<<endl<<" ";
    if(a<b)
    {
        return 0;
    }
    else
    {
        // int l=(fun(a-b,b)+1);
        // cout<<l<<" "<<i<<endl;
        i++;
        return (fun(a-b,b)+1);
    }
}
int main()
{
    cout<<fun(5861,7)+1;
    cout<<" " <<i;
    return 0;
}