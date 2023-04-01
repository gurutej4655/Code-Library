#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class NODE
{
    NODE *ptr;
    NODE *btm;
    int data;

public:
    NODE *getNode();
    NODE *addNode();
    void display();
    NODE *flatten(NODE *);
    NODE *merge(NODE *fir, NODE *sec);
};

NODE *NODE::getNode()
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->ptr = NULL;
    temp->btm = NULL;
    cout << "Data = ";
    cin >> temp->data;
    return (temp);
}

NODE *NODE::addNode()
{
    NODE *head = this, *temp;
    temp = getNode();
    if (head == NULL)
        head = temp;
    else
    {
        temp->ptr = head;
        head = temp;
    }
    cout << "Sizex = ";
    int n;
    cin >> n;
    NODE *temp1, *temp2;
    temp2 = head->btm;
    while (n--)
    {
        temp1 = getNode();
        if (temp2 == NULL)
    }
}

int main()
{
    NODE *head = NULL;
    int n;
    cout << "size = ";
    cin >> n;
    head->display();
    while (n--)
    {
        head = head->addNode();
    }
    head->display();

    head = head->flatten(head);

    head->display();
}