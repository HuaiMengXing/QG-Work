#include"LinkStack.h"
#include"Calculator.h"

numStack::numStack()
{
	node = NULL;
}

numStack::~numStack()
{
	while (!empty())//释放
	{
		pop();
	}
}

//判断
bool numStack::empty()
{
	if (node == NULL)
		return true;
	return false;
}

//入栈
void numStack::push(float x)
{
	Int_StackNode* n = new Int_StackNode;
	n->data = x;//赋值
	n->next = node;//将当前栈顶元素后继新结点
	node = n;//栈顶指针移位
}

//出栈
float numStack::pop()
{
	if (node == NULL)
	{
		std::cout << "\t输入错误！请重新输入！" << std::endl;
		system("pause");
		system("cls");
		return 0;
	}
	Int_StackNode* pop = node;
	float num = pop->data;//保留值弹出
	node = node->next;
	delete pop;
	return num;
}

//取到栈顶元素
float numStack::get_head()
{
	if (node == NULL)
	{
		std::cout << "\t输入错误！请重新输入！" << std::endl;
		system("pause");
		system("cls");
		return 0;
	}
	return node->data;
}

//清空栈里面的数据
void numStack::clear()
{
	Int_StackNode* cle = node;
	while (node != NULL)
	{
		cle = node;
		node = node->next;
		delete cle;
	}
}



charStack::charStack()
{
	Node = NULL;
}

charStack::~charStack()
{
	while (!empty())//释放
	{
		pop();
	}
}

//判断
bool charStack::empty()
{
	if (Node == NULL)
		return true;
	return false;
}

//入栈
void charStack::push(char x)
{
	Stack_Node* N = new Stack_Node;
	N->data = x;//赋值
	N->next = Node;//将当前栈顶元素后继新结点
	Node = N;//栈顶指针移位
}

//出栈
char charStack::pop()
{
	if (empty()) return '0';
	Stack_Node* pop = Node;
	char ch = pop->data;//保留值弹出
	Node = Node->next;
	delete pop;

	return ch;
}

//取到栈顶元素
char charStack::get_head()
{
	return Node->data;
}

//清空栈里面的数据
void charStack::clear()
{
	Stack_Node* cle = Node;
	while (Node != NULL)
	{
		cle = Node;
		Node = Node->next;
		delete cle;
	}
}