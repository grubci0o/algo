

#include <iostream>

using namespace std;

struct node{
    int value;
    node*next;
};
node*Head = nullptr;
void push(int x){
    node* e = new node;
    e->value = x;
    e->next = Head;
    Head = e;
    
}
void pop(){
    if(!Head){
        cout <<"Stos jest pusty"<< endl;
    return;    
        
    }else{
        node*e = Head;
        Head=Head->next;
        delete e;
        
    }
    
    
}
void peek(){
    cout<<"Na gorze stosu jest "<<Head->value<<endl;
}
int main()
{
    push(3);
    push(5);
    peek();
    pop();
    peek();

    return 0;
}

