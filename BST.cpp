
#include <iostream>

using namespace std;
class BST{
    public:
    int value;
    BST* left,*right;
    public:
    BST();
    BST(int);
 
    BST* Insert(BST*, int);
    BST* search(BST*, int);
    BST* minval(BST*);
 
    void Inorder(BST*);
    BST* deleteNode(BST*&,int);
};
BST::BST(){
    value = 0;
    left = nullptr;
    right = nullptr;
}
BST::BST(int x){
    value = x;
    left = nullptr;
    right = nullptr;
}
BST* BST::Insert(BST* root,int x){
    if(!root){
        return new BST(x);
    }
    if(root->value > x){
       root->left = Insert(root->left,x);
    }
    if(root->value < x){
        root->right =Insert(root->right,x);
    }
    return root;
    
}
void BST::Inorder(BST*root){
    if(!root){
        return;
    }
    Inorder(root->left);
    cout<<root->value<<"    "<<endl;
    Inorder(root->right);
}
BST* BST::search(BST*root,int x){
    if(root->value == x){
        return root;
    }
    if(root->value > x){
        return search(root->left,x);
    }
    if(root->value < x){
        return search(root->right,x);
    }
    return root;
}
BST* BST::minval(BST* root){
    BST* temp = root;
    while(temp->left != nullptr){
        temp = temp->left;
        
    }
    return temp;
    
}
BST* BST::deleteNode(BST*&root,int x){
    if(!root){
        return nullptr;
    }else if(x > root->value){
        root->right =deleteNode(root->right,x);
    }else if(x < root->value){
        root->left =deleteNode(root->left,x);
    }else{
        if(root->left == nullptr ){
        BST* temp = root->left;
        delete root;
        return temp;
        }
        if(root->right == nullptr ){
        BST* temp = root->left;
        delete root;    
        return temp;
        }else{ BST* temp = minval(root->right);
            root->value = temp->value; 
            root->right = deleteNode(root->right,temp->value);
            
            
        }
        
        
        
        
    }
    return root;
}
int main()
{
    BST* root = nullptr;
    BST binarytree;
    root = binarytree.Insert(root,10);
    binarytree.Insert(root,20);
    binarytree.Insert(root,5);
    binarytree.Insert(root,15);
    binarytree.deleteNode(root,10);
    binarytree.Inorder(root);
    return 0;
}
