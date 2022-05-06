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
    bool hasPathSum(BST*,int);
 
    void Inorder(BST*);
    void printTree(BST*);//od najwiekszego do najmniejszego
    void postOrder(BST*);
    int size(BST*);
    int maxDepth(BST*);
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
int BST::size(BST*root){
    if(!root){
        return 0;
    }else{
        return size(root->left) + 1 + size(root->right);//schodzimy w lewe i prawe poddrzewo dodajac 1 za kazdym razem
    }
    
    
}
int BST::maxDepth(BST*root){
    int left = 0;
    int right = 0;
    if(!root){
        return 0;
    }else{ left = size(root->left) + 1;
        right = size(root->right) + 1;
    }
    if(left > right){
        return left;
    }else{
        return right;
    }
    
    
    
}
void BST::printTree(BST*root){
    if(!root){
        return;
    }
    printTree(root->right);
    cout<<root->value<<"    "<<endl;
    printTree(root->left);
    
}
void BST::postOrder(BST*root){
    if(!root){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->value<<"     ";
    
}
bool BST::hasPathSum(BST* root,int sum){
    bool ans = 0;
    int subsum = sum - root->value;
    if(subsum == 0 && root->left == nullptr && root->right == nullptr){
        return 1;
    }else{if(root->left){
        ans = ans || hasPathSum(root->left,subsum);
    }if(root->right){
        ans = ans || hasPathSum(root->right,subsum);
    }
        
        
    }
    return ans;
    
    
}
int main()
{
    BST* root = nullptr;
    BST binarytree;
    root = binarytree.Insert(root,4);
    binarytree.Insert(root,2);
    binarytree.Insert(root,5);
    binarytree.Insert(root,1);
    binarytree.Insert(root,3);
    //binarytree.Inorder(root);
   // cout<<binarytree.size(root)<<endl;
   // cout<<binarytree.maxDepth(root)<<endl;
   // binarytree.printTree(root);
   //binarytree.postOrder(root);
   cout<<binarytree.hasPathSum(root,7)<<endl;
    return 0;
}
