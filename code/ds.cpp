#include<stdio.h>
#include<math.h>
#include <process.h>
#define N 20          /*学校最大数目*/ 
#define M 20          /*男子项目最大数目*/ 
#define W 20          /*女子项目最大数目*/
typedef struct
{ 
	int inum;       /*项目编号*/
    int tnum;           /*取名次的数目*/
    int range[5];      /*名次*/
    int mark[5];       /*分数*/
}itemnode;             /*存放项目信息*/
typedef struct   
{
	int snum;     /*学校编号*/
    int score;         /*学校总分*/
    int mscore;        /*男团总分*/
    int wscore;        /*女团总分*/
    itemnode t[M+W]; /*项目数组*/
}snode;             /*学校信息*/
snode a[N];        /* 学校数组*/
void  menu(int n,int m,int w)   /*菜单函数*/        
{ 
	int c;
    void input(int n,int m,int w);
	void output(int n,int m,int w);
	void sortput(int n,int m,int w);
	void search(int n,int m,int w);
	printf("\t\t\t即将带您进入\t\t\t\t\n\n");   
	printf("\t*          运动会分数表格           \n\n");
    printf("\t\t       1.信息输入       \n");
    printf("\t\t       2.统计输出       \n");
    printf("\t\t       3.排序输出       \n");
    printf("\t\t       4.信息查询       \n");
    printf("\t\t       0.退出系统       \n\n");
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	printf("您想执行哪一步:<0-4>");
    scanf("%d",&c);
	switch(c)         
	{ 
	case 1: 
		input(n,m,w);break;
    case 2: 
		output(n,m,w);break;
    case 3: 
		sortput(n,m,w);break;
    case 4: 
		search(n,m,w);break;
    case 0:
		printf("谢谢使用,下次再见!\n");
        exit(0);
    default: 
		printf("输入不在项目范围内\n");
		menu(n,m,w);
    }
}
void savetofile()                                  /*信息存入文件file*/
{
	FILE *fp;
    int i;
    if((fp=fopen("file.txt","w"))==NULL)
    {
		printf("cannot open the file\n");
		return;
    }
    for(i=0;i<N;i++)
    {
		if(a[i].snum!='\0')
			if(fwrite(&a[i],sizeof(snode),1,fp)!=1)
			{
				printf("file write error\n");
				return;
			}
    }
    fclose(fp);
}
void readfromfile()    /*信息从文件file中取出*/
{
    int i;
	FILE *fp;
    if((fp=fopen("file.txt","rb"))==NULL)
    {
		printf("cannot open the file\n");
		return;
    }
    for(i=0;i<N;i++)
		fread(&a[i],sizeof(snode),1,fp);
    fclose(fp);
}

