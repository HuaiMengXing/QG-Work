#include"LQueue.h"


Link_Queue::Link_Queue()
{
}

Link_Queue::~Link_Queue()
{
}

//�˵�
std::string Link_Queue::menu()
{
	std::cout << "\t**************************************************" << std::endl;
	std::cout << "\t* ***************�����й���ϵͳ***************** *" << std::endl;
	std::cout << "\t*  1����������   * 2����  ��      * 3����  ��    *" << std::endl;
	std::cout << "\t*  4�����г���   * 5������ͷԪ��  * 6����������  *" << std::endl;
	std::cout << "\t*  7����ն���   * 8�����ٶ���    * 9���˳�����  *" << std::endl;
	std::cout << "\t**************************************************" << std::endl;
	std::cout << "\t����������ѡ��";

	std::string select;
	std::cin >> select;

	return select;
}

//������ͷ����
void Link_Queue::InitLQueue(LQueue** Q)
{
	if ((*Q) != NULL)
	{
		std::cout << "\t�Ѿ����ڶ��У������������" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	Node* p = new Node;
	(*Q) = new LQueue;
	(*Q)->front = p;
	(*Q)->rear = p;
	(*Q)->length = 0;

	std::cout << "\t�����ɹ���" << std::endl;
	system("pause");
	system("cls");
	return;
}

//���ٶ���
Status Link_Queue::DestoryLQueue(LQueue** Q)
{
	//�ж���״̬
	if (IsEmptyLQueue((*Q)) == -1) {
		std::cout << "\t���в�����!�����Ѿ����٣�" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}
	else if (IsEmptyLQueue((*Q)) == 0) {

		delete (*Q)->front;//ͷ���Ҳ����
		delete* Q;//���ָ��ͷ����Ҳ����
		*Q = NULL;

		std::cout << "\t���ٳɹ���" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}

	Node* p, * q = NULL;
	for (p = (*Q)->front->next; p; p = q)
	{
		q = p->next;
		delete p;
	}
	delete (*Q)->front;//ͷ���Ҳ����
	delete *Q;//���ָ��ͷ����Ҳ����
	*Q = NULL;

	std::cout << "\t���ٳɹ���" << std::endl;
	system("pause");
	system("cls");
	return TRUE;
}

//�������Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue* Q)
{
	if (Q == NULL)//�Ѿ�����
	{
		return -1;
	}
	else if (Q->front == Q->rear)//Ϊ��
	{
		return 0;
	}
	return 1;//��Ϊ��
}

//�鿴���ض�ͷԪ��
void* Link_Queue::GetHeadLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q) == -1) {
		std::cout << "\t���в�����!�����Ѿ����٣�" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}
	else if (IsEmptyLQueue(Q) == 0) {
		std::cout << "\t����Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}

	std::cout << "\t��ͷԪ��Ϊ��";
	LPrint(Q->front->next->data, Q->front->next->size);//��ӡ
	std::cout << std::endl;
	system("pause");
	system("cls");

	return Q->front->data;//����
}

//ȷ�����ض��г���
size_t Link_Queue::LengthLQueue(LQueue* Q)
{
	if (Q == NULL)//�ж�״̬
	{
		std::cout << "\t���в�����!�����Ѿ����٣�" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}

	std::cout << "\t���г���Ϊ��" << Q->length << std::endl;
	system("pause");
	system("cls");
	return Q->length;
}

//��Ӳ���
Status Link_Queue::EnLQueue(LQueue** Q)
{
	if (*Q == NULL)
	{
		std::cout << "\t���в�����!�����Ѿ����٣�" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}

	Node* p = new Node;
	if (p == NULL)
	{
		return FALSE;
	}

	//��ֵ
	p->data = TypeSelect(p->data,p->size);
	p->next = NULL;
	(*Q)->rear->next = p;//�½�㸳��ԭ���н�����
	(*Q)->rear = p;//�ѵ�ǰ�������Ϊ��β���
	(*Q)->length++;//����++

	std::cout << "\t��ӳɹ�!" << std::endl;

	system("pause");
	system("cls");
	return TRUE;
}

