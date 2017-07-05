#include <iostream>


using namespace std;

//Creating a tree node

struct Node
{
    int data;
    struct Node *left, *right;
};

//tree traversal
void inorder(Node *root){
if(root == NULL){
    return;
}
inorder(root->left);
cout<<root->data<<endl;
inorder(root->right);
}


//function to create new node
 Node* newNode(int data){
    struct Node *temp = new Node;
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
    return(temp);
}

//function to insert node
Node* insert(Node *root, Node *node){

    if(root==NULL){
        return node;
    }

    if(root->data < node->data){
        root->right = insert(root->right,node);
    }
    else if(root->data > node->data){
        root->left = insert(root->left,node);
    }

    return root;

}
//function to inset node based on key
 Node* insert(Node *root, int key){

    if(root==NULL){
        return newNode(key);
    }

    if(root->data < key){
        root->right = insert(root->right,key);
    }
    else if(root->data > key){
        root->left = insert(root->left,key);
    }

    return root;

}
//main function
int main(){
     Node *root = newNode(1);
    insert(root,newNode(2));
    insert(root, newNode(3));
    insert(root, newNode(4));
    insert(root,newNode(5));
    cout<<"passing Node to recursive function"<<endl;
    inorder(root);
    Node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    cout<<"Just printing inorder"<<endl;
    inorder(root1);
    Node *root2 = newNode(1);
    insert(root2,2);
    insert(root2, 3);
    insert(root2, 4);
    insert(root2,5);
    cout<<"Passing key to recursive function"<<endl;
    inorder(root2);
    return 0;
}

