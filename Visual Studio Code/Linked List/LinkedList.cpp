#include<iostream>
#include<stdlib.h>
using namespace std;

class node;
class node
{
    int data;
    node* ptr;
    public:
    node* getnode()
    {
        node* temp=(node*)malloc(sizeof(node));
        temp->ptr=NULL;
        cout<<"Enter the data = ";
        cin>>temp->data;
        return(temp);
    }
    node* appendNode(node* head)    //At last
    {
        node *temp,*temp1=head;
        temp=getnode();
        if(head==NULL) return(temp);
        while(temp1->ptr==NULL) temp1=temp1->ptr;

        temp1->ptr=temp;
    }  
    node* addNode(node* head) //At front
    {
        node* temp=getnode();
        temp->ptr=head;
        head=temp;
        return(head);
    }
    node* addAfter(node* head,int k)
    {
        node* temp=head,*temp1;
        while(temp!=NULL && temp->data!=k) temp=temp->ptr;

        if(temp==NULL) appendNode(head);
        else 
        {
            temp1=getnode();
            temp1->ptr=temp->ptr;
            temp->ptr=temp1;
        }return(head);
    }
    node* addBefore(node* head,int k)
    {
        node* temp=head,*temp1=head;
        while(temp!=NULL && temp->data!=k) { temp1=temp; temp=temp->ptr; }   
        if(temp==NULL) appendNode(head);
        else if(temp==head) addNode(head);
        else
        {
            temp=getnode();
            temp->ptr=temp1->ptr;
            temp1->ptr=temp;
        }     
    }
    node* deleteLast(node* head)
    {        
    }
    node* deleteFirst(node* head)
    {
    }
    node* deleteAfter(node* head,int k)
    {
    }
    node* deleteBefore(node* head,int k)
    {
    }
    void display(node* head)
    {
        while(head->ptr!=NULL) { cout<<head->data<<" --> "; head=head->ptr; }
        cout<<head->data;
    }
    void deleteAll()
    {
        node* head=this,*temp;
        while(head!=NULL)
        {
            temp=head->ptr;
            free(head);
            head=temp;
        }
    }
};

int main()
{
    node* head=NULL;   
    head=head->addNode(head); 
    head=head->addNode(head);
    head=head->addNode(head);
    
    head->deleteAll();
}