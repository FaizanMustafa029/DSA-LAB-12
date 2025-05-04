#include<iostream>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};
node* newnode(int data){
	node* Node=new node();
	Node->data=data;
	Node->left=Node->right=NULL;
	return Node;
}
	

node* insertbst(node* root,int data){
	if(root==NULL)
	return newnode(data);
	if(data<root->data)
	root->left=insertbst(root->left,data);
	else if(data>root->data)
	  root->right=insertbst(root->right,data);
	  return root;
}
void inorderbst(node* root){
	if(root!=NULL){
		inorderbst(root->left);
		cout<<root->data<<" ";
		inorderbst(root->right);
	}
}
int main(){
	node* root=NULL;
	int values[]={30,20,40,10,25,35,50};
	for(int i=0;i<7;++i)
		root=insertbst(root,values[i]);
	    cout<<"BST inorder traversal: ";
	    inorderbst(root);
	    cout<<endl;
}

