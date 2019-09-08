#include <stdio.h>
#include <stdlib.h>
struct student{
    int a;
    struct student * next;
};
struct student * create(int n){
    struct student *p1,*p2,*head;
    p1=p2=(struct student *)malloc(sizeof(struct student));
    p1->next=NULL;
    p2->next=NULL;
    for(int i=1;i<=n;i++){
        if(i==1){
            scanf("%d",&p1->a);
            head=p1;
            p2=p1;
        }
        else{
            p1=(struct student *)malloc(sizeof(struct student));
            scanf("%d",&p1->a);
            p2->next=p1;
            p2=p1;
        }
    }
    p2->next=NULL;
    return (head);
}
int main (){
    struct student *head,*p;
    int n;
    scanf("%d",&n);
    head=p=create(n);
    for(int i=1;i<=n;i++){
        if(i!=n){
        	printf("%d ",p->a);
		}
		else{
			printf("%d",p->a);
		}
        p=p->next;
    }
    return 0;
}

