#define _CRT_SECURE_NO_WARNINGS 1




//0.�˳�
//1.���Ӻ�����Ϣ
//2.ɾ��ָ�����ֵĺ�����Ϣ
//3.���Һ�����Ϣ
//4.�޸ĺ�����Ϣ
//5.��ӡ������Ϣ
//6.����
//7.���浽�ļ�
//8.�����ļ�����Ϣ��ͨѶ¼��

#include <stdio.h>
#include <stdlib.h>
#include "Dynamic Contact File.h"


void menu()
{
    printf("*********0.exit********\n");
	printf("*********1.add*********\n");
	printf("*********2.del*********\n");
	printf("*********3.search******\n");
	printf("*********4.modify******\n");
	printf("*********5.show********\n");
	printf("*********6.sort********\n");
	printf("*********7.save********\n");
}



int main()
{
	struct Contact con; //����ͨѶ¼con,����dateָ�룬capacity��size
	Init_Contact(&con); //��ʼ��
	int input;
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d",&input);
		switch (input)
		{
		case add:
			AddContact(&con);
			break;
		case del:
			DelContact(&con);
			break;
		case search:
			SearchContact(&con);
			break;
		case modify:
			ModifyContact(&con);
			break;
		case show:
			PrintContact(&con);
			break;
		case sort:
			SortContact(&con);
			break;
		case Exit:
			DestroyContact(&con);//free/NULL
			printf("���˳�\n");
			break;
		case save:
			SaveContact(&con);
			printf("�ѱ���\n");
			break; 
		default:
			printf("�����������������\n");
			break;
		}
	} while(input);
	return 0;
}