//��ֵ
void* TypeSelect(void* data,int& size)
{
	int* Data1 = new int;//���ٿռ䣬�����ȥ��û����
	double* Data2 = new double;
	std::string* Data3 = new std::string;
	std::string Data_3;//������ת��

	std::string select;
	while (true)
	{
		std::cout << "\t* ***************��ֵ����ѡ��******************* *" << std::endl;
		std::cout << "\t*  1��int        * 2��double      * 3��string    *" << std::endl;
		std::cout << "\t* ********************************************** *" << std::endl;
		std::cout << "\t��ѡ������ֵ�����ͣ�";
		std::cin >> select;

		if (select == "1")
		{
			

			std::cout << "\t����������ֵ��";
			std::cin >> *Data1;
			data = Data1;
			size = sizeof(int);//��ֵ�ֽڴ�С����������
			break;
		}
		else if (select == "2")
		{
			std::cout << "\t����������ֵ��";
			std::cin >> *Data2;
			data = Data2;
			size = sizeof(double);//��ֵ�ֽڴ�С����������
			break;
		}
		else if (select == "3")
		{
			std::cout << "\t����������ֵ��";
			std::cin >> Data_3;
			*Data3 = Data_3;//����ֱ�Ӹ�ֵ����ô��תһ��
			data = Data3;
			size = sizeof(std::string);//��ֵ�ֽڴ�С����������
			break;
		}
		else
		{
			std::cout << "\tѡ���������������ѡ��" << std::endl;
			system("pause");
		}
	}
	return data;
}

//���Ӳ���
Status Link_Queue::DeLQueue(LQueue** Q)
{
	//�ж���״̬
	if (IsEmptyLQueue((*Q)) == -1) {
		std::cout << "\t���в�����!�����Ѿ����٣�" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}
	else if (IsEmptyLQueue((*Q)) == 0) {
		std::cout << "\t����Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}

	Node* p = new Node;
	p = (*Q)->front->next;//����ֵ�ͷ�
	(*Q)->front->next = p->next;//����

	if ((*Q)->rear == p)//��ͷ���Ƕ�β�������βָ��ָ��ͷָ��
		(*Q)->rear = (*Q)->front;

	delete p;//�ͷ�
	(*Q)->length--;//����--

	std::cout << "\t���ݳ��ӳɹ���" << std::endl;
	system("pause");
	system("cls");
	return TRUE;
}

//��ն���
Status Link_Queue::ClearLQueue(LQueue** Q)
{
	//�ж���״̬
	if (IsEmptyLQueue((*Q)) == -1) {
		std::cout << "\t���в�����!�����Ѿ����٣�" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}
	else if (IsEmptyLQueue((*Q)) == 0) {
		std::cout << "\t�����Ѿ�Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}

	Node* p,*q = NULL;
	for (p = (*Q)->front->next; p ;p = q)
	{
		q = p->next;
		delete p;
	}
	(*Q)->length = 0;
	(*Q)->rear = (*Q)->front;//βָ��ָ��ͷָ��

	std::cout << "\t��ճɹ���" << std::endl;
	system("pause");
	system("cls");
	return TRUE;
}

//������������
Status Link_Queue::TraverseLQueue(const LQueue* Q)
{
	//�ж���״̬
	if (IsEmptyLQueue(Q) == -1) {
		std::cout << "\t���в�����!�����Ѿ����٣�" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}
	else if (IsEmptyLQueue(Q) == 0) {
		std::cout << "\t����Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}

	Node* p;

	std::cout << "\t";
	for (p = Q->front->next; p != NULL; p = p->next)//����
	{
		LPrint(p->data, p->size);
	}
	std::cout << "NULL" << std::endl;

	system("pause");
	system("cls");
	return TRUE;
}

//��ӡ
void LPrint(void* q,int size)//��void*��Ҫ��ҵ���������ҵ�ֵ
{
	if (size == sizeof(int))
	{
		std::cout << *(int*)q << " - ";
	}
	else if(size == sizeof(double))
	{
		std::cout << *(double*)q << " - ";
	}
	else if (size == sizeof(std::string))
	{
		std::cout << *(std::string*)q << " - ";
	}
}