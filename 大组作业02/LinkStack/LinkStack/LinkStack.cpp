#include"LinkStack.h"
//��ջ

LStack::LStack()
{

}

LStack::~LStack()
{

}

//����˵�
void LStack::menu() {

	system("cls");

	LinkStack* stack = NULL;//ջ
	LStack LStack;//�ӿ�
	while (true)
	{
		std::cout << "\t* ****************************************************** *" << std::endl;
		std::cout << "\t* ********************ջ����ϵͳ����******************** *" << std::endl;
		std::cout << "\t*   1������ջ         * 2����ջ          * 3����ջ       *" << std::endl;
		std::cout << "\t*   4����ջ��Ԫ��     * 5�����ջ����    * 6���ж�ջ״̬ *" << std::endl;
		std::cout << "\t*   7������ջ         * 8�����ջ        * 9������ջ     *" << std::endl;
		std::cout << "\t*                     * 10 ���˳�                        *" << std::endl;
		std::cout << "\t* ****************************************************** *" << std::endl;
		std::cout << "\t���������ѡ��";

		std::string select;
		std::cin >> select;

		switch (atoi(select.c_str()))
		{
		case 1:LStack.initLStack(&stack);
			break;
		case 2:LStack.pushLStack(&stack);
			break;
		case 3:LStack.popLStack(&stack);
			break;
		case 4:LStack.getTopLStack(stack);
			break;
		case 5:LStack.LStackLength(stack);
			break;
		case 6:LStack.isEmptyLStack(stack);
			break;
		case 7:LStack.TraStack(stack);
			break;
		case 8:LStack.clearLStack(&stack);
			break;
		case 9:LStack.destroyLStack(&stack);
			break;
		case 10:
			std::cout << "\t��л����ʹ�ã�ף��������죡�ݰ�~~" << std::endl;
			system("pause");
			system("cls");
			return;
		default:
			std::cout << "\t�������������ѡ��!" << std::endl;
			system("pause");
			system("cls");
			break;
		}

	}
	return;
}

//����ջ
Status LStack::initLStack(LinkStack** s){

	(*s) = new LinkStack;
	(*s)->top = NULL;
	(*s)->count = 0;
	std::cout << "\t�����ɹ���" << std::endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ�ջ���û��ջ
Status LStack::isEmptyLStack(LinkStack* s) {

	if (s == NULL)//������ջ
	{
		std::cout << "\tջ������!�����Ѿ����٣�" << std::endl;
		system("pause");
		system("cls");
		return INEXISTENCE;
	}
	else if (s->count == 0)//ջ���ڣ�����Ϊ��
	{
		std::cout << "\tջ�Ѿ�����,��ջΪ�գ�" << std::endl;
		system("pause");
		system("cls");
		return ERROR;
	}
	//����ջ�Ҳ�Ϊ��
	std::cout << "\tջ�Ѿ�����,ջ��Ϊ�գ�" << std::endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//�õ�ջ��Ԫ��
Status LStack::getTopLStack(LinkStack* S) {

	if (S == NULL || S->count == 0)//ջ������!����Ϊ��
	{
		std::cout << "\tջ������!����Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	std::cout << "\tջ��Ԫ��Ϊ��" << S->top->data << std::endl;
	system("pause");
	system("cls");
	return S->top->data;
}

//���ջ
Status LStack::clearLStack(LinkStack** S) {

	if ((*S) == NULL || (*S)->count == 0)//ջ������!����Ϊ��
	{
		std::cout << "\tջ������!�����Ѿ�Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkStackPtr temp;
	while ((*S)->top != NULL)
	{
		temp = (*S)->top;//���������ͷ�
		(*S)->top = (*S)->top->next;//����
		delete temp;//�ͷ�
	}

	(*S)->count = 0;//���³���

	std::cout << "\tջ�Ѿ���գ�" << std::endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//����ջ
Status LStack::destroyLStack(LinkStack** S){

	if ((*S) == NULL)//ջ������!
	{
		std::cout << "\tջ�Ѿ�������!" << std::endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkStackPtr temp;
	while ((*S)->top != NULL)
	{
		temp = (*S)->top;//���������ͷ�
		(*S)->top = (*S)->top->next;//����
		delete temp;//�ͷ�
	}
	delete *S;//����ջ��Ҳ�ͷ�
	(*S) = NULL;

	std::cout << "\tջ���ٳɹ���" << std::endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//���ջ����
Status LStack::LStackLength(LinkStack* S) {

	if (S == NULL)//ջ�����ڻ��߱����٣��򲻿�����ջ��
	{
		std::cout << "\tջ������!�����Ѿ����٣�" << std::endl;
		system("pause");
		system("cls");
		return INEXISTENCE;
	}

	std::cout << "\t������ջ����Ϊ��" << S->count << std::endl;
	system("pause");
	system("cls");
	return S->count;
}

//��ջ
Status LStack::pushLStack(LinkStack** S) {

	if (*S == NULL)//ջ�����ڻ��߱����٣��򲻿�����ջ��
	{
		std::cout << "\tջ������!�����Ѿ����٣�" << std::endl;
		system("pause");
		system("cls");
		return INEXISTENCE;
	}
	else 
	{
		LinkStackPtr s = new (StackNode);

		//��ֵ
		std::string data;
		std::cout << "\t�����������ջ��ֵ(�ַ���0����)��";
		std::cin >> data;
		s->data = atoi(data.c_str());

		//��ջ
		s->next = (*S)->top;//����ǰջ��Ԫ�غ���½��
		(*S)->top = s;//ջ��ָ����λ
		(*S)->count++;//����++

		std::cout << "\t��ջ�ɹ�!" << std::endl;
	}
	system("pause");
	system("cls");
	return SUCCESS;
}

//��ջ
Status LStack::popLStack(LinkStack** S) {

	if ((*S) == NULL || (*S)->count == 0)//ջ������!����Ϊ��
	{
		std::cout << "\tջ������!����Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkStackPtr p = (*S)->top;

	int num = p->data;

	(*S)->top = (*S)->top->next;//ջ������
	delete p;
	(*S)->count--;

	std::cout << "\t�����ɹ���" << std::endl;
	system("pause");
	system("cls");
	return num;//���ص�����ֵ
}

//ջ�ı���
Status LStack::TraStack(LinkStack* S) {

	if (S == NULL || S->count == 0)//ջ������!����Ϊ��
	{
		std::cout << "\tջ������!����Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkStackPtr temp = S->top;//����ջ��ָ�������������

	std::cout << "\t";//��������
	while (temp != NULL)
	{
		std::cout << temp->data << "-";
		temp = temp->next;
	}
	std::cout << "ջ��" << std::endl;

	system("pause");
	system("cls");
	return SUCCESS;
}