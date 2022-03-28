#pragma once
#include<iostream>
#include<string>

#define ERROR  0;
#define SUCCESS  1;
#define INEXISTENCE -1;//栈不存在

//初定义
typedef int ElemType;
typedef int Status;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;//指针
	int	count;//长度
}LinkStack;


class LStack
{
public:
	LStack();
	~LStack();

	//链栈
	void menu();//界面菜单

	Status initLStack(LinkStack** s);//初始化栈

	Status isEmptyLStack(LinkStack* s);//判断栈是否为空或者没有栈

	Status getTopLStack(LinkStack* s);//得到栈顶元素

	Status clearLStack(LinkStack** s);//清空栈

	Status destroyLStack(LinkStack** s);//销毁栈
	
	Status LStackLength(LinkStack* s);//检测栈长度

	Status pushLStack(LinkStack** s);//入栈

	Status popLStack(LinkStack** s);//出栈

	Status TraStack(LinkStack* s);//栈的遍历

private:

};
