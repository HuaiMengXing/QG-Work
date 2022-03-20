#pragma once
#include<iostream>
#include<string>
#define SUCCESS 1;
#define ERROR 0;
using namespace std;

//初步的类型
typedef int ElemType;

// 状态返回
typedef int Status;


//单链表
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node, *LinkList;

class ListFunction
{
public:
	ListFunction();
	~ListFunction();

	//单链表菜单
	void Menu();

	//创建链表
	Status InitList(LinkList* L);

	//按输入想查找的数据，返回位置
	Status GetPlace(LinkList* L, ElemType e);

	//在某数据前后面插入新数据
	Status ListInsert(LinkList* L);

	//删除链表第i个数据，用e返回它的值
	Status ListDelete(LinkList* L);

	//遍历整个链表
	Status TraList(LinkList* L);

	//删除整个链表
	Status ClearList(LinkList* L);

	//单链表奇偶调换
	Status Odd_EvenList(LinkList* L);

	//找到单链表的中点
	Status CentreList(LinkList* L);

	//判断链表是否成环
	Status LoopList(LinkList* L);

	//反转链表（递归和非递归)
	Status ReverseList(LinkList* L);

	//长度(定义为全局变量)
	int ListLengh = 0;

private:

};



//双向链表
typedef struct Dul_Node
{
	ElemType data;
	struct Dul_Node* prior;//前指
	struct Dul_Node* next;//后指
}Dul_Node, *Dul_LinkList;


class Dul_ListFunction
{
public:
	Dul_ListFunction();
	~Dul_ListFunction();

	//双向链表菜单
	void Dul_Menu();

	//创建链表
	Status Dul_InitList(Dul_LinkList* L);

	//查找想要的数据
	Status Dul_Check(Dul_LinkList* L);

	//在某数据前后面插入新数据
	Status Dul_ListInsert(Dul_LinkList* L);

	//删除链表第i个数据，用e返回它的值
	Status Dul_ListDelete(Dul_LinkList* L);

	//遍历整个链表
	Status Dul_TraList(Dul_LinkList* L);

	//删除整个链表
	Status Dul_ClearList(Dul_LinkList* L);

	//长度(定义为全局变量)
	int Dul_ListLengh = 0;

private:

};
