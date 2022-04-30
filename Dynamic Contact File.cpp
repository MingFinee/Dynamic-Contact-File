#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Dynamic Contact File.h"

void CheckCapacity(struct Contact* p)//���ռ��Ƿ�����û����ɶҲ���ɣ����˾ͼӿռ�
{
	if (p->size == p->capacity)
	{
		struct PeoInfo* ps = (struct PeoInfo*)realloc(p->date, (p->size + 2) * sizeof(struct PeoInfo));
		//��p->dateָ��Ŀռ����ݣ�p->date��������struct PeoInfo*
		if (ps != NULL)
		{
			p->date = ps;
			p->capacity += 2;
			printf("������\n");

		}
		else
		{
			printf("����ʧ��\n");
		}

	}
}

void LoadContact(struct Contact* p)   //���ļ��е����ݶ�ȡ��ͨѶ¼��
{
	FILE* ps = fopen("contact.dat", "rb");
	struct PeoInfo m = { 0 };
	if (ps == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	while (fread(&m, sizeof(struct PeoInfo), 1, ps))//���سɹ���ȡ��Ԫ������
	{
		CheckCapacity(p);     //��֤�ռ��㹻
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
		return ;  //������ʧ��ʱ���ؿգ�ɶҲ����
	}
	p->capacity = DEFAULT_SZ;
	p->size = 0;
	LoadContact(p);
}


void AddContact(struct Contact* p)
{
	    CheckCapacity(p);	
		printf("���������֣�");
		scanf("%s", p->date[p->size].name);
		printf("\n");
		printf("�������Ա�");
		scanf("%s", (p->date[p->size].sex));
		printf("\n");
		printf("���������䣺");
		scanf("%d" ,&(p->date[p->size].age));
		printf("\n");
		printf("��������룺");
		scanf("%s" ,p->date[p->size].id);
		printf("\n");
		printf("�������ַ��");
		scanf("%s",p->date[p->size].addt);
		printf("\n");
	
		printf("��ӳɹ�\n");
		p->size++;
		printf("\n");
}

void PrintContact(struct Contact* p)
{
	if (p->size == 0)
		printf("ͨѶ¼Ϊ��\n");
	else
	{
		int i;
		printf("%-10s\t%-3s\t%-3s\t%-20s\t%-10s\n","����","�Ա�","����","����","��ַ"); 
		//  \t ����: ���ʱ����ָ����Ŀ(ǰ�������)�Ŀո�,�������
		// - ���ã������
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



int  Find(struct Contact* p, char name[]) //���Һ������ҵ�Ŀ�����ַ����±�
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
	printf("����ɾ��Ŀ�����֣�\n");
	scanf("%s",name);
	int i = Find( p, name);
	if (i == -1)
		printf("Ŀ�겻����\n");
	else
	{
		int j;
		for (j = i; j < p->size - 1; j++)
		{
			p->date[j] = p->date[j + 1];
			p->size--;
		}
		printf("ɾ���ɹ�\n");
	}
}



void SearchContact(struct Contact* p)
{
	printf("���������Ŀ������֣�\n");
	char name[20];
	scanf("%s", name);
	int i = Find(p, name);
	if (i == -1)
		printf("Ŀ�겻����\n");
	else 
	{
		printf("%-10s\t%-3s\t%-3s\t%-20s\t%-10s\n", "����", "�Ա�", "����", "����", "��ַ");
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
	printf("�������޸�Ŀ������֣�\n");
	char name[20];
	scanf("%s", name);
	int i = Find(p, name);
	if (i == -1)
		printf("Ŀ�겻����\n");
	else
	{
		printf("���������֣�");
		scanf("%s", p->date[p->size].name);
		printf("\n");
		printf("�������Ա�");
		scanf("%s", (p->date[p->size].sex));
		printf("\n");
		printf("���������䣺");
		scanf("%d", &(p->date[p->size].age));
		printf("\n");
		printf("��������룺");
		scanf("%s", p->date[p->size].id);
		printf("\n");
		printf("�������ַ��");
		scanf("%s", p->date[p->size].addt);
		printf("\n");

		printf("�޸ĳɹ�\n");
     }
		printf("%-10s\t%-3s\t%-3s\t%-20s\t%-10s\n", "����", "�Ա�", "����", "����", "��ַ");
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

	printf("1:����\n");
	printf("2:�Ա�\n");
	printf("3:����\n");
	printf("4:����\n");
	printf("5:��ַ\n");
	printf("0:ֹͣ����\n");
	printf("ѡ��������Ŀ��\n");
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
			printf("���˳�\n");
			break;
		default:
			printf("����������������룺");
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
	//дͨѶ¼���ļ���
	int i;
	for (i = 0; i < p->size; i++)
	{
		fwrite(&(p->date[i]), sizeof(struct PeoInfo), 1, ps);
	}
	fclose(ps);
	ps = NULL;
}



