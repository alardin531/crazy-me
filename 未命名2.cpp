#include <stdio.h>
#include <stdlib.h>//malloc����

struct Node {    //������
    int data;    //����
    struct Node* link;    //ָ����һ������ָ��
};
/* ͷ�巨�������������ص������ͷָ�� */
struct Node* buildLinkedList(int* arr, int n);    /* ͷ�巨���������� */
void printLinkedList(struct Node* head);          /* ��ӡ���� */
int main(int argc, char const *argv[]) {
    int n, i;
    int* a;
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));    //��̬�ڴ������������ռ�
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    struct Node* head = NULL;    //����һ��ָ�����head
    //���������ѷ��ص�ͷָ�븳ֵ��headָ�����
    head = buildLinkedList(a, n);
    //��ӡ��������������head������
    printLinkedList(head);
    free(a);    //�ͷŴ洢�ռ�
    return 0;
}
struct Node* buildLinkedList(int* arr, int n){
	struct Node *head,*p1,*p2;
	head=(struct Node*)malloc(sizeof(struct Node));
	head->link=NULL;
	for(int i=0;i<n;i++){
		p1=(struct Node *)malloc(sizeof(struct Node));
		p1->data=arr[i];
		p1->link=head->link;
		head->link=p1;
	}
	p2=head->link;
	return p2;
}
void printLinkedList(struct Node* head){
	struct Node*w,*e;
	int n=0;
	w=head;
	e=head;
	while(w!=NULL){
		n++;
		w=w->link;
	}
	for(int i=0;i<n;i++){
		if(i==n-1){
			printf("%d",e->data);
		}
		else{
			printf("%d ",e->data);
		}
		e=e->link;
	}
}












