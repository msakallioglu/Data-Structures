//Data Structures
//Final Project
//Melike Sakallioglu
//2017

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#define size 50
#define boyut 50
using namespace std;
struct stack{
	int c[size];
	int top;
};

struct q{
	char array[boyut];
	int ax[boyut];
	int bx[boyut];
	int last;
	int first;
	int qsize;
};
char cikan;
int veri;
int qx;
int qy;
struct stack push(struct stack y,int c)
{
	if(y.top==size-1)
	{
		cout<<"stack dolu";
		return y;
	}
	else
	{
		y.top++;
		y.c[y.top]=c;
		return y;
	}
}
struct stack pop(struct stack y)
{
	if(y.top==0)
	{
		cout<<"stack bos";
		return y;
	}
	else
	{
		veri=y.c[y.top];
		y.top--;
		return y;
	}
}
struct q enqueue(struct q temp,char x,int xa,int xb)
{
	if(temp.last==boyut)
	{
		cout<<"Kuyruk Dolu"<<endl;
	}
	else
	{
		temp.array[temp.last]=x;
		temp.ax[temp.last]=xa;
		temp.bx[temp.last]=xb;
		temp.qsize++;
		temp.last++;
	}
	
	return temp;
}

struct q dequeue(struct q temp)
{
	temp.first++;
	if(temp.first==temp.last)
	{
		cout<<"queue empty . . ."<<endl;
		cikan='e';
		temp.first--;
	}
	else
	{
		qx=temp.ax[temp.first];
		qy=temp.bx[temp.first];
		cikan=temp.array[temp.first];

	}
	return temp;
}


void tablo(int x, int y)
{
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<31;j++)
		{
			if(i==x && j==y)
				printf("&");
			else
				printf(" . ");	
		}
		printf("\n");
	}
}


