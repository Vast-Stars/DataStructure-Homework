/* 
ģ���ֻ�ͨ��¼����ϵͳ��ʵ�ֶ��ֻ��е�ͨ��¼���й���
����Ҫ��
 	�鿴���ܣ�ѡ��˹���ʱ���г���������ѡ��
 	A  �칫��  B  ������ C ������ ����ѡ��ĳ��ʱ����ʾ���������������е������͵绰���룩
 	���ӹ��ܣ���¼�������ݣ�һ�����������������绰���롢���ࣨ��ѡ���У�A  �칫��  B  ������ C �����ࣩ�������ʼ���������
�   13511111111  ������  chuny@126.com
��¼�����ظ��������͵绰����ʱ������ʾ����¼���ظ���ȡ��¼�룻��ͨ��¼�г���15����Ϣʱ���洢�ռ�������������¼�������ݣ�¼����������ܰ�������˳���Զ�������Ŀ��š�
 	�κŹ��ܣ�����ʾ��ͨ��¼�������˵���������ѡ��ĳ������ʱ����Ļ��ģ����ֻ���Ч��������ʾ�����˵ĵ绰�����еĸ������֣���������Ӧ�İκ�������
 	�޸Ĺ��ܣ�ѡ��ĳ���˵�����ʱ���ɶԴ��˵���Ӧ���ݽ����޸�
 	ɾ�����ܣ�ѡ��ĳ���˵�����ʱ���ɶԴ��˵���Ӧ���ݽ���ɾ�������Զ�����������Ŀ�ı�š�*/
