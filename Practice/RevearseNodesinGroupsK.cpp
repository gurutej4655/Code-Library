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
    void display()
    {
        node* head=this;
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
    node* Revearse(int k)
    {
        int i=0;
        node* pre=NULL,*post=NULL;
        node* head=this;
        while(i<k && head!=NULL) {
            post=head->ptr;
            head->ptr=pre;
            pre=head;
            head=post;
            i++;
        }return(pre);
    }
    node* RevearseKGroups(int n,int k)
    {
        if(n<k || n==0 || n==1) return(this);
        int i=0;
        node *temp=this,*cur=this,*pre=this,*head,*temp1;
        while(n>=k) {
            temp1=cur;
            cur=temp;
            while(i<k) {
                n--;
                temp=temp->ptr;
                i++;
            }
            i=0; 
            if(cur==this) {
                head=cur->Revearse(k);           
                cur->ptr=temp;
            }
            else {
                pre=cur->Revearse(k);
                cur->ptr=temp;
                temp1->ptr=pre;
            }
            }return(head);
    }
};

int main()
{
    node* head=NULL;   
    int k,n=7;
    head=head->addNode(head); 
    head=head->addNode(head);
    head=head->addNode(head);
    head=head->addNode(head);
    head=head->addNode(head);
    head=head->addNode(head);
    head=head->addNode(head);
    head->display();

    cout<<"K = ";
    cin>>k;

    head=head->RevearseKGroups(7,k);
    head->display();
    
    head->deleteAll();
}