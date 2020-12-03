#include <conio.h>
#include <iostream>
#define size 5
using namespace std;
struct q{
	int array[size];
	int first;
	int last;
	int qsize;
};
int cikan;
struct q enqueue(struct q temp,int x)
{
	temp.last=(temp.last+1)%size;
	cout<<temp.last<<" - - - "<<temp.first<<endl;
	if(temp.last==temp.first)
	{
		cout<<"queue is full"<<endl;
	}
	else
	{
		temp.array[temp.last]=x;
		temp.qsize++;
	}
	return temp;
}

struct q dequeue(struct q temp)
{
	cout<<"dequeue - - -"<<temp.last<<" - - - "<<temp.first<<endl;
	if(temp.first==temp.last)
	{
		cout<<"queue is empty"<<endl;
	}
	else
	{
		temp.first=(temp.first+1)%size;
		cikan=temp.array[temp.first];
		temp.qsize--;
	}
	return temp;
}


int main()
{
	struct q queue;
	
	queue.first=size-1;
	queue.last=size-1;
	queue.qsize=0;
	
	queue=enqueue(queue,10);
	queue=enqueue(queue,20);
	queue=enqueue(queue,30);
	queue=enqueue(queue,40);
	queue=enqueue(queue,50);
		
		queue=dequeue(queue);
	cout<<cikan<<endl;
	
		queue=dequeue(queue);
	cout<<cikan<<endl;
	
		queue=dequeue(queue);
	cout<<cikan<<endl;
		queue=dequeue(queue);
	cout<<cikan<<endl;
		queue=dequeue(queue);
	cout<<cikan<<endl;
		queue=dequeue(queue);
	cout<<cikan<<endl;
	return 0;
}
