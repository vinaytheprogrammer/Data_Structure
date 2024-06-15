#include <bits/stdc++.h>
#define MAX 5
using namespace std;


// Circular Queve , problem in executing.
struct cqu
{
    int front = -1, rear = -1;
    int cq[MAX];
};

void insert_rear(struct cqu *p)
{
    if ((p->front == 0 && p->rear == MAX - 1) || (p->front == p->rear + 1))
    {
        cout << "Overflow\n\n";
        return;
    }
    else
    {
        if (p->front == -1)
            p->front = 0;
        int n;
        cout << "Input\n";
        cin >> n;
        p->rear = (p->rear + 1) % MAX;
        p->cq[p->rear] = n;
    }
}

void delete_front(cqu *p)
{
    if (p->front == -1)
        cout << "Underflow\n";
    else
    {
        cout << "Element deleted  " << p->cq[p->front];
        if (p->front == p->rear)
        {
            p->front = -1;
            p->rear = -1;
        }

        p->front = (p->front + 1) % MAX;
    }
}

void display(cqu *p)
{
    int i = p->front;
    int j = p->rear;

    if (p->front == -1)
    {
        cout << "Underflow\n";
        return;
    }
    else
    {
        if (i <= j)
        {
            while (i <= j)
            {
                cout << p->cq[i] << " ";
                i++;
            }
        }
        else
        {
            while (i <= MAX - 1)
            {
                cout << p->cq[i] << " ";
                i++;
            }
            i = 0;
            while (i <= j)
            {
                cout << p->cq[i] << " ";
                i++;
            }
        }
    }
}

int main()
{
    cqu *p;
    while (1)
    {
        int ch;

        cout << "1.INSERT_REAR\n2.DELETE_FRONT\n3.DISPLAY\n4.EXIT\n\n";
        cout << "Enter Choice\n\n";

        cin >> ch;
        switch (ch)
        {
        case 1:
            insert_rear(p);
            break;
        case 2:
            delete_front(p);
            break;
        case 3:
            display(p);
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}