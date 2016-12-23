#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "library.h"
#include "lirary.c"
//��ʾά���˵�
void display_maintenance_menu()
{
	system("cls");
	puts("\n\n\t\t<<ά���Ӳ˵�(DEFEND MUNU)>>\n\n");
	puts("\t1 --ע���û�(ENROLL USER)");
	puts("\t2 --ע��ͼ��(ENROLL BOOK)");
	puts("\t3 --ע���û�(CANCEL USER)");
	puts("\t4 --ע��ͼ��(CANCEL BOOK)");
	puts("\t5 --�汾��Ϣ(EDITION INFORMATION)");
	puts("\t0 --�����Ӳ˵�(RETURN MENU)");
}

//��Ϣ���Ҳ˵�
void display_info_menu()
{
	system("cls");
	puts("\n\n\t\t<<��Ϣ�����Ӳ˵�(FIND INFORMATION OF THE MEMU)>>\n\n");
	puts("\t1 --�����û���Ϣ(FIND USER'S INFORMATION)");
	puts("\t2 --����ͼ����Ϣ(FIND BOOK'S INFORMATION)");
	puts("\t3 --����û���Ϣ(BROWSE USER'S INFORMATION)");
	puts("\t4 --���ͼ����Ϣ(BROWSE BOOK'S INFORMATION)");
	puts("\t0 --�������˵�(RETURN MENU)");

}
//���˵�
void display_mainmenu()
{
	system("cls");
	puts("\n\t\t         �����ѧͼ�����ϵͳ                 \n\n");
	puts("\t\t\t         ====================\n\n");
	puts("\t             1 --����(BORROW BOOK)");
	puts("\t             2 --����(RETURN BOOK)");
	puts("\t             3 --����(MANAGE)");
	puts("\t             4 --����(FIND)");
	puts("\t             0 --�˳�(EXIT)");
	puts("\n");
	puts("\t     --��ѡ��(CHOOSE):           ");
}
//�������
void display_end()
{
	system("cls");
	puts("\n\n\n\n\n\n\tллʹ�ã���ӭ�´ι���!\n");
}



//������
int main(void)
{
	int quit=0;
	char ch;
	
	init_system();
	do
	{
		display_mainmenu();
		ch=getch();
		switch(ch)
		{
			case '1':
				//lend_book();
				break;
			case '2':
				//return_book();
				break;
			case '3':
				{
					int sub_run=1;
					while(sub_run)
					{
						display_maintenance_menu();
						ch=getch();
					    switch(ch)
						{
							case '1':
								{		create_borrower();
								break;}
							case '2':
								{	 	create_book();
								break;}
							case '3':
								{		remove_borrower();
								break;}
							case '4':
								{		remove_book();
								break;}
							case '0':
								sub_run=0;
								break;
						}
					}
				}
				break;
			case '4':
				{
					int sub_run=1;
					while(sub_run)
					{
						display_info_menu();
						ch=getch();
						switch(ch)
						{
							case '1':
								{		lookup_borrower();
								break;}
							case '2':
								{		lookup_book();
									break;
								}
							case '3':
								{   
										browse_borrower();
									break;}
							case '4':
								{	
										browse_book();
									break;
								}
							case '0':
								sub_run=0;
								break;
						}
				    }
				}
				break;
			case '0':
				quit=1;
				break;
		}
	}while(!quit);
	release_system();
	display_end();
	getch();
	return 0;
}
