#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ERROR 1e8
enum operation{pop,push,end};
typedef int elementtype;
struct snode{
	int maxsize;
	int top1,top2;
	int *data;
}; 
typedef struct snode* stack;
stack createstack(int maxsize){
	stack s=(stack)malloc(sizeof(struct snode));
	s->data=(int*)malloc(maxsize*sizeof(int));
	s->maxsize=maxsize;
	s->top1=-1;
	s->top2=maxsize;
	return s;
}
bool Push(stack s,int x,int tag){
	if(s==NULL) return false;
		if(s->top1+1==s->top2){
		printf("stack full\n");
		return false;
	    }
	if(tag==1){
		s->data[--s->top1]=x;
	}
	else s->data[++s->top2]=x;
	return true;
}
elementtype Pop(stack s,int tag){
	if(s==NULL) return ERROR;
	if(tag==1){
		if(s->top1==-1){
			printf("stack %d is empty\n",tag);
			return ERROR;
		}
		else{
			return s->data[s->top1--];
		}
	}
	if(tag==2){
		if(s->top2==s->maxsize){
			printf("stack %d is empty\n");
			return ERROR;
		}
		else{
			return s->data[s->top2++];
		}
	}
}
operation getop(){
	char a[10];
	scanf("%s",&a);
	if(strcmp(a,"push")==0){
		return push;
	}
	if(strcmp(a,"pop")==0){
		return pop;
	}
	if(strcmp(a,"end")==0){
		return end;
	}
} 
void printstack(stack s,int tag){
	printf("ohh,I'm here\n");
	if(tag==1){
		printf("inside stack 1: \n");
		for(int i=s->top1;i>=0;i--){
			printf("%d ",s->data[s->top1]);
			s->top1--;
		}
	}
	if(tag==2){
		printf("inside stack 2 : \n");
		for(int i=s->top2;i<s->maxsize;i++){
			printf("%d ",s->data[s->top2]);
			s->top2++;
		}
	}
}
int main(){
	int maxsize,tag=0,x=0;
	scanf("%d",&maxsize);
	stack s=createstack(maxsize);
	int done=0;
	while(done!=1){
		switch (getop()){
		case push:{
			printf("i'm here\n");
			scanf("%d %d",&tag,&x);
			if(!Push(s,tag,x)) printf("stack %d is full",tag);
			
		}
		break;
		case pop:{printf("i'm here\n");
			scanf("%d",tag);
			x=Pop(s,tag);
			if(x==ERROR){
				printf("stack %d is empty",tag);
			}
		}
		break;
		case end:{printf("i'm here\n");
			printstack(s,1);
			printstack(s,2);
			done=1;
		}
		break;
	}
}
	
	return 0;
}
