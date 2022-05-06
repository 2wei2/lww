#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 500
#define STACK_SIZE 30
 
 
/// 
//������еĽṹ��
typedef struct {
	int data[MAXSIZE];//������Ԫ�ص���󳤶�
	int front;//��ͷ
	int rear;//��β
}Squeue;
 
//����ջ��˳��ջ���Ľṹ�� 
typedef struct{
    int *base;
    int *top;  //ջ��ָ��
    int size;
}seqStack;
int InitStack(seqStack *s){
    s->base = (int *)malloc(STACK_SIZE* sizeof(seqStack));//��̬����30����λ��stack
    //ʡ���Ƿ�ռ���
    s->top = s->base;//ջ����ջβ��ͬ��ջ����û��Ԫ��
    s->size = STACK_SIZE;
    return 1;
}
int Push(seqStack *s,int x){
 
    *s->top = x;
    s->top++;
    return 1;
}
 
int Pop(seqStack *s,int *x){
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
}//��ʼ������
void InitQueue(Squeue *Q)
{
	Q->front = Q->rear = 0;
}
 
//�ж϶����Ƿ�Ϊ��
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
 
//Ԫ����Ӳ���
int EnQueue(Squeue *qu,int x)
{
	//���������޷���ӡ�����ǰ�����Ѿ��������������
	//�ͻ����mod��Maxsize���Ľ���Ƕ�ͷָ��
	//���磬��ͷ��1����󳤶���12������ӵ�13��Ԫ�أ�������13mod12==1���Ͷ�ͷ��ȣ������
	//�����ͻ�return false 
	if((qu->rear + 1) % MAXSIZE == qu->front)
	{
		return 0;
	}
	qu->rear = (qu->rear + 1) % MAXSIZE;
	qu->data[qu->rear] = x;
	return 1;
}
 
//Ԫ�س��Ӳ���
int deQueue(Squeue *qu,int *x)
{
	//���ӿ����޷�����
	if(qu->front == qu->rear)
	{
		return 0;
	}
	qu->front = (qu->front + 1) % MAXSIZE;
	*x = qu->data[qu->front];
	return 1;
}int main()
{
	int i , n , x , a;
	scanf("%d",&n);
 
	Squeue q;
	seqStack s;
 
    InitStack(&s);
	InitQueue(&q);
 
	//˳�����ջ 
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a);
		Push(&s,a);
	}
	
	int stackNumber;
	for(i=0;i<n;i++)
    {
        Pop(&s,&stackNumber);	//����ĳ�ջ�������Ƚ����ԭ�� 
        EnQueue(&q,stackNumber);//��������  
    }
    while(!isQueueEmpty(&q))
	{
		deQueue(&q,&x);			//����ĳ��ӣ���ѭ�Ƚ��ȳ�ԭ�� 
		printf("%d ",x);		//�����ת������� 
	}
	
	return 0;
}
