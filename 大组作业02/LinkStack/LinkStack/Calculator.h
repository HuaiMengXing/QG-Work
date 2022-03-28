#pragma once
#include<iostream>
#include<map>
#include"LinkStack.h"

//������˵�
std::string main_menu();
//���ܵ���
void Calculator();
//Ԥ�ȴ���
std::string Preprocess(std::string str);

int priority(char ch);//�������ȼ��ж�
int count();//����
float Calculator_empty(std::string &str);//ѹ�ˣ����㣬��������


//����ջ
typedef  struct Stack_Node
{
	char data;
    Stack_Node* next;
}Stack_Node;

//����ջ
typedef  struct Int_StackNode
{
	float data;
	Int_StackNode* next;
}Int_StackNode;

//������
class numStack
{
public:
	numStack();
	~numStack();

	bool empty();//�ж�

	void push(float x);//��ջ

	float pop();//��ջ

	float get_head();//ȡ��ջ��Ԫ��

	void clear();//���ջ���������

private:
	Int_StackNode* node;
};

//�ַ���
class charStack
{
public:
	charStack();
	~charStack();

	bool empty();//�ж�

	void push(char x);//��ջ

	char pop();//��ջ

	char get_head();//ȡ��ջ��Ԫ��

	void clear();//���ջ���������

private:
	Stack_Node* Node;
};