#include<bits/stdc++.h>
using namespace std;

void conquer(int a[],int si,int mid,int ei)
{
    int *merged= new int[ei-si+1];
    int idx1=si;
    int idx2=mid+1;
    int x=0;

    while(idx1<=mid && idx2<=ei)
    {
        if(a[idx1]<=a[idx2])
        {
            merged[x++]=a[idx1++];
        }
        else{
            merged[x++]=a[idx2++];
        }
    }
    while(idx1<=mid)
    {
        merged[x++]=a[idx1++];
    }
    while(idx2<=ei)
    {
        merged[x++]=a[idx2++];
    }
    // int size=sizeof(merged)/sizeof(merged[1]);
    int size=ei-si+1;
    for(int i=0,j=si;i<size-1;i++,j++)
    {
        a[j]=merged[i];
    }
    // delete[] merged;
}

void divide(int a[],int si,int ei)
{
    if(si>=ei)
        return;
    int mid=si+(ei-si)/2;
    divide(a,si,mid);
    divide(a,mid+1,ei);
    conquer(a,si,mid,ei);
}
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];

divide(a,0,n-1);

for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
return 0;
}