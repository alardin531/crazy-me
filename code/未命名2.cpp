#include<stdio.h>
#include<stdlib.h>
typedef int position;
typedef struct snode * ptrtosnode;
struct snode{
	int *data;
	position top;
	int maxsize;
}; 
typedef ptrtosnode stack;
stack createstack(int maxsize){
	stack s=(stack)malloc(sizeof(struct snode));
	s->data=(int *)malloc(maxsize*sizeof(int));
	s->top=-1;
	s->maxsize=maxsize;
	return s;
}
bool IsFull(stack s){
	return(s->top==s->maxsize-1);
}
bool push(stack s,int x){
	if(IsFull(s)){
		printf("¶ÑÕ»Âú£¡\n");
		return false;
	}
	else{
		s->data[++(s->top)]=x;
		return true; 
	}
} 
bool IsEmpty(stack s){
	return(s->top==-1);
}
int pop(stack s){
	if(IsEmpty(s)){
		printf("¶ÑÕ»¿Õ!\n");
		return false;
	}
	else{
		return (s->data[(s->top)--]);
	}
}
void prints(stack s,int key){
	for(int i=0;i<key;i++){
		printf("%d\n",s->data[i]);
	}
}
int main(){
	struct snode* s1;
	int key;
	scanf("%d",&key);
	s1=createstack(key);
	pop(s1);
	push(s1,1);
	push(s1,2);
	push(s1,3);
	push(s1,4);
	push(s1,5);
	push(s1,6);
	push(s1,7);
	prints(s1,key);
	return 0;
}
























