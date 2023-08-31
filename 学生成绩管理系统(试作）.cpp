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
			default :printf("����ѡ�����\n");break;					
		}
		if(n==0){printf("�ɹ��˳�ϵͳ��\n");break;}
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
	printf("                                   ѧ���ɼ�����ϵͳ                 \n");
	printf("            ********************************************************\n");
	printf("            *          1 ����ѧ����Ϣ             2 ɾ��ѧ����¼   *\n");
	printf("            *          3 ��ѯѧ���ɼ�             4 �޸�ѧ����¼   *\n");
	printf("            *          5 ����ѧ����¼             6 ͳ��ѧ���ɼ�   *\n");
	printf("            *          7 ��ѧ������               8 ���ɼ�����     *\n");
	printf("            *          9 ���ѧ����Ϣ             0 �˳�ϵͳ       *\n");
	printf("            ********************************************************\n");
	printf("\n\n");
	printf("            ����������ѡ��(0-9):");
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
		printf("������ѧ����Ϣ:\n");
		printf("������ѧ��:");
		scanf("%ld",&a);
		printf("����������:");	
		scanf("%s",b);
		printf("�������Ա�:");
		scanf("%s",s);
		printf("������ �㷨 �ĳɼ�:");
		scanf("%f",&c[0]);
		printf("������ ʵ�� �ĳɼ�:");
		scanf("%f",&c[1]);
		printf("������ ���� �ĳɼ�:");
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
		printf("��������ô��(1Ϊ������2Ϊֹͣ)\n");
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
	printf("%s %s %s %s %s %s %s","ѧ��","����","�Ա�","�㷨","ʵ��","����","ƽ���ɼ�\n");
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
		printf("ѧ����Ϣ����:%d\n",n);
	}
	else {printf("��ϵͳδ¼����Ϣ��\n");}
	system("pause");
}
void delete_(student*head)
{
	student *p,*t;
	t=head;
	p=head->next;
	int i=0;
	long n;
	printf("��������Ҫɾ����¼��ѧ��:");
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
	if(i==1){printf("���ҵ��ý��:%ld,ɾ���ɹ���\n",n);output(head);}
	if(i==0){printf("δ�ҵ��ý��:%ld\n",n);output(head);}
}
void find(student*head)
{
	int i=0;
	long n;
	student *p;
	p=head->next;
	printf("������Ҫ����ѧ��ѧ��:");
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
		if(i==0){printf("δ�ҵ���ѧ����Ϣ��\n");}	
		system("pause");
}
void change(student*head)
{
	long n;
	student *p;
	printf("������Ҫ�޸���Ϣ��ѧ��ѧ��:");
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
	printf("������ѧ����Ϣ:\n");
	printf("������ѧ��:");
	scanf("%ld",&p->num);
	printf("����������:");	
	scanf("%s",p->name);
	printf("�������Ա�:");
	scanf("%s",p->sex);	printf("������ �㷨 �ĳɼ�:");
	scanf("%f",&p->score[0]);
	printf("������ ʵ�� �ĳɼ�:");
	scanf("%f",&p->score[1]);
	printf("������ ���� �ĳɼ�:");
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
	printf("������ѧ����Ϣ:\n");		
	printf("������ѧ��:");
	scanf("%ld",&q->num);
	printf("����������:");	
	scanf("%s",q->name);
	printf("�������Ա�:");
	scanf("%s",q->sex);	
	printf("������ �㷨 �ĳɼ�:");
	scanf("%f",&q->score[0]);
	printf("������ ʵ�� �ĳɼ�:");
	scanf("%f",&q->score[1]);
	printf("������ ���� �ĳɼ�:");
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
	printf("�γ�ƽ���ɼ�:   �㷨  ʵ��  ����  ƽ���ɼ�\n");
	printf("                %.2f  %.2f  %.2f  %.2f\n",a/n*1.0,b/n*1.0,c/n*1.0,d/n*1.0);
	system("pause");
}
void listhead(student*p)
{
	int i;
	printf("%s %s %s %s %s %s %s","ѧ��","����","�Ա�","�㷨","ʵ��","����","ƽ���ɼ�\n");
	printf("%ld %s %s",p->num,p->name,p->sex);
	for(i=0;i<3;i++){printf(" %.2f",p->score[i]);}
	printf(" %.2f\n",p->average);
}
