#pragma once
#include<iostream>
#include<map>
#include"LinkStack.h"

//主界面菜单
std::string main_menu();
//功能调用
void Calculator();
//预先处理
std::string Preprocess(std::string str);

int priority(char ch);//符号优先级判断
int count();//计算
float Calculator_empty(std::string &str);//压人，计算，弹出流程


//符号栈
typedef  struct Stack_Node
{
	char data;
    Stack_Node* next;
}Stack_Node;

//数字栈
typedef  struct Int_StackNode
{
	float data;
	Int_StackNode* next;
}Int_StackNode;

//数字类
class numStack
{
public:
	numStack();
	~numStack();

	bool empty();//判断

	void push(float x);//入栈

	float pop();//出栈

	float get_head();//取到栈顶元素

	void clear();//清空栈里面的数据

private:
	Int_StackNode* node;
};

//字符类
class charStack
{
public:
	charStack();
	~charStack();

	bool empty();//判断

	void push(char x);//入栈

	char pop();//出栈

	char get_head();//取到栈顶元素

	void clear();//清空栈里面的数据

private:
	Stack_Node* Node;
};