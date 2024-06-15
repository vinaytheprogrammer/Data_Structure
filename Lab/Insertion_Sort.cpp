#include <bits/stdc++.h>
using namespace std;

// void swap(int &a,int &b)
// {
//     a=a^b;
//     b=a^b;
//     a=a^b;
// }

int * Insertion_Sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (a[j] >temp && j>=0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }

    return a;
}
int main()
{
    int a[5] = {10, 2, 6, 4, 5};
    int n = 5;
    Insertion_Sort(a, 5);

    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

    return 0;
}