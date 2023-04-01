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
    node* loop(){
        node* temp=this;
        while(temp->ptr!=NULL) {      
            temp=temp->ptr;      
        }temp->ptr=this;
        return(this);
    }
    void checkLoop(){
        if(this==NULL || this->ptr==NULL) { cout<<"No"<<endl; return; }
        node* f=this,*s=this,*entry=this;;
        while(f!=NULL){
            if(f->ptr==NULL) break;
            f=(f->ptr)->ptr;
            s=s->ptr;
            if(s==f) {
                while(s!=entry) {
                    s=s->ptr;
                    entry=entry->ptr;
                } 
                cout<<entry->data<<endl;
                cout<<"Yes"<<endl;
                break;
            }
        }cout<<"No"<<endl;
    }
};

int main()
{
    node* head=NULL;   
    head=head->addNode(head); 
    head->checkLoop();
    head=head->addNode(head);    
    head=head->addNode(head);
    head=head->loop();

    head=head->addNode(head);
    head=head->addNode(head);

    //head->display(head);
    head->checkLoop();
    //head->deleteAll();
}