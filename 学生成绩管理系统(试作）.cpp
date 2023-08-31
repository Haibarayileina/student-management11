#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct student
{
	long num;
	char name[10];
	char sex[4];
	float score[3];
	float average;
	student *next;
}student;
void menu(void);
void input(student*head);
void output(student*head);
void delete_(student*head);
void find(student*head);
void change(student*head);
void rank_num(student*head);
void rank_score(student*head);
void sta_(student*head);
void insert(student*head);
void listhead(student*p);
int main()
{	
    student *head=(student*)malloc(sizeof(student));
    head->next=NULL;
	int n;
	while(1)
	{
		menu();
		scanf("%d",&n);
		system("cls");
		switch(n)
		{
			case 0:break;
			case 1:input(head);break;
			case 2:delete_(head);break;
			case 3:find(head);break;
			case 4:change(head);break;
			case 5:insert(head);break;
			case 6:sta_(head);break;
			case 7:rank_num(head);break;
			case 8:rank_score(head);break;
			case 9:output(head);break;
			default :printf("输入选项错误！\n");break;					
		}
		if(n==0){printf("成功退出系统！\n");break;}
	}	
	student*p,*q;
	p=head;
	q=head->next;
	while(p)
	{
		free(p);
		p=q;
		q=q->next;
	}
	return 0;
}
void menu(void)
{
	system("cls");
	printf("\n\n\n\n");
	printf("                                   学生成绩管理系统                 \n");
	printf("            ********************************************************\n");
	printf("            *          1 输入学生信息             2 删除学生记录   *\n");
	printf("            *          3 查询学生成绩             4 修改学生记录   *\n");
	printf("            *          5 插入学生记录             6 统计学生成绩   *\n");
	printf("            *          7 按学号排序               8 按成绩排序     *\n");
	printf("            *          9 输出学生信息             0 退出系统       *\n");
	printf("            ********************************************************\n");
	printf("\n\n");
	printf("            请输入您的选择(0-9):");
}
void input(student*head)
{
	student *p,*last;
	long a;
	char b[10];
	char s[4];
	float c[3];
	float d;
	float e;
	int i,n;
	do
	{
		system("cls");
		printf("请输入学生信息:\n");
		printf("请输入学号:");
		scanf("%ld",&a);
		printf("请输入姓名:");	
		scanf("%s",b);
		printf("请输入性别:");
		scanf("%s",s);
		printf("请输入 算法 的成绩:");
		scanf("%f",&c[0]);
		printf("请输入 实验 的成绩:");
		scanf("%f",&c[1]);
		printf("请输入 高数 的成绩:");
		scanf("%f",&c[2]);
		e=(c[0]+c[1]+c[2])*1.0/3.0;
		p=(student*)malloc(sizeof(student));
		p->num=a;
		strcpy(p->name,b);strcpy(p->sex,s);
		for(i=0;i<3;i++){p->score[i]=c[i];}
		p->average=e;
		p->next=NULL;
		last=head;
		while(last->next)
		{
			last=last->next;
		}
		last->next=p;
		printf("继续输入么？(1为继续，2为停止)\n");
		scanf("%d",&n);
		if(n==2){break;}	
	}while(1);		
}
void output(student*head)
{
	int i,n=0,m;
	student*p;
	p=head->next;
	if(p)
	{
	printf("%s %s %s %s %s %s %s","学号","姓名","性别","算法","实验","高数","平均成绩\n");
	while(p)
	{
		n++;
		printf("%ld %s %s",p->num,p->name,p->sex);
		for(i=0;i<3;i++){printf(" %.2f",p->score[i]);}
		printf(" %.2f",p->average);
		printf("\t");
		printf("\n");
    	p=p->next;
	}
		printf("学生信息个数:%d\n",n);
	}
	else {printf("该系统未录入信息！\n");}
	system("pause");
}
void delete_(student*head)
{
	student *p,*t;
	t=head;
	p=head->next;
	int i=0;
	long n;
	printf("请输入您要删除记录的学号:");
	scanf("%ld",&n);
	while(p)
	{
		if(n==p->num)
		{
			i=1;
			t->next=p->next;
			free(p);
			break;
		}
		else 
		{
			t=t->next;
			p=p->next;
		}
	}
	if(i==1){printf("已找到该结点:%ld,删除成功！\n",n);output(head);}
	if(i==0){printf("未找到该结点:%ld\n",n);output(head);}
}
void find(student*head)
{
	int i=0;
	long n;
	student *p;
	p=head->next;
	printf("请输入要查找学生学号:");
	scanf("%ld",&n);
	while(p)
	{
		if(n==p->num)
		{
			i=1;
			listhead(p);
			break;
		}
		else 
		{
			p=p->next;
		}
	}
		if(i==0){printf("未找到该学号信息！\n");}	
		system("pause");
}
void change(student*head)
{
	long n;
	student *p;
	printf("请输入要修改信息的学生学号:");
	scanf("%ld",&n);
	p=head->next;
	while(p)
	{
		if(n==p->num)
		{
			break;
		}
		else 
		{
			p=p->next;
		}
	}
	listhead(p);
	printf("请输入学生信息:\n");
	printf("请输入学号:");
	scanf("%ld",&p->num);
	printf("请输入姓名:");	
	scanf("%s",p->name);
	printf("请输入性别:");
	scanf("%s",p->sex);	printf("请输入 算法 的成绩:");
	scanf("%f",&p->score[0]);
	printf("请输入 实验 的成绩:");
	scanf("%f",&p->score[1]);
	printf("请输入 高数 的成绩:");
	scanf("%f",&p->score[2]);	
	output(head);
}
void rank_num(student*head)
{
	int i,j,n=0;
	student*p,*q,*r;
	p=head->next;
	while(p){n++;p=p->next;}
	for(i=0;i<n;i++)
	{
		r=head;
		p=head->next;
		q=p->next;
		for(j=0;j<n-i-1;j++)
		{
			if(p->num>q->num)
			{
				p->next=q->next;
				q->next=p;
				r->next=q;
			}
			r=r->next;
			p=r->next;
			q=p->next;
		}
	}
	output(head);
}
void rank_score(student*head)
{
	int i,j,n=0;
	student*p,*q,*r;
	p=head->next;
	while(p){n++;p=p->next;}
	for(i=0;i<n;i++)
	{
		r=head;
		p=head->next;
		q=p->next;
		for(j=0;j<n-i-1;j++)
		{
			if(p->average<q->average)
			{
				p->next=q->next;
				q->next=p;
				r->next=q;
			}
			r=r->next;
  			p=r->next;
			q=p->next;
		}
	}
	output(head);
}
void insert(student*head)
{
	student*p,*q=(student*)malloc(sizeof(student));
	printf("请输入学生信息:\n");		
	printf("请输入学号:");
	scanf("%ld",&q->num);
	printf("请输入姓名:");	
	scanf("%s",q->name);
	printf("请输入性别:");
	scanf("%s",q->sex);	
	printf("请输入 算法 的成绩:");
	scanf("%f",&q->score[0]);
	printf("请输入 实验 的成绩:");
	scanf("%f",&q->score[1]);
	printf("请输入 高数 的成绩:");
	scanf("%f",&q->score[2]);	
	q->average=(q->score[0]+q->score[1]+q->score[2])*1.0/3.0;
	p=head;
	q->next=p->next;
	p->next=q;
	output(head);
}
void sta_(student*head)
{
	int n=0;
	float a=0,b=0,c=0,d=0;
	student*p;
	p=head->next;
	while(p){n++;p=p->next;}
	p=head->next;
	while(p)
	{
		a+=p->score[0];
		b+=p->score[1];
		c+=p->score[2];
		d+=p->average;
		p=p->next;
	}
	output(head);
	printf("课程平均成绩:   算法  实验  高数  平均成绩\n");
	printf("                %.2f  %.2f  %.2f  %.2f\n",a/n*1.0,b/n*1.0,c/n*1.0,d/n*1.0);
	system("pause");
}
void listhead(student*p)
{
	int i;
	printf("%s %s %s %s %s %s %s","学号","姓名","性别","算法","实验","高数","平均成绩\n");
	printf("%ld %s %s",p->num,p->name,p->sex);
	for(i=0;i<3;i++){printf(" %.2f",p->score[i]);}
	printf(" %.2f\n",p->average);
}
