#include <iostream>
using namespace std;
struct node{
    int value;
    node* next;
    
};
void addB(node*&head,int x){
    node*p = new node;
    p->value = x;
    p->next = head;
    head = p;
    
}
void show(node*head){
    node*p = head;
    while(p!=NULL){
        cout<<p->value<<'-';
        p = p->next;
    }
    cout<<"\n";
}
void addE(node*&head,int x){
    if(head == NULL){
        addB(head,x);
    }
    
    node*p = head;
    while(p->next!=NULL){
        p=p->next;
    }
    node*e = new node;
    e->value = x;
    p->next = e;
    e->next = NULL;
   
}
void delB(node*&head){
    node*p = head;
    head = head->next;
    delete p;
    
}
void deleteV(node*&head,int x){
    if(head->value == x){
        delB(head);
    }
    else{
    node*p = head;
    node*e = new node;
    while(p->next->value!=x){
        p=p->next;
    }
    e = p->next;
    p->next = e->next;
    delete e;
    }
    
}
    
void delE(node*&head){
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    node*p = head;
    while(p->next->next!=NULL){
        p=p->next;
    }
    node*e = p->next;
    delete e;
    p->next = NULL;
}
int listLen(node*head){
    int count = 0;
    node*p = head;
    while(p!=NULL){
        count++;
        p=p->next;
    }
   // cout<<"Lista ma "<<count<<" elementow"<<endl;
    return count;
}


int main()
{
    node*head = NULL;
    addB(head,5);
    delB(head);
    addB(head,11);
    deleteV(head,11);
    show(head);
    addB(head,12);
    show(head);
    return 0;
}
