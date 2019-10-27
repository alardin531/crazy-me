#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define ERROR 1e8
typedef int ElementType;
enum  Operation{push,pop,end};
//typedef enum { false, true } bool;
typedef int Position;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;
Stack CreateStack(int MaxSize)
{
    Stack stack = (Stack)malloc(sizeof(struct SNode));
    stack->Data = (int *)malloc(sizeof(ElementType)* MaxSize);
    stack->Top1 = -1;
    stack->Top2 = MaxSize;
    stack->MaxSize = MaxSize;
    return stack;
}
bool Push(Stack S, ElementType X, int Tag)
{
    if (S == NULL)return false;
    if (S->Top1+1==S->Top2){
        printf("Stack Full\n");
        return false;
    }

    if (Tag == 1)
        S->Data[++S->Top1] = X;
     else S->Data[--S->Top2] = X;
     return true;
}
ElementType Pop(Stack S, int Tag)
{
    if (S == NULL)return ERROR;
    if (Tag == 1){
        if (S->Top1 == -1)
        {
            printf("Stack %d Empty\n",Tag);
            return ERROR;
        }
        return S->Data[S->Top1--];
    }
    
    if (S->Top2 == S->MaxSize)
    {
        printf("Stack %d Empty\n", Tag);
        return ERROR;
    }
    return S->Data[S->Top2++];
    
    
}

Operation GetOp(){
	char s[10];
	scanf("%s",&s);
    if(strcmp(s,"push")==0){
    	return push;
	}
	if(strcmp(s,"pop")==0){
		return pop;
	}
	if(strcmp(s,"end")==0){
		return end;
	}
}
void PrintStack(Stack S,int Tag){
	if(Tag==1){
		printf("pop from stack 1:\n");
		for(int i=S->Top1;i>=0;i--){
			printf("%d\n",S->Data[S->Top1]);
			S->Top1--;
		}
	}
	if(Tag==2){
		printf("pop from stack 2:\n");
		for(int i=S->Top2;i<S->MaxSize;i++){
			printf("%d\n",S->Data[S->Top2]);
			S->Top2++;
		}
	}
}

int main()
{
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
            {
			scanf("%d %d", &Tag, &X);
            if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);}
            break;
        case pop:
            {
			scanf("%d", &Tag);
            X = Pop(S, Tag);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Tag);}
            break;
        case end:
            {
			PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
			}
            break;
        }
    }
    return 0;
}

