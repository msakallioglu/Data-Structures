#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 50

int stack[SIZE];
int top = -1;

void push(int x)
{
    if(top<SIZE-1)
    {
        if (top < 0)
        {
            stack[0] = x;
            top = 0;
        }
        else
        {
            stack[top+1] = x;
            top++;
        }
    }
    else
    {
        printf("Stackoverflow!!!!\n");
    }
}

int pop()
{
    int n = stack[top];
    top--;
    return n;  	
}

int Top()
{
    return stack[top];
}

void calculate(char c)
{
   int a,b,ans;       
   a=pop();                    
   b=pop();  
          
   if(c=='+')
   	ans=b+a;
   else if(c=='-')
    ans=b-a;
   else if(c=='*')
    ans=b*a;
   else if(c=='/')
    ans=b/a;
   else if(c=='^')
    ans=b^a;  
   else
    ans=0; 	 
			           
   top++;             
   stack[top]=ans;
}


int main()
{
	char c[SIZE];   
	int x;
    printf("Enter an expression = ");
	gets(c);
	for(int i=0;i<strlen(c);i++)
	{
		if(c[i]=='+' || c[i]=='-' || c[i]=='*' || c[i]=='/'|| c[i]=='^')
		{
			calculate(c[i]);			
		}
		else if(c[i]>='0' && c[i]<='9')
		{
			x=(int)(c[i]-48);
			push(x);
		}
	}
	
	printf("The result is: %d",Top());
    return 0;
}
