#include"Headers.h"


ListFunction::ListFunction()
{
}

ListFunction::~ListFunction()
{
}
//单链表菜单
void ListFunction::Menu()
{
	cout << "\t* ***********单链表系统功能界面************** *" << endl;
	cout << "\t***********************************************" << endl;
	cout << "\t 1、创建链表   * 2、插入数据     * 3、删除数据 " << endl;
	cout << "\t 4、遍历链表   * 5、反转链表     * 6、奇偶调换 " << endl;
	cout << "\t 7、链表中点   * 8、删除整表     * 9、判断成环 " << endl;
	cout << "\t          非数字&&0、退出且删除整表            " << endl;
	cout << "\t***********************************************" << endl;

}

//创建带头结点链表
Status ListFunction::InitList(LinkList* L)
{
	string num ;
	string Data;
	cout << "\t请输入你要构建的结点数(字符当0处理)：";
	cin >> num;

	LinkList p, r;
	*L = new Node;
	r = *L;

	for (int i = 1; i <= atoi(num.c_str()); i++)
	{
		p = new Node;
		cout << "\t请输入第" << i << "数据：";

		cin >> Data;
		p->data = atoi(Data.c_str());

		//r跟上
		r->next = p;
		r = p;
	}
	r->next = NULL;

	//更新长度
	this->ListLengh = atoi(num.c_str());

	system("pause");
	system("cls");
	return SUCCESS;
}

//按输入想查找的数据，返回位置
Status ListFunction::GetPlace(LinkList *L,ElemType e)
{
	int place = 1;//赋值为1，是为了处理插入时，找到的是第一个数据前插的情况
	if (this->ListLengh == 0)//判断链表是否为空
	{
		cout << "\t链表为空！" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}
	else
	{
		LinkList p = *L;
		p = p->next;
		while (p->data != e)
		{
			p = p->next;
			place++;
			if (p == NULL)//找不到
			{
				place = 0;
				break;
			}
		}
		//cout << place << endl;
		return place;
	}
}

