#include <stdio.h>
#include <stdlib.h>//malloc函数

struct Node {    //链表结点
    int data;    //数据
    struct Node* link;    //指向下一个结点的指针
};
/* 尾插法建立单链表：返回单链表的头指针 */
struct Node* buildLinkedList(int* arr, int n); /* 尾插法建立单链表 */
void printLinkedList(struct Node* head);       /* 打印链表 */
int main(int argc, char const *argv[]) {
    int n, i;
    int* a;
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));	//动态内存分配申请数组空间
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    struct Node* head = NULL;	//声明一个指针变量head
    //创建链表，把返回的头指针赋值给head指针变量
    head = buildLinkedList(a, n);
    //打印链表：整个链表用head来代表。
    printLinkedList(head);
    free(a);	//释放存储空间
    return 0;
}
struct Node* buildLinkedList(int* arr, int n){
	struct Node *head,*p1,*p2;
	p1=p2=(struct Node*)malloc(sizeof(struct Node));
	p1->link=NULL;
	p2->link=NULL;
	for(int i=0;i<n;i++){
		if(i==0){
			p1->data=arr[i];
			head=p1;
			p2=p1;
		}
		else{
			p1=(struct Node*)malloc(sizeof(struct Node));
			p1->data=arr[i];
			p2->link=p1;
			p2=p1;
		}	
	}
	p2->link=NULL;
	return head;
}
void printLinkedList(struct Node* head){
	struct Node *q,*m;
	q=head;
	m=head;
	int n=0;
	while(q!=NULL){
		n++;
		q=q->link;
	}
	for(int i=1;i<=n;i++){
		if(i==n){
			printf("%d",m->data);
		}
		else{
			printf("%d ",m->data);
		}
		m=m->link;
	}
}
