#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Dynamic Contact File.h"

void CheckCapacity(struct Contact* p)//检查空间是否满，没满就啥也不干，满了就加空间
{
	if (p->size == p->capacity)
	{
		struct PeoInfo* ps = (struct PeoInfo*)realloc(p->date, (p->size + 2) * sizeof(struct PeoInfo));
		//给p->date指向的空间扩容，p->date的类型是struct PeoInfo*
		if (ps != NULL)
		{
			p->date = ps;
			p->capacity += 2;
			printf("已增容\n");

		}
		else
		{
			printf("增容失败\n");
		}

	}
}

void LoadContact(struct Contact* p)   //把文件中的数据读取到通讯录中
{
	FILE* ps = fopen("contact.dat", "rb");
	struct PeoInfo m = { 0 };
	if (ps == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	while (fread(&m, sizeof(struct PeoInfo), 1, ps))//返回成功读取的元素总数
	{
		CheckCapacity(p);     //保证空间足够
		p->date[p->size] = m;
		p->size++;
	}
	fclose(ps);
	ps = NULL;
}

void Init_Contact(struct Contact* p)
{
	p->date=(struct PeoInfo*)malloc(3*sizeof(struct PeoInfo));
	if (p->date == NULL)
	{
		return ;  //当开辟失败时返回空，啥也不干
	}
	p->capacity = DEFAULT_SZ;
	p->size = 0;
	LoadContact(p);
}


void AddContact(struct Contact* p)
{
	    CheckCapacity(p);	
		printf("请输入名字：");
		scanf("%s", p->date[p->size].name);
		printf("\n");
		printf("请输入性别：");
		scanf("%s", (p->date[p->size].sex));
		printf("\n");
		printf("请输入年龄：");
		scanf("%d" ,&(p->date[p->size].age));
		printf("\n");
		printf("请输入号码：");
		scanf("%s" ,p->date[p->size].id);
		printf("\n");
		printf("请输入地址：");
		scanf("%s",p->date[p->size].addt);
		printf("\n");
	
		printf("添加成功\n");
		p->size++;
		printf("\n");
}

void PrintContact(struct Contact* p)
{
	if (p->size == 0)
		printf("通讯录为空\n");
	else
	{
		int i;
		printf("%-10s\t%-3s\t%-3s\t%-20s\t%-10s\n","名字","性别","年龄","号码","地址"); 
		//  \t 作用: 输出时留出指定数目(前面的数字)的空格,方便对齐
		// - 作用：左对齐
		for (i = 0; i < p->size; i++)
		{
			printf("%-10s\t%-3s\t%-3d\t%-20s\t%-10s\n",
				p->date[i].name,
				p->date[i].sex,
				p->date[i].age,
				p->date[i].id,
				p->date[i].addt);

		}
		printf("\n");
	}
}



int  Find(struct Contact* p, char name[]) //查找函数，找到目标名字返回下标
{
	int i;
	for (i = 0; i < p->size; i++)
	{
		if (strcmp(p->date[i].name, name) == 0)
			return i;
	}
	return -1;

}
void DelContact(struct Contact* p)
{
	char name[20];
	printf("输入删除目标名字：\n");
	scanf("%s",name);
	int i = Find( p, name);
	if (i == -1)
		printf("目标不存在\n");
	else
	{
		int j;
		for (j = i; j < p->size - 1; j++)
		{
			p->date[j] = p->date[j + 1];
			p->size--;
		}
		printf("删除成功\n");
	}
}



void SearchContact(struct Contact* p)
{
	printf("请输入查找目标的名字：\n");
	char name[20];
	scanf("%s", name);
	int i = Find(p, name);
	if (i == -1)
		printf("目标不存在\n");
	else 
	{
		printf("%-10s\t%-3s\t%-3s\t%-20s\t%-10s\n", "名字", "性别", "年龄", "号码", "地址");
		printf("%-10s\t%-3s\t%-3d\t%-20s\t%-10s\n",
			p->date[i].name,
			p->date[i].sex,
			p->date[i].age,
			p->date[i].id,
			p->date[i].addt);
		printf("\n");
	}
}



void ModifyContact(struct Contact* p)
{
	printf("请输入修改目标的名字：\n");
	char name[20];
	scanf("%s", name);
	int i = Find(p, name);
	if (i == -1)
		printf("目标不存在\n");
	else
	{
		printf("请输入名字：");
		scanf("%s", p->date[p->size].name);
		printf("\n");
		printf("请输入性别：");
		scanf("%s", (p->date[p->size].sex));
		printf("\n");
		printf("请输入年龄：");
		scanf("%d", &(p->date[p->size].age));
		printf("\n");
		printf("请输入号码：");
		scanf("%s", p->date[p->size].id);
		printf("\n");
		printf("请输入地址：");
		scanf("%s", p->date[p->size].addt);
		printf("\n");

		printf("修改成功\n");
     }
		printf("%-10s\t%-3s\t%-3s\t%-20s\t%-10s\n", "名字", "性别", "年龄", "号码", "地址");
		printf("%-10s\t%-3s\t%-3d\t%-20s\t%-10s\n",
			p->date[i].name,
			p->date[i].sex,
			p->date[i].age,
			p->date[i].id,
			p->date[i].addt);	
		printf("\n");
}



#include <stdlib.h>
#include <string.h>
int namecmp(const void* a, const void* b)
{
	return strcmp(((struct PeoInfo*)a)->name , ((struct PeoInfo*)b)->name);
}
int agecmp(const void* a, const void* b)
{
	return((struct PeoInfo*)a)->age -((struct PeoInfo*)b)->age;
}
int sexcmp(const void* a, const void* b)
{
	return strcmp(((struct PeoInfo*)a)->sex, ((struct PeoInfo*)b)->sex);
}
int idcmp(const void* a, const void* b)
{
	return strcmp(((struct PeoInfo*)a)->id , ((struct PeoInfo*)b)->id);
}
int addtcmp(const void* a, const void* b)
{
	return strcmp(((struct PeoInfo*)a)->addt, ((struct PeoInfo*)b)->addt);
}
void mmm()
{

	printf("1:名字\n");
	printf("2:性别\n");
	printf("3:年龄\n");
	printf("4:号码\n");
	printf("5:地址\n");
	printf("0:停止排序\n");
	printf("选择排序项目：\n");
}
void SortContact(struct Contact* p)
{
	int i=1;
	do {
		mmm();
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			qsort(p->date, p->size, sizeof(p->date[0]), namecmp);
			break;
		case 2:
			qsort(p->date, p->size, sizeof(p->date[0]), sexcmp);
			break;
		case 3:
			qsort(p->date, p->size, sizeof(p->date[0]), agecmp);
			break;
		case 4:
			qsort(p->date, p->size, sizeof(p->date[0]), idcmp);
			break;
		case 5:
			qsort(p->date, p->size, sizeof(p->date[0]), addtcmp);
			break;
		case 0:
			printf("已退出\n");
			break;
		default:
			printf("输入错误，请重新输入：");
			break;
		}
		PrintContact(p);
	} while (i);
}

void DestroyContact(struct Contact* p)
{
		free(p->date);
		p->date = NULL;
}

#include <errno.h>
void SaveContact(struct Contact* p)
{
	FILE* ps = fopen("contact.dat", "wb");
	if (ps == NULL)
	{
		printf("%s\n",strerror(errno));
		return;
	}
	//写通讯录到文件中
	int i;
	for (i = 0; i < p->size; i++)
	{
		fwrite(&(p->date[i]), sizeof(struct PeoInfo), 1, ps);
	}
	fclose(ps);
	ps = NULL;
}



