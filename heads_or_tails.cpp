#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node{
	int data;
	struct node*next;
};
void output(struct node*r)
{
	while(r!=NULL)
	{
		cout<< r->data <<" - ";
		r=r->next;
	}
}
struct node*add(struct node*r,int x)
{
	if(r==NULL) 
	{
		r=(struct node*)malloc(sizeof(struct node));
		r->data=x;
		r->next=NULL;
		return r;	
	}
	
	struct node*iter=r;
	while(iter->next!=NULL)
		iter=iter->next;
	iter->next=(struct node*)malloc(sizeof(struct node));
	iter->next->next=NULL;
	iter->next->data=x;
	return r;
}
struct node*del(struct node*r)
{
	struct node *iter=r;
	while(iter->next->next!=NULL)
		iter=iter->next;
	struct node*temp=iter->next->next;
	iter->next=NULL;
	free(temp);
	return r;
}

int main()
{
	struct node* list0=NULL;
	struct node* list1=NULL;
	int num,choice;
	for(int i=0;i<10;i++)
	{
		cout<<"Enter Number  = ";
		cin>>num;
		if(num%2==0)
			list0=add(list0,num);
		else
			list1=add(list1,num);
	}
	
	for(int i=0;i<5;i++)
	{
		choice=rand()%2;
		if(choice==0) //--> 0 tura
			list1=del(list1);
		else
			list0=del(list0);
	}
	output(list1);
	output(list0);
	return 0;
}


