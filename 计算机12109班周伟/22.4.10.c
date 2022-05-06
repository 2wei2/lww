#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 500
#define STACK_SIZE 30
 
 
/// 
//定义队列的结构体
typedef struct Squeue{
	int data[MAXSIZE];//队列内元素的最大长度
	int front;//队头
	int rear;//队尾
}Squeue;
 
//定义栈（顺序栈）的结构体 
typedef struct{
    char *base;
    char *top;  //栈顶指针
    int size;
}seqStack;
int InitStack(seqStack *s){
    s->base = (int *)malloc(STACK_SIZE* sizeof(seqStack));//动态分配30个单位的stack
    //省略是否空间满
    s->top = s->base;//栈顶和栈尾相同，栈里面没有元素
    s->size = STACK_SIZE;
    return 1;
}
int Push(seqStack *s,int x){
 
    *s->top = x;
    s->top++;
    return 1;
}
 
int Pop(seqStack *s,char *x){
    if(s->top == s->base)return 0;
    else{
        s->top--;
        *x = *s->top;
        return 1;
    }
}
int GetTop(seqStack *s, int *x){
    if(s->top==s->base)
		return 0;
    else{
        *x=*(s->top-1);
        return 1;
    }
}//初始化队列
void InitQueue(Squeue *Q)
{
	Q->front = Q->rear = 0;
}
 
//判断队列是否为空
int isQueueEmpty(Squeue *qu)
{
	if(qu->front == qu->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
 
//元素入队操作
int EnQueue(Squeue *qu,int x)
{
	//若队满则无法入队——当前个数已经超过最大数量，
	//就会出现mod（Maxsize）的结果是队头指针
	//比如，队头是1，最大长度是12，若入队第13个元素，则会出现13mod12==1（和队头相等）的情况
	//这样就会return false 
	if((qu->rear + 1) % MAXSIZE == qu->front)
	{
		return 0;
	}
	qu->rear = (qu->rear + 1) % MAXSIZE;
	qu->data[qu->rear] = x;
	return 1;
}
 
//元素出队操作
int deQueue(Squeue *qu,int *x)
{
	//若队空则无法出队
	if(qu->front == qu->rear)
	{
		return 0;
	}
	qu->front = (qu->front + 1) % MAXSIZE;
	*x = qu->data[qu->front];
	return 1;
}

int judge(char n[]);
int main()
{
	char n[30];
	scanf("%s",n);
    if(judge(n))
    {
    	printf("符合！");
	}
	else
	{
		printf("不符合！");
	}
	
	
	//InitQueue(&q);
 

	return 0;
}

int judge(char n[])
{
	int i;
	seqStack s;
    InitStack(&s);
	int x=strlen(n);
	char wei;
	for(i=0;i<n;i++)
	{
		if(n[i]!='&'&&i<=(n-1)/2) 
		{
			push(&s,n[i]);
		}
		else
		{
			pop(&s,&wei);
			if(n[i]!=wei)
			{
				return 0;
			}	
		}
	
	}
	
}
