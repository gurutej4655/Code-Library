//Revearse linked list
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
    void display(node* head)
    {
        while(head->ptr!=NULL) { cout<<head->data<<" --> "; head=head->ptr; }
        cout<<head->data;
    }
    void deleteAll()
    {
        node* head=this->ptr,*temp;
        while(head!=NULL)
        {
            cout<<head->data<<endl;
            temp=head->ptr;
            free(head);
            head=temp;
        }
    }
    node* checkMiddleElement(){
        node *f=this,*s=this;
        while(f->ptr!=NULL && (f->ptr)->ptr!=NULL)
        {
            f=(f->ptr)->ptr;
            s=s->ptr;
        }
        return(s);
    }
    node* Revearse()
    {
        node* pre=NULL,*post=NULL;
        node* head=this;
        while(head!=NULL) {
            post=head->ptr;
            head->ptr=pre;
            pre=head;
            head=post;
        }return(pre);
    }
    node* isPalindrome()
    {
        node* s=this->checkMiddleElement(),*head=this;
        s->ptr=(s->ptr)->Revearse();
        s=s->ptr;
        while(s!=NULL)
        {
            if(head->data!=s->data) { cout<<"NO"<<endl; return(this); }
            s=s->ptr;
            head=head->ptr;
        }    
        cout<<"YES"<<endl;
        return(this);
    }
};

int main()
{
    node* head=NULL;   
    head=head->addNode(head); 
    head=head->addNode(head);    
    head=head->addNode(head);
    head=head->addNode(head);
    head=head->addNode(head);

    //head=head->Revearse();
    //head=head->checkMiddleElement();
    head->display(head);
    head=head->isPalindrome();
    head->display(head);
}