#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef struct Node
  {
    int data;
    struct Node * LChild;
    struct Node * RChild;
  }
  BiTNode, *BiTree;
  
  void CreateBiTree(BiTree *bt)
{ 
  int ch;
  scanf("%d",&ch);
  if(ch==0) 
    *bt=NULL;
  else
    {
      *bt=(BiTree)malloc(sizeof(BiTNode));
      (*bt)->data=ch;
      CreateBiTree(&((*bt)->LChild));
      CreateBiTree(&((*bt)->RChild));
    }
} 
 

void PrintTree(BiTree bt, int nLayer)  /* 按竖向树状打印的二叉树 */
{
  if(bt ==NULL) 
    return;
  PrintTree(bt ->RChild,  nLayer+1);
  for(int i=0;i<nLayer;i++)
  {
     printf("   ");  
  }
  printf("%d\n",bt->data);
    
  PrintTree(bt ->LChild ,  nLayer+1);
} 


char pathdata[100];
int pathlevel[100];
 
int k=0;



int main()
{
    struct Node BiTNode,*bt;
    bt=&BiTNode;
    CreateBiTree(&bt);
    PrintTree(bt, 1);
    
  
    return 0;
}

//1 2 3 4 5 0 0 6 0 0 0 7 0 8 0 0 9 10 0 0 11 0 12 0 0
