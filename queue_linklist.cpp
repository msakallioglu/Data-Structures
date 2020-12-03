#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;


struct queue{
	int x;
	struct queue* next;
};
int cikan;
void goster(struct queue *r)
{
	while(r!=NULL)
	{
		cout<<"Data: "<<r->x <<" Address: "<<r<<"  Next: "<<r->next<<endl;
		r=r->next;
	}
}
struct queue* enqueue(struct queue *r,int x)
{
	if(r==NULL)
	{
		r=(struct queue*)malloc(sizeof(struct queue));
		r->x=x;
		r->next=NULL;
		return r;
	}
	else
	{
		struct queue *temp=(struct queue*)malloc(sizeof(struct queue));
		temp->x=x;
		temp->next=r;
		return temp;
	}
}

struct queue* dequeue(struct queue *r)
{
	if(r==NULL)
	{
		cout<<"queue is empty"<<endl;
		return 0;
	}
	else if(r->next==NULL)
	{
		cout<<"Deleted= "<<r->x<<endl;
		r=NULL;
		return r;
	}
	else{ 	
	struct queue*iter=r;
		while(iter->next->next!=NULL)
			iter=iter->next;
					
	struct queue *temp=iter->next;
		iter->next=NULL;
		cout<<"Deleted= "<<temp->x<<endl;
		
		free(temp);
		return r;
	}
}
int main()
{
	struct queue *q=NULL;
	int num;
	for(int i=0;i<10;i++)
	{
		cin>>num;
		q=enqueue(q,num);
	}
	goster(q);
	q=dequeue(q);
	q=dequeue(q);
	q=dequeue(q);
	q=dequeue(q);
	q=dequeue(q);
	q=dequeue(q);
	q=dequeue(q);
	q=dequeue(q);
	q=dequeue(q);
	q=dequeue(q);
	
	return 0;
}
