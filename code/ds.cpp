#include<stdio.h>
#include<math.h>
#include <process.h>
#define N 20          /*ѧУ�����Ŀ*/ 
#define M 20          /*������Ŀ�����Ŀ*/ 
#define W 20          /*Ů����Ŀ�����Ŀ*/
typedef struct
{ 
	int inum;       /*��Ŀ���*/
    int tnum;           /*ȡ���ε���Ŀ*/
    int range[5];      /*����*/
    int mark[5];       /*����*/
}itemnode;             /*�����Ŀ��Ϣ*/
typedef struct   
{
	int snum;     /*ѧУ���*/
    int score;         /*ѧУ�ܷ�*/
    int mscore;        /*�����ܷ�*/
    int wscore;        /*Ů���ܷ�*/
    itemnode t[M+W]; /*��Ŀ����*/
}snode;             /*ѧУ��Ϣ*/
snode a[N];        /* ѧУ����*/
void  menu(int n,int m,int w)   /*�˵�����*/        
{ 
	int c;
    void input(int n,int m,int w);
	void output(int n,int m,int w);
	void sortput(int n,int m,int w);
	void search(int n,int m,int w);
	printf("\t\t\t������������\t\t\t\t\n\n");   
	printf("\t*          �˶���������           \n\n");
    printf("\t\t       1.��Ϣ����       \n");
    printf("\t\t       2.ͳ�����       \n");
    printf("\t\t       3.�������       \n");
    printf("\t\t       4.��Ϣ��ѯ       \n");
    printf("\t\t       0.�˳�ϵͳ       \n\n");
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	printf("����ִ����һ��:<0-4>");
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
		printf("ллʹ��,�´��ټ�!\n");
        exit(0);
    default: 
		printf("���벻����Ŀ��Χ��\n");
		menu(n,m,w);
    }
}
void savetofile()                                  /*��Ϣ�����ļ�file*/
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
void readfromfile()    /*��Ϣ���ļ�file��ȡ��*/
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

