
#include<iostream>
using namespace std;
struct node{
	int data,height;
	node* left;
	node* right;
};
int max(int a,int b){
	return (a>b)?a:b;
}
int height(node* n){
	return (n==NULL)?0:n->height;
}
int getbalance(node* n){
	return (n==NULL)?0:height(n->left)-height(n->right);
}
node* newnode(int data){
	node* Node=new node;
	Node->data=data;
	Node->left=Node->right=NULL;
	Node->height=1;
	return Node;
}
node* rightrotate(node* y){
	node*x=y->left;
	y->left=x->right;
	x->right=y;
	
	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	return x;
}
node* leftrotate(node* x){
	node* y=x->right;
	x->right=y->left;
	y->left=x;
	
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}
node* insert(node* Node,int data){
	if(Node==NULL) 
	return newnode(data);
	if(data<Node->data)
	Node->left=insert(Node->left,data);
	else if(data>Node->data)
	Node->right=insert(Node->right,data);
	else 
	return Node;
	
	Node->height=1+max(height(Node->left),height(Node->right));
	int balance=getbalance(Node);
	if(balance>1 && data<Node->left->data)
	return rightrotate(Node);
	if(balance<-1&&data>Node->right->data)
	return leftrotate(Node);
	if(balance>1 && data>Node->left->data){
		Node->left=leftrotate(Node->left);
		return rightrotate(Node);
	}
	if(balance<-1&&data<Node->left->data){
		Node->right=rightrotate(Node->right);
		return leftrotate(Node);
	}
	return Node;
	}
void inorder(node* root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

int main(){
	node* root=NULL;
	int values[7]={20,30,10,35,50,40};
	for(int i=0;i<7;i++)
	
	   root=insert(root,values[i]);
	   cout<<"AVL inorder traversal: ";
	   inorder(root);
	   cout<<endl;
	   return 0;
}

