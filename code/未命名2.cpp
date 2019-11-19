#include <stdio.h>
#include <stdlib.h>
#define NoInfo 0

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
struct Qnode{
	int* Data;
	int front,rear;
	int Maxsize;
};
typedef struct Qnode* Queue;
Queue CreateQueue(int MaxSize){
	Queue Q=(Queue)malloc(sizeof(struct Qnode));
	Q->Data=(int*)malloc(sizeof(int)*M0axsize);
	Q->front=Q->rear=0;
	Q->Maxsize=Maxsize;
	return Q; 
}
bool IsFull(Queue Q){
	return ((Q->front+1)%Q->Maxsize==Q->rear);
}
bool AddQ(Queue Q,BinTree x){
	if(IsFull(Q)){
		printf("¶ÓÁÐÂú\n");
		return false;
	}
	else{
		Q->rear=(Q->rear+1)%Q->Maxsize;
		Q->rear=x;
		return true;
	}
}
bool IsEmpty(Queue Q){
	return (Q->front==Q->rear);
}
Queue DeleteQ(Queue Q){
	if(IsEmpty(Q)){
		printf("duilie¿Õ\n");
		return NULL;
	}
	else{
		Q->front=(Q->front+1)%Q->Maxsize;
		return Q->front;
	}
}

BinTree CreatBinTree(){
	int Data;
	BinTree BT,T;
	Queue Q=CreateQueue();
	scanf("%d",&Data);
	if(!Data==NoInfo){
		BT=(BinTree)malloc(sizeof(struct TNode));
		BT->Left=BT->Right=NULL;
		BT->Data=Data;
		AddQ(Q,BT);
	}
	else{
		return NULL;
	}
	
	while(!IsEmpty(Q)){
		T=Delete(Q);
		scanf("%d",&Data);
		if(Data==NoInfo){
			T->Left=NULL;
		}
		else{
			T->Left=(BinTree)malloc(sizeof(struct TNode));
			T->Left->Data=Data;
			T->Left->Left=T->Left->Right=NULL;
			AddQ(Q,T->Left);
		}
		
		scanf("%d",&Data);
		if(Data==NoInfo){
			T->Right=NULL;
		}
		else{
			T->Right=(BinTree)malloc(sizeof(struct TNode));
			T->Right->Data=Data;
			T->Right->Left=T->Right->Right=NULL;
			AddQ(Q,T->Right);
		}
	}
	return BT;
}
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}






