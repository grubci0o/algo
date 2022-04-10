#include <iostream>

using namespace std;
struct node{
    int value;
    int priority;
    node*next;
};
node* front = nullptr;
node* rear = nullptr;
void enqueue(int x,int y){
    node*p = new node;
    p->value = x;
    p->priority =y;
    if(front == nullptr){
        front = p;
        rear = p;
    }else if(front->priority <p->priority){
        p->next = front;
        front = p;
        
    }
    else{node*e = front;
        while(e->next!= nullptr  && e->next->priority > p->priority){
            e=e->next;
        }
        p->next = e->next;
        e->next = p;
        }
}
void dequeue(){
    if(front==nullptr){
        cout<<"Lista jest pusta "<<endl;
        return;
    }else if(front == rear){
        node*p = front;
        delete p;
        front = rear = nullptr;
    }else{
        node*e = front;
        front = front->next;
        delete e;
        
    }
    
}
void display(){
    node*e = front;
    while(e!=nullptr){
        cout<<"Wartosc "<<e->value<<" Priorytet "<<e->priority<<"->";
        e=e->next;
    }
    cout<<endl;
}
int main()
{
    enqueue(5,1);
    enqueue(60,0);
    enqueue(2,5);
    enqueue(5,3);
    display();
    enqueue(10,4);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}