#include<stdio.h>
#include<math.h>
#include<string.h>
//#include<windows.h>
//#include<mmsystem.h>
//#pragma comment(lib, "winmm.lib")
typedef struct com
{
	char name[20];
	char no[12];
	char Class[20];
	char Email[30];
	struct com *next;
}note;
int sum=0;
void tip()
{
	printf("                       ����������������\n");
	printf("                             ��ӭ�����ֻ�ͨѶ¼\n");
	printf("                       ����������������\n\n\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("     �����ܡ� 1-�鿴  2-���  3-���Ź���   4-�޸�  5-ɾ��\n");
	printf("-------------------------------------------------------------------------------\n");
}
void tip1()
{
	printf("-------------------------------------------------------------------------------\n");
	printf("     �����ܡ� 1-�鿴  2-���  3-���Ź���   4-�޸�  5-ɾ��\n");
	printf("-------------------------------------------------------------------------------\n");
}
note *crete()
{
	note *head=NULL,*p=NULL,*p1=NULL;
	printf("�������������绰���룬���ͣ������ʼ�,����Ϊ0�˳�\n");
	for(;;)
	{
		p=(note*)malloc(sizeof(note));
		fflush(stdin);
		gets(p->name);
		if(*(p->name)=='0')
			break;
		fflush(stdin);
		gets(p->no);
		fflush(stdin);
		gets(p->Class);
		fflush(stdin);
		gets(p->Email);
		fflush(stdin);
		p->next=NULL;
		sum++;
		if(p1==NULL)
			head=p1=p;
		else
		{
			p1->next=p;
			p1=p;
		}	
	}
	return head;
}
void Display()
{
	note *p=NULL,*p1=NULL,*head=NULL;
	FILE *fp=fopen("communication.txt","r");
	if(fp==NULL)
	{
		printf("��ʧ��\n");
		return;
	}
	printf("-------------------------------------------------------------------------------\n");
	printf("    ����        �绰����            ����           ����\n");
	printf("-------------------------------------------------------------------------------\n");
	for(p=head;;)
	{   
		p=(note*)malloc(sizeof(note));
		fscanf(fp,"%s%s%s%s",p->name,p->no,p->Class,p->Email);
		p->next=NULL;
		if(p1==NULL)
			head=p1=p;
		else
		{
			p1->next=p;
			p1=p;
		}	
		if(feof(fp)!=0)//��Ҫ
			break;
		printf("    %-7s",p->name);
		printf("     %-13s",p->no);
		printf("       %-8s",p->Class);
		printf("        %-15s\n\n",p->Email);
		
	}
	fclose(fp);
	printf("-------------------------------------------------------------------------------\n");
}
//����
void save(note *head)
{

	note *p;
	FILE *fp=fopen("communication.txt","w");
	if(fp==NULL)
	{
		printf("��ʧ��\n");
		return;
	}
	for(p=head;p!=NULL;)
	{
		fprintf(fp,"%s %s %s %s ",p->name,p->no,p->Class,p->Email);
		p=p->next;
	}
	fclose(fp);
}
// �޸�
note * alter(char *name1)
{
	int sel1;
	char no1[20],name2[20],class1[20],Email1[20];
	note *p=NULL,*p1=NULL,*head=NULL;
	FILE *fp=fopen("communication.txt","r");
	if(fp==NULL)
	{
		printf("��ʧ��\n");
	}
	for(p=head;;)
	{  
		if(feof(fp)!=0)//��Ҫ
			break;
		p=(note*)malloc(sizeof(note));
		fscanf(fp,"%s%s%s%s",p->name,p->no,p->Class,p->Email);
		p->next=NULL;
		if(p1==NULL)
			head=p1=p;
		else
		{
			p1->next=p;
			p1=p;
		}	
		if(strcmp(p->name,name1)==0)
		{
			while(1)
			{
			printf("-------------------------------------------------------------------------------\n");
			printf("      ���޸�ѡ�� 1-����  2-�绰����  3-����   4-��������  0-�޸����\n");
			printf("-------------------------------------------------------------------------------\n");
			scanf("%d",&sel1);
			if(sel1==0)
			{
				printf("                            ����������\n");
				printf("                            �ϲ���޸ĳɹ���\n");
				printf("                            ����������\n");
				break;
			}
			switch(sel1)
			{
				case 1:
					{
						printf("����������:");
						scanf("%s",name2);
						strcpy(p->name,name2);
					}
					break;
				case 2:
					{
						printf("���������:");
						scanf("%s",no1);
						strcpy(p->no,no1);
					}
					break;
				case 3:
					{
						printf("����������:");
						scanf("%s",class1);
						strcpy(p->Class,class1);
					}
					break;
				case 4:
					{
						printf("����������:");
						scanf("%s",Email1);
						strcpy(p->Email,Email1);
					}
					break;

			}
			}
		}
	}
	fclose(fp);
	printf("\n");
	return head;
}
void save1(note *head)
{

	note *p;
	FILE *fp=fopen("communication.txt","w");
	if(fp==NULL)
	{
		printf("��ʧ��\n");
		return;
	}
	for(p=head;;)
	{
		fprintf(fp,"%s %s %s %s ",p->name,p->no,p->Class,p->Email);
		p=p->next;
		if(p->next==NULL)
			break;
	}
	fclose(fp);
}
note *Insert()    //����ڵ�
{
	note *p,*p1=NULL,*head=NULL,*p2=NULL;
	FILE *fp=fopen("communication.txt","r");
	if(fp==NULL)
	{
		printf("��ʧ��\n");
	}
	for(p=head;;)
	{
		if(feof(fp)!=0)//��Ҫ
			break;
		p=(note*)malloc(sizeof(note));
		fscanf(fp,"%s%s%s%s",p->name,p->no,p->Class,p->Email);
		p->next=NULL;
		if(p1==NULL)
			head=p1=p;
		else
		{
			p1->next=p;
			p1=p;
		}
		
	}
			p2=(note*)malloc(sizeof(note));
			fflush(stdin);
			/*gets(p2->name);
			fflush(stdin);
			gets(p2->no);
			fflush(stdin);
			gets(p2->Class);
			fflush(stdin);
			gets(p2->Email);*/
				printf("��������Ҫ�����ϵ�˵���Ϣ��\n");
				printf("������");
			fflush(stdin);
			scanf("%s",p2->name);
			printf("�绰���룺");
			fflush(stdin);
			scanf("%s",p2->no);
			printf("���ͣ�");
			fflush(stdin);
			scanf("%s",p2->Class);
			printf("�������䣺");
			fflush(stdin);
			scanf("%s",p2->Email);
		//	scanf("%s%s%s%s",p2->name,p2->no,p2->Class,p2->Email);
			p2->next=head;
			head=p2;
				printf("                            ����������\n");
				printf("                            �ϲ����ӳɹ���\n");
				printf("                            ����������\n");
			return head;
}
note *Delete()
{
	char name3[20];
	note *head=NULL,*p=NULL,*p1=NULL;
	FILE *fp=fopen("communication.txt","r");
	printf("��������Ҫɾ������ϵ�˵�������");
	fflush(stdin);
	gets(name3);
	if(fp==NULL)
	{
		printf("��ʧ��\n");
	}
	for(p=head;;)
	{
		if(feof(fp)!=0)//��Ҫ
			break;
		p=(note*)malloc(sizeof(note));
		fscanf(fp,"%s%s%s%s",p->name,p->no,p->Class,p->Email);
		p->next=NULL;
		if(p1==NULL)
			head=p1=p;
		else
		{
			p1->next=p;
			p1=p;
		}
	}
	for(p1=p=head;p!=NULL;)
	{
		if(strcmp(head->name,name3)==0)
		{
			head=p->next;
		}
		if(strcmp(p->name,name3)==0)
				p1->next=p->next;
			p1=p;
			p=p->next;
	}	
				printf("                            ����������\n");
				printf("                            �ϲ��ɾ���ɹ���\n");
				printf("                            ����������\n");
	return head;
}
void Dial()
{
	char name4[20],no5[20];
	int i;
	note *head=NULL,*p=NULL,*p1=NULL;
	FILE *fp=fopen("communication.txt","r");
	printf("��������Ҫ�����˵�����:");
	fflush(stdin);
	gets(name4);
	if(fp==NULL)
	{
		printf("��ʧ��\n");
	}
	for(p=head;;)
	{
		if(feof(fp)!=0)//��Ҫ
			break;
		p=(note*)malloc(sizeof(note));
		fscanf(fp,"%s%s%s%s",p->name,p->no,p->Class,p->Email);
		p->next=NULL;
		if(p1==NULL)
			head=p1=p;
		else
		{
			p1->next=p;
			p1=p;
		}
	}
		for(p=head;p->next!=NULL;)
		{
			if(strcmp(p->name,name4)==0)
			{
				strcpy(no5,p->no);
				for(i=0;i<(int)strlen(p->no);i++)
				{
					if(i==0)
				//	PlaySound(TEXT("475.wav"),NULL,SND_FILENAME|SND_ASYNC);//��������
					printf("%c",no5[i]);
					Sleep(555);//����ʱ��
					
				}
				printf("\n");
				printf("                            ����������\n");
				printf("                            �ϲ��ɾ���ɹ���\n");
				printf("                            ����������\n");
			}
			p=p->next;
		}
	
}
void Display1(char *CLASS)
{
	note *p=NULL,*p1=NULL,*head=NULL;
	FILE *fp=fopen("communication.txt","r");
	if(fp==NULL)
	{
		printf("��ʧ��\n");
		return;
	}
	printf("-------------------------------------------------------------------------------\n");
	printf("    ����        �绰����            ����           ����\n");
	printf("-------------------------------------------------------------------------------\n");
	for(p=head;;)
	{   
		p=(note*)malloc(sizeof(note));
		fscanf(fp,"%s%s%s%s",p->name,p->no,p->Class,p->Email);
		p->next=NULL;
		if(p1==NULL)
			head=p1=p;
		else
		{
			p1->next=p;
			p1=p;
		}	
		if(feof(fp)!=0)//��Ҫ
			break;
		
		if(strcmp(p->Class,CLASS)==0)
		{
		printf("    %-7s",p->name);
		printf("     %-13s",p->no);
		printf("       %-8s",p->Class);
		printf("        %-15s\n\n",p->Email);
		}
	}
	fclose(fp);
	printf("-------------------------------------------------------------------------------\n");
}
void main()
{
	int sel;
	char class2;
	char name1[20];
	char A[10]={"������"},B[10]={"������"},C[10]={"�칫��"};
	note *head=NULL;
	tip();
	for(;;)
	{
		printf("��ѡ��>>:");
		scanf("%d",&sel);
		if(sel>5)
			break;
		switch(sel)
		{
			case 1:
				{
					system("cls");
					printf("-------------------------------------------------------------------------------\n");
					printf("            A-������****B-������****C-�칫��****D-�鿴������\n");
					printf("-------------------------------------------------------------------------------\n");
					printf("��ѡ��>>:");
					
					fflush(stdin);
					scanf("%c",&class2);
					if(class2=='D'||class2=='d')
						Display();
					if(class2=='A'||class2=='a')
						Display1(A);
					if(class2=='B'||class2=='b')
						Display1(B);
					if(class2=='C'||class2=='c')
						Display1(C);
					tip1();
				}
				break;
			case 2:
				{
					system("cls");
					head=Insert();
					save1(head);
					tip1();
				}
				break;
			case 3:
				{
					system("cls");
					Dial();
					tip1();
				}
				break;
			case 4:
				{
					system("cls");
					printf("��������Ҫ�޸������˵�������");
					fflush(stdin);
					scanf("%s",name1);
					head=alter(name1);
					save1(head);
					tip1();
				}
				break;
			case 5:
				{
					head=Delete();
					save1(head);
					tip1();
				}
				break;
			case 0:
				{
					system("cls");
					head=crete();
					save(head);
					tip1();
				}
				break;
		}	
	}
}
