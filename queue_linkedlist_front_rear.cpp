#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct queue{
	char c;
	struct queue *next;
};struct queue *front=NULL, *rear=NULL;

void enqueue(char x)
{
	if(rear==NULL)
	{	
		rear=(struct queue*)malloc(sizeof(struct queue));
			rear->c=x;
			rear->next=NULL;
			front=rear;	
	}
	else
	{
		rear->next=(struct queue*)malloc(sizeof(struct queue));
			rear=rear->next;
			rear->c=x;
			rear->next=NULL;
	}	
}
void dequeue()
{
	if(front==NULL)
	{
		cout<<"queue is empty(";
		return;
	}
	else
	{
		if(front->next==NULL)
		{
			rear=NULL;
		}
		struct queue *temp=front;
		front=front->next;
		cout<<"Deleted"<<temp->c<<endl;
		free(temp);
		return;	
	}
}


int main()
{
	char c;
	for(int i=0;i<6;i++)
	{
		cin>>c;
		enqueue(c);
	}
	
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	return 0;
}
