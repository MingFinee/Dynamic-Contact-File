#define _CRT_SECURE_NO_WARNINGS 1




//0.退出
//1.增加好友信息
//2.删除指定名字的好友信息
//3.查找好友信息
//4.修改好友信息
//5.打印好友信息
//6.排序
//7.保存到文件
//8.加载文件的信息到通讯录中

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
	struct Contact con; //创建通讯录con,包含date指针，capacity和size
	Init_Contact(&con); //初始化
	int input;
	do
	{
		menu();
		printf("请选择：\n");
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
			printf("已退出\n");
			break;
		case save:
			SaveContact(&con);
			printf("已保存\n");
			break; 
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while(input);
	return 0;
}


