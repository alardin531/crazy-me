#include<stdio.h>
#include<stdlib.h>
struct student{
	int data;
	struct student * next;
}; 
struct student * create(int n){
	struct student *head,*p1,*p2;
	p1=p2=(struct student *)malloc(sizeof(struct student));
	p1->next=NULL;
	p2->next=NULL;
	for(int i=1;i<=n;i++){
		if(i==1){
			scanf("%d",&p1->data);
			head=p1;
			p2=p1;
		}
		else{
			p1=(struct student *)malloc(sizeof(struct student));
			scanf("%d",&p1->data);
			p2->next=p1;
			p2=p1;
		}
	}
	p2->next=NULL;
		return head;
}
int main(){
	struct student*h,*m;
	int n;
	scanf("%d",&n);
	h=m=create(n);
	for(int i=0;i<n;i++){
		if(i==n-1){
			printf("%d",m->data);
		}
		else{
			printf("%d ",m->data);
		}
		m=m->next;
	}
	printf("%d",n); 
	return 0;
}

