#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

#define max 12
#define stack 30

typedef struct{
	int data[max];
	int front;
	int rear;
}Sequeue;

typedef struct{
	int size;
	char *top;
	char *tail;
}Stack;

int Inite(Stack *s)
{
	s->tail=(int *)malloc(stack*sizeof(Stack));
	s->top=s->tail; 
	s->size=stack;
	return 1;
}

int Push(Stack *s,char x)
{
	*s->top=x;
	 s->top++;
	return 1;
}

int Pop(Stack *s,char *x)
{
	if(s->top==s->tail) return 0;
	else
	{
		 s->top--;
		*x=*s->top;
		return 1;
	
	}
}

int gettop(Stack *s,char *x)
{
	if(s->top==s->tail) return 0;
	else
	{
		*x=*(s->top-1);
		return 1;
	}
}

int IniteS(Sequeue *s)
{
	s->rear=s->front=0;
	return 1;
}

int isempty(Sequeue *s)
{
	if(s->rear==s->front)
	{
		return 1;
	}
	else
	return 0;
}

int in(Sequeue *s,int x)
{
	if((s->rear+1)%max==s->front)
	{
		return 0;
	}
	s->rear=(s->rear+1)%max;
	s->data[s->rear]=x;
	
	return 1;
}

int out(Sequeue *s,int *x)
{
	if(s->rear==s->front)
	{
		return 0;
	}
	
	s->front=(s->front+1)%max;
	*x=s->data[s->front];
	
	return 1;
	
}

int getmin(Stack s)
{
	int wei;
	gettop(&s,&wei);
	int i;
	int wen;
	for(i=0;i<5;i++)
	{
		Pop(&s,&wen);
		if(wen<wei)
		{
			wei=wen;
		}
	}
	
	return wei;
}


int main(void)
{
	int lu=1;
	Stack a;
	Inite(&a);
	Stack c;
	Inite(&c);
	Sequeue b;
	IniteS(&b);
	int i;
	int n;
	char ch;
	char wh;
	char wei[50];
	char wen[50];
	gets(wei);
	//getchar();
	gets(wen);
	int num1=0;
	int num2=0;
	for(i=0;i<strlen(wei);i++)
	{
		if(wei[i]!='#')
		{
			Push(&a,wei[i]);
			num1++;
		}else
		{
			Pop(&a,&ch);
			num1--;
		}
		
	}	
	
	for(i=0;i<strlen(wen);i++)
	{
		if(wen[i]!='#')
		{
			Push(&c,wen[i]);
			num2++;
		}else
		{
			Pop(&c,&ch);
			num2--;
		}
	}
	

	
	if(num1!=num2)
	{
		lu=0;
	}else
	{
		for(i=0;i<num1;i++)
		{
			Pop(&a,&ch);
			Pop(&c,&wh);
			if(ch!=wh)
			{
				lu=0;
			}
			
		}
	}
	
	if(lu)
	{
		printf("correct");
	}else
	{
		printf("false");
	}
	
	
	return 0;
}
