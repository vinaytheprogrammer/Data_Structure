#include <bits/stdc++.h>
using namespace std;

int Binary_Search(int *p, int n, int a)
{
    int start = 0, end = n;
    int mid = (start + end) / 2;
    if (a < *p || a > *(p + n - 1))
        return -1;
    while (1)
    {
        if (p[mid] > a)
        {
            end = mid;
            mid = (start + end) / 2;
        }
        else if (p[mid] < a)
        {
            start = mid;
            mid = (start + end) / 2;
        }
        else
        {
            return mid;
        }
    }
}

int main()
{
    int *a, n, m;
    cout << "How Many Element Do You Want To Insert  :";
    cin >> n;
    cout << "Enter The Elements of Pointer Array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> *(a + i);
    }
    // sort(a.begin(),a.end());
    sort(a, a + n);
    cout << "Which Number You Want To Search : ";
    cin >> m;
    cout << Binary_Search(a, n, m);
    return 0;
}