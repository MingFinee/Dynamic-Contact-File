#pragma once

#define DEFAULT_SZ 3 //默认大小3

struct PeoInfo
{
	char name[20];
	char sex[3];
	int age;
	char id[20];
	char addt[50];
};

//通讯录类型
struct Contact
{
	struct PeoInfo* date;
	int size;    //记录当前已经有的元素个数
	int capacity;//当前通讯录的最大容量
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
