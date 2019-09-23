#include <stdio.h>
#include <stdlib.h>//malloc����

struct Node {    //������
    int data;    //����
    struct Node* link;    //ָ����һ������ָ��
};
/* β�巨�������������ص������ͷָ�� */
struct Node* buildLinkedList(int* arr, int n); /* β�巨���������� */
void printLinkedList(struct Node* head);       /* ��ӡ���� */
int main(int argc, char const *argv[]) {
    int n, i;
    int* a;
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));	//��̬�ڴ������������ռ�
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    struct Node* head = NULL;	//����һ��ָ�����head
    //���������ѷ��ص�ͷָ�븳ֵ��headָ�����
    head = buildLinkedList(a, n);
    //��ӡ��������������head������
    printLinkedList(head);
    free(a);	//�ͷŴ洢�ռ�
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