//在某数据前后面插入新数据
Status ListFunction::ListInsert(LinkList* L)
{
	if (this->ListLengh == 0)
	{
		cout << "\t链表为空！" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkList p,r;
	p = (*L)->next;//指向第一个结点

	string Data;
	string CheckData;

	cout << "\t请输入想要插入那个数据的前后(字符当0处理)：";
	cin >> CheckData;

	int place = 0;//接收位置
	place = GetPlace(L, atoi(CheckData.c_str()));

	if (place == 0)
	{
		cout << "\t没找到该数据，请检查输入数据！" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}
	else
	{
		while (true)
		{
			string select;
			cout << "\t1、前面  2、后面" << endl;
			cout << "\t请选择插入在前，还是在后：";
			cin >> select;

			if (select == "1")//前插入
			{
				cout << "\t请输入想插入的数据(字符当0处理)：";
				cin >> Data;
				r = new Node;
				r->data = atoi(Data.c_str());//赋值

				if (place == 1)//处理第一位，并且要插入在前面的情况
				{
					r->next = (*L)->next;
					(*L)->next = r;

					//更新长度
					this->ListLengh++;

					break;
				}
				for (int i = 0; i < place - 2; i++)//找到想要插入的数据的前一个数据的位置（做后插）
				{
					p = p->next;
				}
				//插入
				r->next = p->next;
				p->next = r;

				//更新长度
				this->ListLengh++;

				break;
			}
			else if (select == "2")//后插入
			{
				cout << "\t请输入想插入的数据(字符当0处理)：";
				cin >> Data;
				r = new Node;
				r->data = atoi(Data.c_str());//赋值

				for (int i = 0; i < place-1; i++)
				{
					p = p->next;
				}
				//插入
				r->next = p->next;
				p->next = r;

				//更新长度
				this->ListLengh++;

				break;
			}
			else
			{
				cout << "\t请选择正确的选项！" << endl;
			}
		}
	}
	cout << "\t插入成功！" << endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//删除链表第i个数据，用e返回它的值
Status ListFunction::ListDelete(LinkList* L)
{
	if (this->ListLengh == 0)
	{
		cout << "\t链表为空！" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}
	else
	{
		string Data;

		LinkList q = *L;//同时保证可以删除第一个的情况
		LinkList p = *L;
		p = p->next;//指向第一个结点

		cout << "\t请输入你想删除的数据(字符当0处理)：";
		cin >> Data;

		while (p->data != atoi(Data.c_str()))
		{
			q = p; 
			p = p->next;
			if (p == NULL)
			{
				cout << "\t没有找到您想要删除的数据" << endl;
				system("pause");
				system("cls");
				return ERROR;
			}
		}

		//进行删除
		q->next = p->next;
		delete p;
		cout << "\t删除成功！" << endl;

		//更新长度
		this->ListLengh--;
	}
	system("pause");
	system("cls");
	return SUCCESS;
}

//遍历整个链表
Status ListFunction::TraList(LinkList *L)
{
	
	if (this->ListLengh == 0)
	{
		cout << "\t链表为空！" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}
	else
	{
		LinkList p = *L;
		p = p->next;
		cout << "\t";
		while (p != NULL)
		{	
			cout << p->data << "->";
			p = p->next;
		}
		cout << "NULL" << endl;
		system("pause");
		system("cls");
		return SUCCESS;
	}
}

//删除整个链表
Status ListFunction::ClearList(LinkList* L)
{
	if (this->ListLengh == 0)
	{
		cout << "\t链表为空！" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkList p, q;
	p = (*L)->next;//让p指向第一个结点
	while (p)
	{
		q = p->next;//保留下一个结点位置
		delete p;//释放
		p = q;
	}
	(*L)->next = NULL;

	//更新长度
	this->ListLengh = 0;

	cout << "\t删除成功！" << endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//单链表奇偶调换
Status ListFunction::Odd_EvenList(LinkList* L)
{
	if (this->ListLengh == 0)//判断链表是否为空
	{
		cout << "\t链表为空！" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkList pre = *L;
	while (pre->next != NULL && pre->next->next != NULL)
	{
		//创建三个指针指向1、2、3个结点
		LinkList L1 = pre->next;
		LinkList L2 = pre->next->next;
		LinkList L3 = L2->next;

		//进行交换next指向,重新排序前两个奇偶
		L1->next = L3;
		L2->next = L1;
		//带头结点的链表接回
		pre->next = L2;

		//pre移位
		pre = L1;
	}

	cout << "\t两两反转成功!" << endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//找到单链表的中点
Status ListFunction::CentreList(LinkList* L)
{
	//因为我设置了长度，可以直接取中
	//不过，这里还是用快慢指针

	if (this->ListLengh == 0)//判断链表是否为空
	{
		cout << "\t链表为空！" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkList fast = (*L)->next;//快指针
	LinkList slow = (*L)->next;//慢指针
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;//慢指针移动一个位置
		fast = fast->next->next;//快指针移动两个位置
	}

	cout << "\t查找到的中值为：" <<slow->data<< endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//判断链表是否成环
Status ListFunction::LoopList(LinkList* L)
{

	if (this->ListLengh == 0)//判断链表是否为空
	{
		cout << "\t链表为空！" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkList fast = *L;//快指针
	LinkList slow = *L;//慢指针
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;//移动一
		fast = fast->next->next;//移动二
		if (fast == slow)//成环则相等
		{
			cout << "\t链表成环！" << endl;
			system("pause");
			system("cls");
			return SUCCESS;
		}
	}
	cout << "\t没有成环！" << endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//递归反转链表函数实现
LinkList recursive_reverse(LinkList head)
{
	//当只有一个结点，就返回
	if (head->next == NULL)
	{
		return head;
	}
	else
	{
		//递归到最后
		LinkList new_head = recursive_reverse(head->next);

		//改变指向
		head->next->next = head;
		head->next = NULL;

		return new_head;
	}
}

//反转链表（递归和非递归)
Status ListFunction::ReverseList(LinkList* L)
{
	if (this->ListLengh == 0)//判断链表是否为空
	{
		cout << "\t链表为空！" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	system("cls");
	cout << "\t* *************反转链表功能界面************** *" << endl;
	cout << "\t***********************************************" << endl;
	cout << "\t 1、迭代反转   * 2、递归反转     * 3、头插反转 " << endl;
	cout << "\t              其他选项视为、退出               " << endl;
	cout << "\t***********************************************" << endl;
	cout << "\t请输入你的选择：";


	string select;
	cin >> select;

	if (select == "1")
	{
		//迭代反转链表
		//第一个指针
		LinkList beg = NULL;
		//第二个指针
		LinkList mid = (*L)->next;
		//第三个指针
		LinkList end = (*L)->next->next;

		//遍历
		while (true)
		{
			//修改mid的指向
			mid->next = beg;

			if (end == NULL)
			{
				break;
			}

			//后移
			beg = mid;
			mid = end;
			end = end->next;
		}
		//最后修改头指向
		(*L)->next = mid;
	}
	else if (select == "2")
	{
		LinkList head = (*L)->next;
		//递归反转链表
		(*L)->next = recursive_reverse(head);
	}
	else if (select == "3")
	{
		LinkList head = (*L)->next;
		//头插反转链表
		LinkList new_head = NULL;//相当于新链表
		LinkList temp = NULL;//配合head一个个头插入new_head

		while(head != NULL)
		{
			temp = head;

			//后移head，保留下一个结点位置
			head = head->next;

			//更改指向
			temp->next = new_head;
			new_head = temp;//跟上
		}
		//接回L中
		(*L)->next = new_head;
	}
	else
	{
		system("pause");
		system("cls");
		return ERROR;
	}

	cout << "\t反转链表成功！" << endl;
	system("pause");
	system("cls");
	return SUCCESS;
}






Dul_ListFunction::Dul_ListFunction()
{
}

Dul_ListFunction::~Dul_ListFunction()
{
}

//双向链表菜单
void Dul_ListFunction::Dul_Menu()
{
	cout << "\t* ************双向链表系统功能界面*********** *" << endl;
	cout << "\t***********************************************" << endl;
	cout << "\t 1、创建链表  * 2、插入数据      * 3、删除数据 " << endl;
	cout << "\t 4、遍历链表  * 5、删除整个链表  * 6、查找数据 " << endl;
	cout << "\t          非数字&&0、退出且删除整表            " << endl;
	cout << "\t***********************************************" << endl;
}

//创建带头结点双向链表
Status Dul_ListFunction::Dul_InitList(Dul_LinkList* L)
{
	string num;
	string Data;
	cout << "\t请输入你要构建的结点数(字符当0处理)：";
	cin >> num;

	Dul_LinkList p, r;
	*L = new Dul_Node;
	(*L)->prior = NULL;//前指为空

	r = *L;
	for (int i = 1; i <= atoi(num.c_str()); i++)
	{
		p = new Dul_Node;
		cout << "\t请输入第" << i << "数据：";
		cin >> Data;
		p->data = atoi(Data.c_str());

		//双双指向
		r->next = p;
		p->prior = r;

		r = p;
	}
	r->next = NULL;

	//更新长度
	this->Dul_ListLengh = atoi(num.c_str());

	system("pause");
	system("cls");
	return SUCCESS;

}

//查找想要的数据
Status Dul_ListFunction::Dul_Check(Dul_LinkList* L)
{
	if (this->Dul_ListLengh == 0)
	{
		cout << "\t链表为空！" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}
	else
	{
		string Data;
		cout << "\t请输入你想要查找的数据(字符当0处理)：";
		cin >> Data;

		Dul_LinkList p = *L;
		p = p->next;

		while (p->data != atoi(Data.c_str()))
		{
			p = p->next;
			if (p == NULL)
			{
				cout << "\t链表中不存在该数据" << endl;
				system("pause");
				system("cls");
				return ERROR;
			}
		}
		cout << "\t该数据存在！" << endl;
	}
	system("pause");
	system("cls");
	return SUCCESS;
}

//在某数据前后面插入新数据（这里与什么单链表不同，直接利用双向链表的特性前后插入）
Status Dul_ListFunction::Dul_ListInsert(Dul_LinkList* L)
{
	if (this->Dul_ListLengh == 0)
	{
		cout << "\t链表为空！" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	Dul_LinkList p, r;
	p = (*L)->next;

	string Data;
	string CheckData;

	cout << "\t请输入想要插入那个数据的前后(字符当0处理)：";
	cin >> CheckData;

	while (p->data != atoi(CheckData.c_str()))//让p指向想要找的那个结点
	{
		p = p->next;
		if (p == NULL)
		{
			cout << "\t没找到该数据，请检查输入数据！" << endl;
			system("pause");
			system("cls");
			return ERROR;
		}
	}

	while (true)
	{
		string select;
		cout << "\t1、前面  2、后面" << endl;
		cout << "\t请选择插入在前，还是在后：";
		cin >> select;

		if (select == "1")//前插入
		{
			cout << "\t请输入想插入的数据(字符当0处理)：";
			cin >> Data;
			r = new Dul_Node;
			r->data = atoi(Data.c_str());//赋值

			r->prior = p->prior;
			p->prior->next = r;
			r->next = p;
			p->prior = r;

			//更新长度
			this->Dul_ListLengh++;

			break;
		}
		else if (select == "2")//后插入
		{
			cout << "\t请输入想插入的数据(字符当0处理)：";
			cin >> Data;
			r = new Dul_Node;
			r->data = atoi(Data.c_str());//赋值

			if (p->next == NULL)//处理在最后的情况
			{
				r->next = p->next;
				r->prior = p;
				p->next = r;

				//更新长度
				this->Dul_ListLengh++;

				break;
			}

			r->prior = p;
			r->next = p->next;
			p->next->prior = r;
			p->next = r;

			//更新长度
			this->Dul_ListLengh++;

			break;
		}
		else
		{
			cout << "\t请选择正确的选项！" << endl;
		}
	}
	cout << "\t插入成功！" << endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//删除链表中数据
Status Dul_ListFunction::Dul_ListDelete(Dul_LinkList* L)
{
	if (this->Dul_ListLengh == 0)
	{
		cout << "\t链表为空！" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}
	else
	{
		string Data;

		Dul_LinkList p = *L;
		p = p->next;//指向第一个结点

		cout << "\t请输入你想删除的数据(字符当0处理)：";
		cin >> Data;

		while (p->data != atoi(Data.c_str()))//让p指向想要找的那个结点位置
		{
			p = p->next;
			if (p == NULL)
			{
				cout << "\t没有找到您想要删除的数据" << endl;
				system("pause");
				system("cls");
				return ERROR;
			}
		}

		if (p->next == NULL)//处理最后的情况
		{
			//让前面结点指向空
			p->prior->next = NULL;
			delete p;

			cout << "\t删除成功！" << endl;

			//更新长度
			this->Dul_ListLengh--;

			system("pause");
			system("cls");
			return SUCCESS;
		}

		//进行删除
		p->prior->next = p->next;
		p->next->prior = p->prior;
		delete p;

		cout << "删除成功！" << endl;

		//更新长度
		this->Dul_ListLengh--;
	}
	system("pause");
	system("cls");
	return SUCCESS;
}

//遍历整个链表（跟单链表差不多）
Status Dul_ListFunction::Dul_TraList(Dul_LinkList* L)
{
	if (this->Dul_ListLengh == 0)
	{
		cout << "\t链表为空！" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}
	else
	{
		Dul_LinkList p = *L;
		p = p->next;
		cout << "\t";
		while (p != NULL)
		{
			cout << p->data << "<->";
			p = p->next;
		}
		cout << "NULL" << endl;
		system("pause");
		system("cls");
		return SUCCESS;
	}
}

//删除整个链表（跟单链表差不多）
Status Dul_ListFunction::Dul_ClearList(Dul_LinkList* L)
{
	if (this->Dul_ListLengh == 0)
	{
		cout << "\t链表为空！" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	Dul_LinkList p, q;
	p = (*L)->next;//让p指向第一个结点

	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	(*L)->next = NULL;

	//更新长度
	this->Dul_ListLengh = 0;

	cout << "\t删除成功！" << endl;
	system("pause");
	system("cls");
	return SUCCESS;
}