void input(int n,int m,int w)                             /*1.信息输入*/
{
	int i,j,s,k,q=0;
    for(i=0;i<n;i++)
    { 
		printf("学校编号:");
        scanf("%d",&a[i].snum); /*输入学校信息*/
        for(j=0;j<m+w;j++)
		{  
			printf("项目编号:");
            scanf("%d",&a[i].t[j].inum);
			printf("项目取前3名或前5名(3或者5):");
            scanf("%d",&a[i].t[j].tnum);
			if(a[i].t[j].tnum==3)
				printf("获名次个数(1--3)：");
			else
				printf("获名次个数(1--5)：");
            scanf("%d",&k);   /*输入项目信息*/
            for(s=0;s<k;s++)
			{   
				if(a[i].t[j].tnum==3)
					printf("名次(1--3):");
				else
					printf("名次(1--5):");
                scanf("%d",&a[i].t[j].range[s]); /*输入所获名次信息*/
           	}
			printf("\n");
        }
    }
    for(i=0;i<n;i++)
    { 
		a[i].score=0;
        a[i].mscore=0;
        a[i].wscore=0;
	}                   /*初始化分数*/
	for(i=0;i<n;i++)
		for(j=0;j<m+w;j++)
			for(s=0;s<5;s++)
			{  
				if(a[i].t[j].tnum==3)
					switch(a[i].t[j].range[s])
				{
             case 0: a[i].t[j].mark[s]=0; break;
             case 1: a[i].t[j].mark[s]=5; break;
             case 2: a[i].t[j].mark[s]=3; break;
             case 3: a[i].t[j].mark[s]=2; break;
				}
				else if(a[i].t[j].tnum==5)
					switch(a[i].t[j].range[s])
				{
             case 0: a[i].t[j].mark[s]=0; break;
             case 1: a[i].t[j].mark[s]=7; break;
             case 2: a[i].t[j].mark[s]=5; break;
             case 3: a[i].t[j].mark[s]=3; break;
             case 4: a[i].t[j].mark[s]=2; break;
             case 5: a[i].t[j].mark[s]=1; break;
				}
				else 
				{
					printf("信息错误!");
					printf("\n");
					exit(0);
				}
				a[i].score=a[i].score+a[i].t[j].mark[s];   /*记学校总分*/
				if(j<=m-1)
				a[i].mscore=a[i].mscore+a[i].t[j].mark[s];  /*记男子团体总分*/
				else
				a[i].wscore=a[i].wscore+a[i].t[j].mark[s];  /*记女子团体总分*/
			}		
			printf("输入完毕，是（1）否（2）返回？\n");   /*返回菜单*/
			scanf("%d",&q);
			printf("\n");
			if(q!=1)
				printf("不能再添加信息!");
			printf("\n");
			savetofile();          /*将信息存入文件file*/
			menu(n,m,w);
}
void output(int n,int m,int w)                                /*2.统计输出*/
{
    readfromfile();
	int i,j,s,q=0; 
    for(i=0;i<n;i++)  /*显示结果*/
	{
		printf("学校编号:%d  学校总分:%d  男团总分:%d  女团总分:%d\n",a[i].snum,a[i].score,a[i].mscore,a[i].wscore);
        for(j=0;j<m+w;j++)
		{
			printf("项目编号:%d  所取名次数量:%d\n",a[i].t[j].inum,a[i].t[j].tnum);
			for(s=0;s<5;s++)
			{
                if(a[i].t[j].range[s]!=0)
				printf("名次:%d  分数:%d\n",a[i].t[j].range[s],a[i].t[j].mark[s]);
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("统计完毕!返回?  1是 2否");    /*返回菜单*/
	scanf("%d",&q);
	printf("\n");
	if(q!=1)
		printf("统计结束");
	printf("\n");
    menu(n,m,w);
}
void sortput(int n,int m,int w)                                /*3.排序输出*/ 
{
	readfromfile();
	int c,i,j,k,q=0;
	int temp[N];
    printf("\t            排序输出系统              \n\n");
    printf("\t\t    1.按学校编号输出    \n");
    printf("\t\t    2.按学校总分输出    \n");
    printf("\t\t    3.按男团总分输出    \n");
    printf("\t\t    4.按女团总分输出    \n");
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	do
	{
        printf("您想执行哪一步？(1--4):");
        scanf("%d",&c);
		switch(c)
		{
		case 1: 
			for(i=0;i<n;i++)
				temp[i]=i;
            for(i=0;i<n;i++)
            { 
				for(j=i+1;j<n;j++)
					if(a[temp[i]].snum>a[j].snum)
					{ 
						k=temp[i];
                        temp[i]=temp[j];
                        temp[j]=k;
					}
            }              /* 冒泡排序*/
            for(i=0;i<n;i++)
            {
				printf("学校编号:%d  学校总分:%d  男团总分:%d  女团总分:%d\n",a[temp[i]].snum,a[temp[i]].score,a[temp[i]].mscore,a[temp[i]].wscore);
            }                                   /*按学校编号输出*/
            break;              
		case 2:   
			for(i=0;i<n;i++)
				temp[i]=i;
            for(i=0;i<n;i++)
			{ 
				for(j=i+1;j<n;j++)
					if(a[temp[i]].score<a[j].score)
					{ 
						k=temp[i];
						temp[i]=temp[j];
						temp[j]=k;
					}
			}              /* 冒泡排序*/
			for(i=0;i<n;i++)
			{
				printf("学校编号:%d  学校总分:%d  男团总分:%d  女团总分:%d\n",a[temp[i]].snum,a[temp[i]].score,a[temp[i]].mscore,a[temp[i]].wscore);
			}                                   /*按学校总分输出*/
			break;
		case 3:   
			for(i=0;i<n;i++)
				temp[i]=i;
			for(i=0;i<n;i++)
			{ 
				for(j=i+1;j<n;j++)
					if(a[temp[i]].mscore<a[j].mscore)
					{ 
						k=temp[i];
						temp[i]=temp[j];
						temp[j]=k;
					}
			}              /* 用冒泡排序方法排序*/
			for(i=0;i<n;i++)
			{
				printf("学校编号:%d  学校总分:%d  男团总分:%d  女团总分:%d\n",a[temp[i]].snum,a[temp[i]].score,a[temp[i]].mscore,a[temp[i]].wscore);
			}                                   /*按男团总分输出*/
			break;  
		case 4:   
			for(i=0;i<n;i++)
				temp[i]=i;
			for(i=0;i<n;i++)
			{ 
				for(j=i+1;j<n;j++)
					if(a[temp[i]].wscore<a[j].wscore)
					{ 
						k=temp[i];
						temp[i]=temp[j];
						temp[j]=k;
					}
			}              /* 冒泡排序*/
			for(i=0;i<n;i++)
			{
				printf("学校编号:%d  学校总分:%d  男团总分:%d  女团总分:%d\n",a[temp[i]].snum,a[temp[i]].score,a[temp[i]].mscore,a[temp[i]].wscore);
			}                                    /*按女团总分输出*/
			break; 
		default: 
			printf("输入错误,请重试!\n");	
		}
		printf("请选择  1 返回主菜单 0继续");      /*返回菜单或继续排序*/
		scanf("%d",&q);
		printf("\n");
	}
	while(q==0);
	printf("\n");
	if(q!=0)
		menu(n,m,w);
}
void search(int n,int m,int w)                  /*查询函数*/ 
{
	readfromfile();
	int c,i,j,k,d,l,q=0;
    printf("\t****************查询系统****************\n\n");
    printf("\t\t****1.按学校编号查询****\n");
    printf("\t\t****2.按项目编号查询****\n");
    printf("=======================================================\n\n");
	do
	{
        k=-1;d=-1;l=-1;
		printf("请选择要实现功能的编号(1--2):");
        scanf("%d",&c);
		switch(c)
		{
		case 1:
            printf("要查询的学校编号:");       /*查找学校编号下标*/
			scanf("%d",&c);
			for(i=0;i<n;i++)
			{
				if(a[i].snum==c)
					k=i;
			}
			if(k==-1)
				printf("错误：这个学校没有参加此次运动会!\n");
			else
			{
				printf("要查询的项目编号:");         /*查找项目编号下标*/
                scanf("%d",&c);
				for(j=0;j<m+w;j++)
				{
					if(a[k].t[j].inum==c)
						d=j;
				}
				if(d==-1)
					printf("此次运动会没有这个项目\n");
				else                                       /*显示结果*/
				{  
				printf("这个项目取前 %d名,该学校的成绩如下:\n", a[k].t[d].tnum);
					for(i=0;i<5;i++)
						if(a[k].t[d].range[i]!=0)
							printf("名次:%d\n",a[k].t[d].range[i]);
				}
			}
            break;                     
		case 2:
			printf("要查询的项目编号:");     /*查找项目编号下标*/
			scanf("%d",&c);
			for(i=0;i<n;i++)
				for(j=0;j<m+w;j++)
					if(a[i].t[j].inum==c)
						l=j;
					if(l==-1)
						printf("此次运动会没有这个项目\n");
					else                                    /*显示结果*/
					{
					printf("该项目取前 %d名,取得名次的学校\n",a[0].t[l].tnum);
						for(i=0; i<n;i++)
							for(j=0;j<5;j++)
								if(a[i].t[l].range[j]!=0)
					 printf("学校编号:%d,名次:%d\n",a[i].snum,a[i].t[l].range[j]); 
					}
					break;
		default: 
			printf("输入错误,请重试!\n");
		}
		printf("请选择:1.返回主菜单 0.继续");     /*返回菜单或继续查询*/
		scanf("%d",&q);
		printf("\n");
	}
	while(q==0);
	printf("\n");
    if(q!=0)
		menu(n,m,w);
}
int main()   
{ 
    int n,m,w;
    printf("\t\t\t\t欢迎使用\t\t\t\t\t\n\n");   
	printf("\t\t           运动会分数统计系统           \n\n\t\t\tPowered by Wanghe 20181102934\n\n");
	printf("请先输入运动会主要信息\n");        /*设计运动会主要数据个数*/  
    printf("输入学校数量:");                       
	scanf("%d",&n);
	printf("输入男子项目个数:");
    scanf("%d",&m);
	printf("输入女子项目个数:");
    scanf("%d",&w);
	menu(n,m,w);
}

