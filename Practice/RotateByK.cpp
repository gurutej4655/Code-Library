#include <iostream>
#include <stdlib.h>
using namespace std;

class node;
class node
{
    int data;
    node *ptr;

public:
    node *getnode()
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->ptr = NULL;
        cout << "Enter the data = ";
        cin >> temp->data;
        return (temp);
    }
    node *appendNode(node *head) // At last
    {
        node *temp, *temp1 = head;
        temp = getnode();
        if (head == NULL)
            return (temp);
        while (temp1->ptr == NULL)
            temp1 = temp1->ptr;

        temp1->ptr = temp;
    }
    node *addNode(node *head) // At front
    {
        node *temp = getnode();
        temp->ptr = head;
        head = temp;
        return (head);
    }
    void display()
    {
        node *head = this;
        while (head->ptr != NULL)
        {
            cout << head->data << " --> ";
            head = head->ptr;
        }
        cout << head->data;
    }
    void deleteAll()
    {
        node *head = this, *temp;
        while (head != NULL)
        {
            temp = head->ptr;
            free(head);
            head = temp;
        }
    }
    node *RotatebyK(int n, int k)
    {
        k = k % n;
        k = n - k;

        node *head = this, *temp;
        while (head->ptr != NULL)
        {
            head = head->ptr;
        }
        head->ptr = this;
        temp = this;

        k--;
        while (k--)
        {
            temp = temp->ptr;
        }
        head = temp->ptr;
        temp->ptr = NULL;
        return (head);
    }
};

int main()
{
    node *head = NULL;
    int k, n = 7;
    head = head->addNode(head);
    head = head->addNode(head);
    head = head->addNode(head);
    head = head->addNode(head);
    head = head->addNode(head);
    head = head->addNode(head);
    head = head->addNode(head);
    head->display();

    cout << "K = ";
    cin >> k;

    head = head->RotatebyK(7, k);
    head->display();

    head->deleteAll();
}