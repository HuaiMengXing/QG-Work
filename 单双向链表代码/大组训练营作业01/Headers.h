#pragma once
#include<iostream>
#include<string>
#define SUCCESS 1;
#define ERROR 0;
using namespace std;

//����������
typedef int ElemType;

// ״̬����
typedef int Status;


//������
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

	//������˵�
	void Menu();

	//��������
	Status InitList(LinkList* L);

	//����������ҵ����ݣ�����λ��
	Status GetPlace(LinkList* L, ElemType e);

	//��ĳ����ǰ�������������
	Status ListInsert(LinkList* L);

	//ɾ�������i�����ݣ���e��������ֵ
	Status ListDelete(LinkList* L);

	//������������
	Status TraList(LinkList* L);

	//ɾ����������
	Status ClearList(LinkList* L);

	//��������ż����
	Status Odd_EvenList(LinkList* L);

	//�ҵ���������е�
	Status CentreList(LinkList* L);

	//�ж������Ƿ�ɻ�
	Status LoopList(LinkList* L);

	//��ת�����ݹ�ͷǵݹ�)
	Status ReverseList(LinkList* L);

	//����(����Ϊȫ�ֱ���)
	int ListLengh = 0;

private:

};



//˫������
typedef struct Dul_Node
{
	ElemType data;
	struct Dul_Node* prior;//ǰָ
	struct Dul_Node* next;//��ָ
}Dul_Node, *Dul_LinkList;


class Dul_ListFunction
{
public:
	Dul_ListFunction();
	~Dul_ListFunction();

	//˫������˵�
	void Dul_Menu();

	//��������
	Status Dul_InitList(Dul_LinkList* L);

	//������Ҫ������
	Status Dul_Check(Dul_LinkList* L);

	//��ĳ����ǰ�������������
	Status Dul_ListInsert(Dul_LinkList* L);

	//ɾ�������i�����ݣ���e��������ֵ
	Status Dul_ListDelete(Dul_LinkList* L);

	//������������
	Status Dul_TraList(Dul_LinkList* L);

	//ɾ����������
	Status Dul_ClearList(Dul_LinkList* L);

	//����(����Ϊȫ�ֱ���)
	int Dul_ListLengh = 0;

private:

};