int main()
{
	int bitir=0,puan=0,sayac=0;
	int m[16][31];
	struct stack s;
	s.top=0;
	struct q queue;
	queue.first=-1;
	queue.last=0;
	queue.qsize=0;
	for(int i=0;i<16;i++) 
	{
		m[i][30]=0;
	}
	for(int i=0;i<31;i++) 
	{
		m[15][i]=0;
	}
	
	int a,b;
	for(int i=0;i<100;i++) 
	{
		a=rand()%14;
		b=rand()%30;
		m[a][b]=1;
	}
	
	char c;
	int x=15,y=30;
	cout<<"Press any key to start the game :) "<<endl;
	c=getch();
	system("cls");

	tablo(x,y);
	
	while(c!='e' && bitir==0)
	{
		cout<<"total score = "<<puan<<endl;
		c=getch();
		
		switch(c)
		{
			case'w':
				x=x-5;
				if(x>=0 && x<16)
				{	
					if(m[x][y]==1)
					{
						queue=enqueue(queue,'m',x,y);
						system("cls");
						cout<<"Bomm Minee !!!"<<endl;
						tablo(x,y);
						if(sayac==0) // 2 konum
						{
							s=pop(s); // ilk y
							s=pop(s); // ilk x
							s=pop(s); // ilk y
							y=veri;
							s=pop(s); 
							x=veri;
							system("cls");
							cout<<"Bomm Minee !!!"<<endl;
							puan-=30;
							tablo(x,y);	
						}
						else if(sayac==1)
						{
							for(int i=0;i<4;i++)
							{
								s=pop(s);
								s=pop(s);
							}
							s=pop(s);
							y=veri;
							s=pop(s);
							x=veri;
							system("cls");
							cout<<"Bomm Minee !!!"<<endl;
							puan-=70;
							tablo(x,y);	
						}
						else if(sayac==2) 
						{
							s=pop(s);
							y=veri;
							s=pop(s);
							x=veri;
							system("cls");
							cout<<"Bomm Minee !!!"<<endl;
							puan-=200;
							tablo(x,y);	
							bitir=1;
						}
						sayac++;
						
					}
					else
					{
						puan+=100;
						s=push(s,x);
						s=push(s,y);
						queue=enqueue(queue,'u',x,y);
						system("cls");
						tablo(x,y);
						
					}
				}
				else //alandýsý
				{
					system("cls");
					x=x+5;
					tablo(x,y);
					cout<<"Out of Area"<<endl;
				}
			break;
			case'd':
				y=y+5;
				
				if(y>=0 && y<31)
				{
					if(m[x][y]==1)
					{
						queue=enqueue(queue,'m',x,y);
						system("cls");
						cout<<"Bomm Minee !!!"<<endl;
						tablo(x,y);
						if(sayac==0) // 2 konum
						{
							s=pop(s); // ilk y
							s=pop(s); // ilk x
							s=pop(s); // ilk y
							y=veri;
							s=pop(s); 
							x=veri;
							system("cls");
							cout<<"Bomm Minee !!!"<<endl;
							puan-=30;
							tablo(x,y);	
						}
						else if(sayac==1)
						{
							for(int i=0;i<4;i++)
							{
								s=pop(s);
								s=pop(s);
							}
							s=pop(s);
							y=veri;
							s=pop(s);
							x=veri;
							system("cls");
							cout<<"Bomm Minee !!!"<<endl;
							puan-=70;
							tablo(x,y);	
						}
						else if(sayac==2) 
						{
							s=pop(s);
							y=veri;
							s=pop(s);
							x=veri;
							system("cls");
							cout<<"Bomm Minee !!!"<<endl;
							puan-=200;
							tablo(x,y);	
							bitir=1;
						}
						sayac++;
						
					}
					else 
					{	puan+=100;
						s=push(s,x);
						s=push(s,y);
						queue=enqueue(queue,'r',x,y);
						system("cls");
						tablo(x,y);
						
					}
				}
				else //alandýsý
				{
					y=y-5;
					system("cls");
					tablo(x,y);
					cout<<"Out of Area"<<endl;
				}
			break;
			case's':
				x=x+5;
				if(x>=0 && x<16)
				{
					if(m[x][y]==1)
					{
						queue=enqueue(queue,'m',x,y);
					system("cls");
					cout<<"Bomm Minee !!!"<<endl;
						tablo(x,y);
						if(sayac==0) // 2 konum
						{
							
							s=pop(s); // ilk y
							s=pop(s); // ilk x
							s=pop(s); // ilk y
							y=veri;
							s=pop(s); 
							x=veri;
							system("cls");
							cout<<"Bomm Minee !!!"<<endl;
							puan-=30;
							tablo(x,y);	
						}
						else if(sayac==1)
						{
							for(int i=0;i<4;i++)
							{
								s=pop(s);
								s=pop(s);
							}
							s=pop(s);
							y=veri;
							s=pop(s);
							x=veri;
							system("cls");
							cout<<"Bomm Minee !!!"<<endl;
							puan-=70;
							tablo(x,y);	
						}
						else if(sayac==2) //cýkýs
						{
							s=pop(s);
							y=veri;
							s=pop(s);
							x=veri;
							system("cls");
							cout<<"Bomm Minee !!!"<<endl;
							puan-=200;
							tablo(x,y);	
							bitir=1;
						}
						sayac++;
						
					}
					else 
					{
						puan+=100;
						s=push(s,x);
						s=push(s,y);
						queue=enqueue(queue,'d',x,y);
						system("cls");
						tablo(x,y);
					}
				}
				else //alandýsý
				{
					x=x-5;
					system("cls");
					tablo(x,y);
					cout<<"Out of Area"<<endl;
				}
					
			break;
			case'a':
				y=y-5;
				if(y>=0 && y<31)
				{
					if(m[x][y]==1)
					{
						queue=enqueue(queue,'m',x,y);
						system("cls");
						cout<<"Bomm Minee !!!"<<endl;
						tablo(x,y);
						if(sayac==0) // 2 konum
						{
							
							s=pop(s); // ilk y
							s=pop(s); // ilk x
							s=pop(s); // ilk y
							y=veri;
							s=pop(s); 
							x=veri;
							system("cls");
							cout<<"Bomm Minee !!!"<<endl;
							puan-=30;
							tablo(x,y);	
						}
						else if(sayac==1)
						{
							for(int i=0;i<4;i++)
							{
								s=pop(s);
								s=pop(s);
							}
							s=pop(s);
							y=veri;
							s=pop(s);
							x=veri;
							system("cls");
							cout<<"Bomm Minee !!!"<<endl;
							puan-=70;
							tablo(x,y);	
						}
						else if(sayac==2) //cýkýs
						{
							s=pop(s);
							y=veri;
							s=pop(s);
							x=veri;
							system("cls");
							cout<<"Bomm Minee !!!"<<endl;
							puan-=200;
							tablo(x,y);	
							bitir=1;
						}
						sayac++;
							
					}
					else 
					{
						puan+=100;
						s=push(s,x);
						s=push(s,y);
						queue=enqueue(queue,'l',x,y);
						system("cls");
						tablo(x,y);
					}
				}
				else //alandýsý
				{
					y=y+5;
					system("cls");
					tablo(x,y);
					cout<<"Out of Area"<<endl;
				}
			default:	
			break;
		}
	}
	system("cls");
	
	if(bitir==1)
	{
		cout<<"Total Score = "<<puan<<endl;
		cout<<"Game Over. Press A to watch steps"<<endl;
	}
	else
	{
		cout<<"Exit"<<endl;
		return 0;
	}
		
	
	c=getch();
	while(c=='a')
	{
		
		queue=dequeue(queue);	
		if(cikan=='u')
				cout<<"    one unit up "<<"Coordinate --> "<<qx<<" - "<<qy<<endl;
		else if(cikan=='d')
				cout<<"    one unit down "<<"Coordinate --> "<<qx<<" - "<<qy<<endl;
		else if(cikan=='l')
				cout<<"    one unit left "<<"Coordinate --> "<<qx<<" - "<<qy<<endl;
		else if(cikan=='r')
				cout<<"    one unit right "<<"Coordinate --> "<<qx<<" - "<<qy<<endl;
		else if(cikan=='m')
				cout<<"            Mine "<<"Coordinate --> "<<qx<<" - "<<qy<<endl;
		else if(cikan=='e')
		{
			cout<<"That's all the moves"<<endl;
			break;
		}
			c=getch();
	
	}
	
	cout<<"Gamer Overr .. :)"<<endl;
	
	return 0;
}
