#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
	struct node *parent;
};

void inorder(struct node *root)
{
	if(root == NULL )
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

struct node* bstSearch(struct node *root,int data)
{
	if(root == NULL || root->data == data)
		return root;
	if(root->data > data)
		return bstSearch(root->left,data);
	else
		return bstSearch(root->right,data);
}

struct node *treeMinimum(struct node* root)
{
	if(root == NULL)
		return root;
	if(root->left == NULL)
		return root;
	return treeMinimum(root->left);
}

struct node* treeMaximum(struct node* root)
{
	if(root == NULL)
		return root;
	while(root->right != NULL)
		root = root->right;
	return root;
}

struct node* successor(struct node *node)
{
	if(node == NULL)
		return node;
	if(node->right != NULL)
		return treeMinimum(node->right);

	struct node* pnode = node->parent;
	while(pnode != NULL && pnode->right == node){
		node = pnode;
		pnode = pnode->parent;
	}
	return pnode;
}

struct node* insertUtil(struct node *root,struct node* z)
{
	struct node *x = root,*y =NULL;
	while(x!=NULL){
		y=x;
		if(x->data > z->data){
			x=x->left;
		}
		else if(x->data < z->data){
			x=x->right;
		}
		else
			return root;
	}
	z->parent = y;
	if(root == NULL)
		return z;
	else{
		if(y->data > z->data)
			y->left = z;
		else
			y->right = z;
	}
	return root;
}
struct node* bstInsert(struct node*root,int data)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = newNode->right = newNode->parent = NULL;
	return insertUtil(root,newNode);
}
struct node *transplant(struct node *root, struct node *x, struct node *y)
{
	if(x->parent == NULL){
		if(y != NULL)
			y->parent = NULL;
		return y;
		}
		else if(x == x->parent->left){
			x->parent->left = y;
		}
		else if(x == x->parent->right){
			x->parent->right = y;
		}
		if(y != NULL)
			y->parent = x->parent;
	return root;
}
struct node* deleteNode(struct node *root, struct node *z)
{
	if(z == NULL)
		return root;
	if(z->left == NULL)
		root = transplant(root,z,z->right);

	else if (z->right == NULL)
		root = transplant(root,z,z->left);

	else {
		struct node *y = successor(z);
		if(y->parent != z){
			root = transplant(root,y,y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		root = transplant(root,z,y);
		y->left = z->left;
		y->left->parent = y;
	}
	return root;
}

int main()
{
	struct node *root = NULL;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		root = bstInsert(root,temp);
	}
	cout<<endl<<"inorder is : ";
	inorder(root);
	struct node* sr = bstSearch(root,7);
	if(sr)
		cout<<endl<<"node found : "<<sr->data<<endl;
	struct node* tmin = treeMinimum(root);
	if(tmin)
		cout<<endl<<"min is : "<<tmin->data<<endl;
	struct node *tmax = treeMaximum(root);
	if(tmax)
		cout<<endl<<"max is : "<<tmax->data<<endl;
	struct node *smin = successor(tmin);
	if(smin)
		cout<<endl<<"successor of min : " <<smin->data<<endl;
	struct node *smax = successor(tmax);
	if(smax)
		cout<<endl<<"successor of max : " <<smax->data<<endl;

	while(root){
		int toDelete;
		cout<<"element to be deleted : ";
		cin>>toDelete;

		struct node *slife = bstSearch(root,toDelete);
		root = deleteNode(root,slife);

		if(root)
			cout<<endl<<"new root is : "<<root->data<<endl;

		cout<<endl<<"new inorder is : ";
		inorder(root);
	}
}