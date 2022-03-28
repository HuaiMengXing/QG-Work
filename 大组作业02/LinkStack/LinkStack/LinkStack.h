#pragma once
#include<iostream>
#include<string>

#define ERROR  0;
#define SUCCESS  1;
#define INEXISTENCE -1;//ջ������

//������
typedef int ElemType;
typedef int Status;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;//ָ��
	int	count;//����
}LinkStack;


class LStack
{
public:
	LStack();
	~LStack();

	//��ջ
	void menu();//����˵�

	Status initLStack(LinkStack** s);//��ʼ��ջ

	Status isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ�ջ���û��ջ

	Status getTopLStack(LinkStack* s);//�õ�ջ��Ԫ��

	Status clearLStack(LinkStack** s);//���ջ

	Status destroyLStack(LinkStack** s);//����ջ
	
	Status LStackLength(LinkStack* s);//���ջ����

	Status pushLStack(LinkStack** s);//��ջ

	Status popLStack(LinkStack** s);//��ջ

	Status TraStack(LinkStack* s);//ջ�ı���

private:

};
