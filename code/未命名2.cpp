#include<stdio.h>
#include<math.h>
void guess(int a){
	printf("\t\t\t\t��ӭʹ��2019������֣�\n\n\n");
	printf("\t\t\t\t��������������С�������\n\n\n\n");
	int key=a*2*8/3+11-33;
	printf("\t\t\t\t���������������ϣ�\n\n\n");
	int g;
	printf("\t\t\t\t���������Ĳ²⣺\n");
	scanf("%d",&g);
	while(g!=key){
		if(g-key>0){
			if(g-key>10000){
				printf("���������̫Զ�ˣ���\n");
			}
			else if(g-key>1000&&g-key<=10000){
				printf("�����1000���ϣ�\n");
			}
			else if(g-key>100&&g-key<=1000){
				printf("��������ԯ����ꪣ�����ͬѧ�ٲ�����\n");
			}
			else if(g-key>10&&g-key<=100){
				printf("����׼���Ѿ���ʼ�����ˣ�\n");
			}
			else if(g-key>1&&g-key<=10){
				printf("���Ϳ�¶��ˣ���Ҫ����\n");
			}
		}
		else{
			int k=key-g;
			if(k>10000){
				printf("���������̫Զ�ˣ���\n");
			}
			else if(k>1000&&k<=10000){
				printf("�����1000���ϣ�\n");
			}
			else if(k>100&&k<=1000){
				printf("��������ԯ����ꪣ�����ͬѧ�ٲ�����\n");
			}
			else if(k>50&&k<=100){
				printf("����׼���Ѿ���ʼ�����ˣ�\n");
			}
			else if(k>10&&k<=50){
				printf("׼��״̬���ѣ�\n");
			}
			else if(k>=1&&k<=10){
				printf("���Ϳ�¶��ˣ���Ҫ����\n");
			}
		}
		scanf("%d",&g);
	}
	printf("��ϲ��ϲ������¶���!\n\n");
}
int main(){
	
	printf("\n\n\t\t\t\t\t���潫���������Ϸ���磡\n\n\t\t\t\t\tPowered by WangHe\n\t\t\t\t\t2019 all rights reserved.\n\n");
	int a,b,c,d,n;
	printf("\t\t\t\t\t��ѡ������Ҫ����Ϸ��\n\n\n\t\t\t\t\t1.������\n");
	scanf("%d",&n);
	switch (n){
		case 1:{
			printf("���������һ���������֣�");
			scanf("%d",&a);
			guess(a);
			break;
		}
		default :{
			printf("\n\n\t\t\t������Ϸ���ڿ�����@-@\n");
			break;
		}
	}
	return 0;
}
