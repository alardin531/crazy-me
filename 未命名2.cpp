#include<stdio.h>
#include<stdlib.h>
//定义单链表 
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
//1.栈的初始化 
Node * InitStack()
{
	Node * p;
	p=(Node *) malloc(sizeof(Node));
	p->next=NULL;
	return p;
}
//2.入栈操作 
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
//3.判空操作
int Empty(Node *top)
{
	return top->next==NULL;
 } 
//4.出栈操作 
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
//5.取栈顶元素 
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
 	
	Node *top,*p;//定义链栈的栈顶指针并初始化 
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
