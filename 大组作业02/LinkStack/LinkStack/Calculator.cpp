#include"LinkStack.h"
#include"Calculator.h"

numStack::numStack()
{
	node = NULL;
}

numStack::~numStack()
{
	while (!empty())//�ͷ�
	{
		pop();
	}
}

//�ж�
bool numStack::empty()
{
	if (node == NULL)
		return true;
	return false;
}

//��ջ
void numStack::push(float x)
{
	Int_StackNode* n = new Int_StackNode;
	n->data = x;//��ֵ
	n->next = node;//����ǰջ��Ԫ�غ���½��
	node = n;//ջ��ָ����λ
}

//��ջ
float numStack::pop()
{
	if (node == NULL)
	{
		std::cout << "\t����������������룡" << std::endl;
		system("pause");
		system("cls");
		return 0;
	}
	Int_StackNode* pop = node;
	float num = pop->data;//����ֵ����
	node = node->next;
	delete pop;
	return num;
}

//ȡ��ջ��Ԫ��
float numStack::get_head()
{
	if (node == NULL)
	{
		std::cout << "\t����������������룡" << std::endl;
		system("pause");
		system("cls");
		return 0;
	}
	return node->data;
}

//���ջ���������
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
	while (!empty())//�ͷ�
	{
		pop();
	}
}

//�ж�
bool charStack::empty()
{
	if (Node == NULL)
		return true;
	return false;
}

//��ջ
void charStack::push(char x)
{
	Stack_Node* N = new Stack_Node;
	N->data = x;//��ֵ
	N->next = Node;//����ǰջ��Ԫ�غ���½��
	Node = N;//ջ��ָ����λ
}

//��ջ
char charStack::pop()
{
	if (empty()) return '0';
	Stack_Node* pop = Node;
	char ch = pop->data;//����ֵ����
	Node = Node->next;
	delete pop;

	return ch;
}

//ȡ��ջ��Ԫ��
char charStack::get_head()
{
	return Node->data;
}

//���ջ���������
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