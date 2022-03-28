#include"LQueue.h"


Link_Queue::Link_Queue()
{
}

Link_Queue::~Link_Queue()
{
}

//菜单
std::string Link_Queue::menu()
{
	std::cout << "\t**************************************************" << std::endl;
	std::cout << "\t* ***************链队列功能系统***************** *" << std::endl;
	std::cout << "\t*  1、创建队列   * 2、入  队      * 3、出  队    *" << std::endl;
	std::cout << "\t*  4、队列长度   * 5、队列头元素  * 6、遍历队列  *" << std::endl;
	std::cout << "\t*  7、清空队列   * 8、销毁队列    * 9、退出程序  *" << std::endl;
	std::cout << "\t**************************************************" << std::endl;
	std::cout << "\t请输入您的选择：";

	std::string select;
	std::cin >> select;

	return select;
}

//创建带头队列
void Link_Queue::InitLQueue(LQueue** Q)
{
	if ((*Q) != NULL)
	{
		std::cout << "\t已经存在队列，勿继续创建！" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	Node* p = new Node;
	(*Q) = new LQueue;
	(*Q)->front = p;
	(*Q)->rear = p;
	(*Q)->length = 0;

	std::cout << "\t创建成功！" << std::endl;
	system("pause");
	system("cls");
	return;
}

//销毁队列
Status Link_Queue::DestoryLQueue(LQueue** Q)
{
	//判队列状态
	if (IsEmptyLQueue((*Q)) == -1) {
		std::cout << "\t队列不存在!或者已经销毁！" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}
	else if (IsEmptyLQueue((*Q)) == 0) {

		delete (*Q)->front;//头结点也放了
		delete* Q;//这个指向头结点的也放了
		*Q = NULL;

		std::cout << "\t销毁成功！" << std::endl;
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
	delete (*Q)->front;//头结点也放了
	delete *Q;//这个指向头结点的也放了
	*Q = NULL;

	std::cout << "\t销毁成功！" << std::endl;
	system("pause");
	system("cls");
	return TRUE;
}

//检查队列是否为空
Status IsEmptyLQueue(const LQueue* Q)
{
	if (Q == NULL)//已经销毁
	{
		return -1;
	}
	else if (Q->front == Q->rear)//为空
	{
		return 0;
	}
	return 1;//不为空
}

//查看返回队头元素
void* Link_Queue::GetHeadLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q) == -1) {
		std::cout << "\t队列不存在!或者已经销毁！" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}
	else if (IsEmptyLQueue(Q) == 0) {
		std::cout << "\t队列为空！" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}

	std::cout << "\t队头元素为：";
	LPrint(Q->front->next->data, Q->front->next->size);//打印
	std::cout << std::endl;
	system("pause");
	system("cls");

	return Q->front->data;//返回
}

//确定返回队列长度
size_t Link_Queue::LengthLQueue(LQueue* Q)
{
	if (Q == NULL)//判断状态
	{
		std::cout << "\t队列不存在!或者已经销毁！" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}

	std::cout << "\t队列长度为：" << Q->length << std::endl;
	system("pause");
	system("cls");
	return Q->length;
}

//入队操作
Status Link_Queue::EnLQueue(LQueue** Q)
{
	if (*Q == NULL)
	{
		std::cout << "\t队列不存在!或者已经销毁！" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}

	Node* p = new Node;
	if (p == NULL)
	{
		return FALSE;
	}

	//赋值
	p->data = TypeSelect(p->data,p->size);
	p->next = NULL;
	(*Q)->rear->next = p;//新结点赋给原队列结点后面
	(*Q)->rear = p;//把当前结点设置为队尾结点
	(*Q)->length++;//长度++

	std::cout << "\t入队成功!" << std::endl;

	system("pause");
	system("cls");
	return TRUE;
}

//赋值
void* TypeSelect(void* data,int& size)
{
	int* Data1 = new int;//开辟空间，否则出去就没有了
	double* Data2 = new double;
	std::string* Data3 = new std::string;
	std::string Data_3;//用来中转的

	std::string select;
	while (true)
	{
		std::cout << "\t* ***************赋值类型选择******************* *" << std::endl;
		std::cout << "\t*  1、int        * 2、double      * 3、string    *" << std::endl;
		std::cout << "\t* ********************************************** *" << std::endl;
		std::cout << "\t请选择您的值的类型：";
		std::cin >> select;

		if (select == "1")
		{
			

			std::cout << "\t请输入您的值：";
			std::cin >> *Data1;
			data = Data1;
			size = sizeof(int);//赋值字节大小，用来索引
			break;
		}
		else if (select == "2")
		{
			std::cout << "\t请输入您的值：";
			std::cin >> *Data2;
			data = Data2;
			size = sizeof(double);//赋值字节大小，用来索引
			break;
		}
		else if (select == "3")
		{
			std::cout << "\t请输入您的值：";
			std::cin >> Data_3;
			*Data3 = Data_3;//不能直接赋值，那么中转一下
			data = Data3;
			size = sizeof(std::string);//赋值字节大小，用来索引
			break;
		}
		else
		{
			std::cout << "\t选择错误啦，请重新选择！" << std::endl;
			system("pause");
		}
	}
	return data;
}

//出队操作
Status Link_Queue::DeLQueue(LQueue** Q)
{
	//判队列状态
	if (IsEmptyLQueue((*Q)) == -1) {
		std::cout << "\t队列不存在!或者已经销毁！" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}
	else if (IsEmptyLQueue((*Q)) == 0) {
		std::cout << "\t队列为空！" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}

	Node* p = new Node;
	p = (*Q)->front->next;//保留值释放
	(*Q)->front->next = p->next;//后移

	if ((*Q)->rear == p)//队头就是队尾的情况，尾指针指回头指针
		(*Q)->rear = (*Q)->front;

	delete p;//释放
	(*Q)->length--;//长度--

	std::cout << "\t数据出队成功！" << std::endl;
	system("pause");
	system("cls");
	return TRUE;
}

//清空队列
Status Link_Queue::ClearLQueue(LQueue** Q)
{
	//判队列状态
	if (IsEmptyLQueue((*Q)) == -1) {
		std::cout << "\t队列不存在!或者已经销毁！" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}
	else if (IsEmptyLQueue((*Q)) == 0) {
		std::cout << "\t队列已经为空！" << std::endl;
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
	(*Q)->rear = (*Q)->front;//尾指针指回头指针

	std::cout << "\t清空成功！" << std::endl;
	system("pause");
	system("cls");
	return TRUE;
}

//遍历函数操作
Status Link_Queue::TraverseLQueue(const LQueue* Q)
{
	//判队列状态
	if (IsEmptyLQueue(Q) == -1) {
		std::cout << "\t队列不存在!或者已经销毁！" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}
	else if (IsEmptyLQueue(Q) == 0) {
		std::cout << "\t队列为空！" << std::endl;
		system("pause");
		system("cls");
		return FALSE;
	}

	Node* p;

	std::cout << "\t";
	for (p = Q->front->next; p != NULL; p = p->next)//遍历
	{
		LPrint(p->data, p->size);
	}
	std::cout << "NULL" << std::endl;

	system("pause");
	system("cls");
	return TRUE;
}

//打印
void LPrint(void* q,int size)//对void*的要作业处理，才能找到值
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