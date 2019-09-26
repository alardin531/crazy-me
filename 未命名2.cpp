#include<stdio.h>
#include<stdlib.h>
//���嵥���� 
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
//1.ջ�ĳ�ʼ�� 
Node * InitStack()
{
	Node * p;
	p=(Node *) malloc(sizeof(Node));
	p->next=NULL;
	return p;
}
//2.��ջ���� 
int Push(Node *top,ElemType x)
{
	 Node * p;
	 p=(Node *) malloc(sizeof(Node));
	 p->data=x;
	 if(p==NULL)
	   return 0;
	 else
	 {
	 	p->next=top->next;
	 	top->next=p;
	 	
	 	return 1;
	 }
} 
//3.�пղ���
int Empty(Node *top)
{
	return top->next==NULL;
 } 
//4.��ջ���� 
int Pop(Node *top,ElemType *ptr)
{
	Node * p;
	if(Empty(top))
	  return 0;
	p=top->next;
	top->next=p->next;
	*ptr=p->data;
	free(p);
	return 1;
} 
//5.ȡջ��Ԫ�� 
int GetTop(Node *top,ElemType *ptr)
{
    Node * p;
	if(Empty(top))
	  return 0;
	p=top->next;
	*ptr=p->data;
	return 1;
}
int main()
{
 	ElemType x,*ptr;
 	int i;
 	
	Node *top,*p;//������ջ��ջ��ָ�벢��ʼ�� 
	top=InitStack();
	Push(top,10);
	Push(top,300);
	Push(top,20);
	
	printf("*********\n");
	p=top->next;
	while(p)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	
	printf("*********\n");
	if(Pop(top,&x))
	  printf("%d\n",x);
	
	printf("*********\n");  
	p=top->next;
	while(p)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	return 0;
}
