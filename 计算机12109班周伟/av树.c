#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct avnode *position;
typedef struct avnode *avtree;


int Height(position P)
{
	if(P==NULL)
		return -1;
	else
		return P->height;
}

struct avnode
{
	int a;
	avtree left;
	avtree right;
	int height;
}

avtree insert(int x,avtree T)
{
	if(T==NULL)
	{
		T=malloc(sizeof(struct avtree));
		T->a=x; T->height=0;
		T->left=T->right=NULL;
		
	}
	else
	if(x<T->a)
	{
		T->left=insert(T->left);
		if(Height(T->left)-Height(T->right)==2)
			if(x<T->left->a)
			T=sl(T);
			else
			T=dl(T);
	}
	else
	if(x>T->a)
	{
		T->right=insert(x,T->right);
		if(Height(T->right)-Height(T->left)==2)
			if(x>T->right->a)
			T=sr(T);
		else
			T=dr(T); 
	}
	
	T->height=Max(Height(T->left),Height(T->right))+1;
	 
	return T;
}

position sl(position k2)
{
	position k1;
	k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2->height=Max(Height(k2->left),Height(k2->right))+1;
	k1->height=Max(Height(k1->left),k2->height)+1;
	
	return k1;
}

position dl(position k3)
{
	k3->left=sr(k3->left);
	
	return sl(k3);
}

pisition sr(position k2)
{
	position k1;
	k1=k2->right;
	k2->right=k1->left;
	k1->left=k2;
	k2->height=Max(Height(k2->left),Height(k2->right))+1;
	k1->height=Max(Height(k1->right,k2->height))+1;
	
	return k1;
	
}

position dr(position k3)
{
	
	k3->right=sl(k3->right)
	
	return sr(k3);
	
}


int main(void)
{
	printf("wei");
	
	return 0;
}
