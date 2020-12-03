#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct bst{
	int data;
	struct bst *left;
	struct bst *right;
};

struct bst *insert(struct bst *r,int x)
{
	if(r==NULL)
	{
		r=(struct bst*)malloc(sizeof(struct bst));
		r->data=x;
		r->left=NULL;
		r->right=NULL;
		return r;
	}
	else if(r->data > x)
	{
		r->left=insert(r->left,x);
		return r;
	}
	else if(r->data < x)
	{
		r->right=insert(r->right,x);
		return r;
	}	
}

void inorder(struct bst* r)
{
	if(r==NULL) return;
	inorder(r->left);
	cout<<r->data<<" - ";
	inorder(r->right);	
}
void preorder(struct bst* r)
{	
	if(r==NULL) return;
	cout<<r->data<<" - ";
	preorder(r->left);
	preorder(r->right);	
}
void postorder(struct bst* r)
{
	if(r==NULL) return;
	postorder(r->left);
	postorder(r->right);	
	cout<<r->data<<" - ";
}

int search(struct bst *r,int x)
{
	if(r!=NULL)
	{
		if(r->data==x) return 1;
		else if(r->data > x) search(r->left,x);
		else if(r->data < x) search(r->right,x);
	} 
	else return 0;
} 
	
int dugumsayisi(struct bst *r)
{
	if(r==NULL) return 0;
	else return 1+ dugumsayisi(r->left)+ dugumsayisi(r->right);
}

int depth(struct bst *r)
{
	if(r==NULL) return 0;
	else
	{
		int leftdepth=depth(r->left);
		int rightdepth=depth(r->right);
		if(leftdepth>rightdepth)
			return leftdepth+1;
		else
			return rightdepth+1;
	}
}

int height(struct bst *r)
{
	if(r==NULL) return -1;
	else
	{
		int leftheight=height(r->left);
		int rightheight=height(r->right);
		if(leftheight>rightheight)
			return leftheight+1;
		else
			return rightheight+1;
	}
}

struct bst *del(struct bst *r,int x)
{
	if(r==NULL)
		return 0;
	else if(r->data==x)
	{
		if(r->left==r->right)
		{
			free(r);
			return NULL;
		}
		else
		{
			if(r->left==NULL)
			{
				struct bst *temp=r->right;
				free(r);
				return temp;
			}
			else if(r->right==NULL)
			{
				struct bst *temp=r->left;
				free(r);
				return temp;
			}
			else
			{
				struct bst *temp1,*temp2;
				temp1=temp2=r->right;
				while(temp1->left!=NULL)
					temp1=temp1->left;
				temp1->left=r->left;
				free(r);
				return temp2;
				
			}
		}
	}
	else if(r->data > x) r->left=del(r->left,x);
	else if(r->data < x) r->right=del(r->right,x);	
}
int main()
{
	struct bst *tree=NULL;
	int num,num1,num2;
	cin>>num;
	
	while(num!=0)
	{
		tree=insert(tree,num);
		cin>>num;
	}
	
	cout<<"inorder= "<<endl;
	inorder(tree);
	cout<<endl;
	cout<<"preorder= "<<endl;
	preorder(tree);
	cout<<endl;
	cout<<"postorder= "<<endl;
	postorder(tree);
	
	cout<<endl;
	cout<<"Enter the number to search= "<<endl;
	cin>>num1;
	if(search(tree,num1)==1)
		cout<<"Number found.";
	else
		cout<<"Number not found.";
		
	cout<<endl;
	cout<<"Number of node=  ";
	cout<<dugumsayisi(tree);
	
	cout<<endl;
	cout<<"Deep=  ";
	cout<<depth(tree);
	
	cout<<endl;
	cout<<"height=  ";
	cout<<height(tree);
	cout<<endl;
	
	cout<<"enter the number to be deleted = "<<endl;
	cin>>num2;
	if(del(tree,num2)!=NULL)
		cout<<"The number has been deleted.";
	else
		cout<<"The number to be deleted was not found.";
	
	cout<<endl;
	cout<<"Final version inorder= "<<endl;
	inorder(tree);
	
	return 0;
}
