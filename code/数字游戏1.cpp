#include<stdio.h>
#include<math.h>
void guess(int a){
	printf("\t\t\t\t欢迎使用2019款猜数字！\n\n\n");
	printf("\t\t\t\t您的随机数生成中。。。。\n\n\n\n");
	int key=a*2*8/3+11-33;
	printf("\t\t\t\t您的随机数生成完毕！\n\n\n");
	int g;
	printf("\t\t\t\t请输入您的猜测：\n");
	scanf("%d",&g);
	while(g!=key){
		if(g-key>0){
			if(g-key>10000){
				printf("数量级差的太远了！！\n");
			}
			else if(g-key>1000&&g-key<=10000){
				printf("差距在1000以上！\n");
			}
			else if(g-key>100&&g-key<=1000){
				printf("古有吕布辕门射戟，近有同学百步猜数\n");
			}
			else if(g-key>10&&g-key<=100){
				printf("您的准星已经开始工作了！\n");
			}
			else if(g-key>1&&g-key<=10){
				printf("您就快猜对了！不要放弃\n");
			}
		}
		else{
			int k=key-g;
			if(k>10000){
				printf("数量级差的太远了！！\n");
			}
			else if(k>1000&&k<=10000){
				printf("差距在1000以上！\n");
			}
			else if(k>100&&k<=1000){
				printf("古有吕布辕门射戟，近有同学百步猜数\n");
			}
			else if(k>50&&k<=100){
				printf("您的准星已经开始工作了！\n");
			}
			else if(k>10&&k<=50){
				printf("准星状态渐佳！\n");
			}
			else if(k>=1&&k<=10){
				printf("您就快猜对了！不要放弃\n");
			}
		}
		scanf("%d",&g);
	}
	printf("恭喜恭喜！总算猜对了!\n\n");
}
int main(){
	
	printf("\n\n\t\t\t\t\t下面将进入简易游戏世界！\n\n\t\t\t\t\tPowered by WangHe\n\t\t\t\t\t2019 all rights reserved.\n\n");
	int a,b,c,d,n;
	printf("\t\t\t\t\t请选择您需要的游戏：\n\n\n\t\t\t\t\t1.猜数字\n");
	scanf("%d",&n);
	switch (n){
		case 1:{
			printf("请随便输入一个幸运数字：");
			scanf("%d",&a);
			guess(a);
			break;
		}
		default :{
			printf("\n\n\t\t\t其他游戏正在开发中@-@\n");
			break;
		}
	}
	return 0;
}