void input(int n,int m,int w)                             /*1.��Ϣ����*/
{
	int i,j,s,k,q=0;
    for(i=0;i<n;i++)
    { 
		printf("ѧУ���:");
        scanf("%d",&a[i].snum); /*����ѧУ��Ϣ*/
        for(j=0;j<m+w;j++)
		{  
			printf("��Ŀ���:");
            scanf("%d",&a[i].t[j].inum);
			printf("��Ŀȡǰ3����ǰ5��(3����5):");
            scanf("%d",&a[i].t[j].tnum);
			if(a[i].t[j].tnum==3)
				printf("�����θ���(1--3)��");
			else
				printf("�����θ���(1--5)��");
            scanf("%d",&k);   /*������Ŀ��Ϣ*/
            for(s=0;s<k;s++)
			{   
				if(a[i].t[j].tnum==3)
					printf("����(1--3):");
				else
					printf("����(1--5):");
                scanf("%d",&a[i].t[j].range[s]); /*��������������Ϣ*/
           	}
			printf("\n");
        }
    }
    for(i=0;i<n;i++)
    { 
		a[i].score=0;
        a[i].mscore=0;
        a[i].wscore=0;
	}                   /*��ʼ������*/
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
					printf("��Ϣ����!");
					printf("\n");
					exit(0);
				}
				a[i].score=a[i].score+a[i].t[j].mark[s];   /*��ѧУ�ܷ�*/
				if(j<=m-1)
				a[i].mscore=a[i].mscore+a[i].t[j].mark[s];  /*�����������ܷ�*/
				else
				a[i].wscore=a[i].wscore+a[i].t[j].mark[s];  /*��Ů�������ܷ�*/
			}		
			printf("������ϣ��ǣ�1����2�����أ�\n");   /*���ز˵�*/
			scanf("%d",&q);
			printf("\n");
			if(q!=1)
				printf("�����������Ϣ!");
			printf("\n");
			savetofile();          /*����Ϣ�����ļ�file*/
			menu(n,m,w);
}
void output(int n,int m,int w)                                /*2.ͳ�����*/
{
    readfromfile();
	int i,j,s,q=0; 
    for(i=0;i<n;i++)  /*��ʾ���*/
	{
		printf("ѧУ���:%d  ѧУ�ܷ�:%d  �����ܷ�:%d  Ů���ܷ�:%d\n",a[i].snum,a[i].score,a[i].mscore,a[i].wscore);
        for(j=0;j<m+w;j++)
		{
			printf("��Ŀ���:%d  ��ȡ��������:%d\n",a[i].t[j].inum,a[i].t[j].tnum);
			for(s=0;s<5;s++)
			{
                if(a[i].t[j].range[s]!=0)
				printf("����:%d  ����:%d\n",a[i].t[j].range[s],a[i].t[j].mark[s]);
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("ͳ�����!����?  1�� 2��");    /*���ز˵�*/
	scanf("%d",&q);
	printf("\n");
	if(q!=1)
		printf("ͳ�ƽ���");
	printf("\n");
    menu(n,m,w);
}
void sortput(int n,int m,int w)                                /*3.�������*/ 
{
	readfromfile();
	int c,i,j,k,q=0;
	int temp[N];
    printf("\t            �������ϵͳ              \n\n");
    printf("\t\t    1.��ѧУ������    \n");
    printf("\t\t    2.��ѧУ�ܷ����    \n");
    printf("\t\t    3.�������ܷ����    \n");
    printf("\t\t    4.��Ů���ܷ����    \n");
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	do
	{
        printf("����ִ����һ����(1--4):");
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
            }              /* ð������*/
            for(i=0;i<n;i++)
            {
				printf("ѧУ���:%d  ѧУ�ܷ�:%d  �����ܷ�:%d  Ů���ܷ�:%d\n",a[temp[i]].snum,a[temp[i]].score,a[temp[i]].mscore,a[temp[i]].wscore);
            }                                   /*��ѧУ������*/
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
			}              /* ð������*/
			for(i=0;i<n;i++)
			{
				printf("ѧУ���:%d  ѧУ�ܷ�:%d  �����ܷ�:%d  Ů���ܷ�:%d\n",a[temp[i]].snum,a[temp[i]].score,a[temp[i]].mscore,a[temp[i]].wscore);
			}                                   /*��ѧУ�ܷ����*/
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
			}              /* ��ð�����򷽷�����*/
			for(i=0;i<n;i++)
			{
				printf("ѧУ���:%d  ѧУ�ܷ�:%d  �����ܷ�:%d  Ů���ܷ�:%d\n",a[temp[i]].snum,a[temp[i]].score,a[temp[i]].mscore,a[temp[i]].wscore);
			}                                   /*�������ܷ����*/
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
			}              /* ð������*/
			for(i=0;i<n;i++)
			{
				printf("ѧУ���:%d  ѧУ�ܷ�:%d  �����ܷ�:%d  Ů���ܷ�:%d\n",a[temp[i]].snum,a[temp[i]].score,a[temp[i]].mscore,a[temp[i]].wscore);
			}                                    /*��Ů���ܷ����*/
			break; 
		default: 
			printf("�������,������!\n");	
		}
		printf("��ѡ��  1 �������˵� 0����");      /*���ز˵����������*/
		scanf("%d",&q);
		printf("\n");
	}
	while(q==0);
	printf("\n");
	if(q!=0)
		menu(n,m,w);
}
void search(int n,int m,int w)                  /*��ѯ����*/ 
{
	readfromfile();
	int c,i,j,k,d,l,q=0;
    printf("\t****************��ѯϵͳ****************\n\n");
    printf("\t\t****1.��ѧУ��Ų�ѯ****\n");
    printf("\t\t****2.����Ŀ��Ų�ѯ****\n");
    printf("=======================================================\n\n");
	do
	{
        k=-1;d=-1;l=-1;
		printf("��ѡ��Ҫʵ�ֹ��ܵı��(1--2):");
        scanf("%d",&c);
		switch(c)
		{
		case 1:
            printf("Ҫ��ѯ��ѧУ���:");       /*����ѧУ����±�*/
			scanf("%d",&c);
			for(i=0;i<n;i++)
			{
				if(a[i].snum==c)
					k=i;
			}
			if(k==-1)
				printf("�������ѧУû�вμӴ˴��˶���!\n");
			else
			{
				printf("Ҫ��ѯ����Ŀ���:");         /*������Ŀ����±�*/
                scanf("%d",&c);
				for(j=0;j<m+w;j++)
				{
					if(a[k].t[j].inum==c)
						d=j;
				}
				if(d==-1)
					printf("�˴��˶���û�������Ŀ\n");
				else                                       /*��ʾ���*/
				{  
				printf("�����Ŀȡǰ %d��,��ѧУ�ĳɼ�����:\n", a[k].t[d].tnum);
					for(i=0;i<5;i++)
						if(a[k].t[d].range[i]!=0)
							printf("����:%d\n",a[k].t[d].range[i]);
				}
			}
            break;                     
		case 2:
			printf("Ҫ��ѯ����Ŀ���:");     /*������Ŀ����±�*/
			scanf("%d",&c);
			for(i=0;i<n;i++)
				for(j=0;j<m+w;j++)
					if(a[i].t[j].inum==c)
						l=j;
					if(l==-1)
						printf("�˴��˶���û�������Ŀ\n");
					else                                    /*��ʾ���*/
					{
					printf("����Ŀȡǰ %d��,ȡ�����ε�ѧУ\n",a[0].t[l].tnum);
						for(i=0; i<n;i++)
							for(j=0;j<5;j++)
								if(a[i].t[l].range[j]!=0)
					 printf("ѧУ���:%d,����:%d\n",a[i].snum,a[i].t[l].range[j]); 
					}
					break;
		default: 
			printf("�������,������!\n");
		}
		printf("��ѡ��:1.�������˵� 0.����");     /*���ز˵��������ѯ*/
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
    printf("\t\t\t\t��ӭʹ��\t\t\t\t\t\n\n");   
	printf("\t\t           �˶������ͳ��ϵͳ           \n\n\t\t\tPowered by Wanghe 20181102934\n\n");
	printf("���������˶�����Ҫ��Ϣ\n");        /*����˶�����Ҫ���ݸ���*/  
    printf("����ѧУ����:");                       
	scanf("%d",&n);
	printf("����������Ŀ����:");
    scanf("%d",&m);
	printf("����Ů����Ŀ����:");
    scanf("%d",&w);
	menu(n,m,w);
}

