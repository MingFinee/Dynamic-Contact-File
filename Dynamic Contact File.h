#pragma once

#define DEFAULT_SZ 3 //Ĭ�ϴ�С3

struct PeoInfo
{
	char name[20];
	char sex[3];
	int age;
	char id[20];
	char addt[50];
};

//ͨѶ¼����
struct Contact
{
	struct PeoInfo* date;
	int size;    //��¼��ǰ�Ѿ��е�Ԫ�ظ���
	int capacity;//��ǰͨѶ¼���������
};

void Init_Contact(struct Contact* p);
void AddContact(struct Contact* p);
void PrintContact(struct Contact* p);
void DelContact(struct Contact* p);
void SearchContact(struct Contact* p);
void ModifyContact(struct Contact* p);
void SortContact(struct Contact* p);
void DestroyContact(struct Contact* p);
void SaveContact(struct Contact* p);
void LoadContact(struct Contact* p);
enum Option
{
	Exit,   //0
	add,    //1 
	del,
	search,
	modify,
	show,
	sort,
	save,
	load
};
