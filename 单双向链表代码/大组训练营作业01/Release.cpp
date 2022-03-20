#include"Headers.h"


ListFunction::ListFunction()
{
}

ListFunction::~ListFunction()
{
}
//������˵�
void ListFunction::Menu()
{
	cout << "\t* ***********������ϵͳ���ܽ���************** *" << endl;
	cout << "\t***********************************************" << endl;
	cout << "\t 1����������   * 2����������     * 3��ɾ������ " << endl;
	cout << "\t 4����������   * 5����ת����     * 6����ż���� " << endl;
	cout << "\t 7�������е�   * 8��ɾ������     * 9���жϳɻ� " << endl;
	cout << "\t          ������&&0���˳���ɾ������            " << endl;
	cout << "\t***********************************************" << endl;

}

//������ͷ�������
Status ListFunction::InitList(LinkList* L)
{
	string num ;
	string Data;
	cout << "\t��������Ҫ�����Ľ����(�ַ���0����)��";
	cin >> num;

	LinkList p, r;
	*L = new Node;
	r = *L;

	for (int i = 1; i <= atoi(num.c_str()); i++)
	{
		p = new Node;
		cout << "\t�������" << i << "���ݣ�";

		cin >> Data;
		p->data = atoi(Data.c_str());

		//r����
		r->next = p;
		r = p;
	}
	r->next = NULL;

	//���³���
	this->ListLengh = atoi(num.c_str());

	system("pause");
	system("cls");
	return SUCCESS;
}

//����������ҵ����ݣ�����λ��
Status ListFunction::GetPlace(LinkList *L,ElemType e)
{
	int place = 1;//��ֵΪ1����Ϊ�˴������ʱ���ҵ����ǵ�һ������ǰ������
	if (this->ListLengh == 0)//�ж������Ƿ�Ϊ��
	{
		cout << "\t����Ϊ�գ�" << endl;
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
			if (p == NULL)//�Ҳ���
			{
				place = 0;
				break;
			}
		}
		//cout << place << endl;
		return place;
	}
}

//��ĳ����ǰ�������������
Status ListFunction::ListInsert(LinkList* L)
{
	if (this->ListLengh == 0)
	{
		cout << "\t����Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkList p,r;
	p = (*L)->next;//ָ���һ�����

	string Data;
	string CheckData;

	cout << "\t��������Ҫ�����Ǹ����ݵ�ǰ��(�ַ���0����)��";
	cin >> CheckData;

	int place = 0;//����λ��
	place = GetPlace(L, atoi(CheckData.c_str()));

	if (place == 0)
	{
		cout << "\tû�ҵ������ݣ������������ݣ�" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}
	else
	{
		while (true)
		{
			string select;
			cout << "\t1��ǰ��  2������" << endl;
			cout << "\t��ѡ�������ǰ�������ں�";
			cin >> select;

			if (select == "1")//ǰ����
			{
				cout << "\t����������������(�ַ���0����)��";
				cin >> Data;
				r = new Node;
				r->data = atoi(Data.c_str());//��ֵ

				if (place == 1)//�����һλ������Ҫ������ǰ������
				{
					r->next = (*L)->next;
					(*L)->next = r;

					//���³���
					this->ListLengh++;

					break;
				}
				for (int i = 0; i < place - 2; i++)//�ҵ���Ҫ��������ݵ�ǰһ�����ݵ�λ�ã�����壩
				{
					p = p->next;
				}
				//����
				r->next = p->next;
				p->next = r;

				//���³���
				this->ListLengh++;

				break;
			}
			else if (select == "2")//�����
			{
				cout << "\t����������������(�ַ���0����)��";
				cin >> Data;
				r = new Node;
				r->data = atoi(Data.c_str());//��ֵ

				for (int i = 0; i < place-1; i++)
				{
					p = p->next;
				}
				//����
				r->next = p->next;
				p->next = r;

				//���³���
				this->ListLengh++;

				break;
			}
			else
			{
				cout << "\t��ѡ����ȷ��ѡ�" << endl;
			}
		}
	}
	cout << "\t����ɹ���" << endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//ɾ�������i�����ݣ���e��������ֵ
Status ListFunction::ListDelete(LinkList* L)
{
	if (this->ListLengh == 0)
	{
		cout << "\t����Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}
	else
	{
		string Data;

		LinkList q = *L;//ͬʱ��֤����ɾ����һ�������
		LinkList p = *L;
		p = p->next;//ָ���һ�����

		cout << "\t����������ɾ��������(�ַ���0����)��";
		cin >> Data;

		while (p->data != atoi(Data.c_str()))
		{
			q = p; 
			p = p->next;
			if (p == NULL)
			{
				cout << "\tû���ҵ�����Ҫɾ��������" << endl;
				system("pause");
				system("cls");
				return ERROR;
			}
		}

		//����ɾ��
		q->next = p->next;
		delete p;
		cout << "\tɾ���ɹ���" << endl;

		//���³���
		this->ListLengh--;
	}
	system("pause");
	system("cls");
	return SUCCESS;
}

//������������
Status ListFunction::TraList(LinkList *L)
{
	
	if (this->ListLengh == 0)
	{
		cout << "\t����Ϊ�գ�" << endl;
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

//ɾ����������
Status ListFunction::ClearList(LinkList* L)
{
	if (this->ListLengh == 0)
	{
		cout << "\t����Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkList p, q;
	p = (*L)->next;//��pָ���һ�����
	while (p)
	{
		q = p->next;//������һ�����λ��
		delete p;//�ͷ�
		p = q;
	}
	(*L)->next = NULL;

	//���³���
	this->ListLengh = 0;

	cout << "\tɾ���ɹ���" << endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//��������ż����
Status ListFunction::Odd_EvenList(LinkList* L)
{
	if (this->ListLengh == 0)//�ж������Ƿ�Ϊ��
	{
		cout << "\t����Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkList pre = *L;
	while (pre->next != NULL && pre->next->next != NULL)
	{
		//��������ָ��ָ��1��2��3�����
		LinkList L1 = pre->next;
		LinkList L2 = pre->next->next;
		LinkList L3 = L2->next;

		//���н���nextָ��,��������ǰ������ż
		L1->next = L3;
		L2->next = L1;
		//��ͷ��������ӻ�
		pre->next = L2;

		//pre��λ
		pre = L1;
	}

	cout << "\t������ת�ɹ�!" << endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//�ҵ���������е�
Status ListFunction::CentreList(LinkList* L)
{
	//��Ϊ�������˳��ȣ�����ֱ��ȡ��
	//���������ﻹ���ÿ���ָ��

	if (this->ListLengh == 0)//�ж������Ƿ�Ϊ��
	{
		cout << "\t����Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkList fast = (*L)->next;//��ָ��
	LinkList slow = (*L)->next;//��ָ��
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;//��ָ���ƶ�һ��λ��
		fast = fast->next->next;//��ָ���ƶ�����λ��
	}

	cout << "\t���ҵ�����ֵΪ��" <<slow->data<< endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//�ж������Ƿ�ɻ�
Status ListFunction::LoopList(LinkList* L)
{

	if (this->ListLengh == 0)//�ж������Ƿ�Ϊ��
	{
		cout << "\t����Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkList fast = *L;//��ָ��
	LinkList slow = *L;//��ָ��
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;//�ƶ�һ
		fast = fast->next->next;//�ƶ���
		if (fast == slow)//�ɻ������
		{
			cout << "\t����ɻ���" << endl;
			system("pause");
			system("cls");
			return SUCCESS;
		}
	}
	cout << "\tû�гɻ���" << endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//�ݹ鷴ת������ʵ��
LinkList recursive_reverse(LinkList head)
{
	//��ֻ��һ����㣬�ͷ���
	if (head->next == NULL)
	{
		return head;
	}
	else
	{
		//�ݹ鵽���
		LinkList new_head = recursive_reverse(head->next);

		//�ı�ָ��
		head->next->next = head;
		head->next = NULL;

		return new_head;
	}
}

//��ת�����ݹ�ͷǵݹ�)
Status ListFunction::ReverseList(LinkList* L)
{
	if (this->ListLengh == 0)//�ж������Ƿ�Ϊ��
	{
		cout << "\t����Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	system("cls");
	cout << "\t* *************��ת�����ܽ���************** *" << endl;
	cout << "\t***********************************************" << endl;
	cout << "\t 1��������ת   * 2���ݹ鷴ת     * 3��ͷ�巴ת " << endl;
	cout << "\t              ����ѡ����Ϊ���˳�               " << endl;
	cout << "\t***********************************************" << endl;
	cout << "\t���������ѡ��";


	string select;
	cin >> select;

	if (select == "1")
	{
		//������ת����
		//��һ��ָ��
		LinkList beg = NULL;
		//�ڶ���ָ��
		LinkList mid = (*L)->next;
		//������ָ��
		LinkList end = (*L)->next->next;

		//����
		while (true)
		{
			//�޸�mid��ָ��
			mid->next = beg;

			if (end == NULL)
			{
				break;
			}

			//����
			beg = mid;
			mid = end;
			end = end->next;
		}
		//����޸�ͷָ��
		(*L)->next = mid;
	}
	else if (select == "2")
	{
		LinkList head = (*L)->next;
		//�ݹ鷴ת����
		(*L)->next = recursive_reverse(head);
	}
	else if (select == "3")
	{
		LinkList head = (*L)->next;
		//ͷ�巴ת����
		LinkList new_head = NULL;//�൱��������
		LinkList temp = NULL;//���headһ����ͷ����new_head

		while(head != NULL)
		{
			temp = head;

			//����head��������һ�����λ��
			head = head->next;

			//����ָ��
			temp->next = new_head;
			new_head = temp;//����
		}
		//�ӻ�L��
		(*L)->next = new_head;
	}
	else
	{
		system("pause");
		system("cls");
		return ERROR;
	}

	cout << "\t��ת����ɹ���" << endl;
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

//˫������˵�
void Dul_ListFunction::Dul_Menu()
{
	cout << "\t* ************˫������ϵͳ���ܽ���*********** *" << endl;
	cout << "\t***********************************************" << endl;
	cout << "\t 1����������  * 2����������      * 3��ɾ������ " << endl;
	cout << "\t 4����������  * 5��ɾ����������  * 6���������� " << endl;
	cout << "\t          ������&&0���˳���ɾ������            " << endl;
	cout << "\t***********************************************" << endl;
}

//������ͷ���˫������
Status Dul_ListFunction::Dul_InitList(Dul_LinkList* L)
{
	string num;
	string Data;
	cout << "\t��������Ҫ�����Ľ����(�ַ���0����)��";
	cin >> num;

	Dul_LinkList p, r;
	*L = new Dul_Node;
	(*L)->prior = NULL;//ǰָΪ��

	r = *L;
	for (int i = 1; i <= atoi(num.c_str()); i++)
	{
		p = new Dul_Node;
		cout << "\t�������" << i << "���ݣ�";
		cin >> Data;
		p->data = atoi(Data.c_str());

		//˫˫ָ��
		r->next = p;
		p->prior = r;

		r = p;
	}
	r->next = NULL;

	//���³���
	this->Dul_ListLengh = atoi(num.c_str());

	system("pause");
	system("cls");
	return SUCCESS;

}

//������Ҫ������
Status Dul_ListFunction::Dul_Check(Dul_LinkList* L)
{
	if (this->Dul_ListLengh == 0)
	{
		cout << "\t����Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}
	else
	{
		string Data;
		cout << "\t����������Ҫ���ҵ�����(�ַ���0����)��";
		cin >> Data;

		Dul_LinkList p = *L;
		p = p->next;

		while (p->data != atoi(Data.c_str()))
		{
			p = p->next;
			if (p == NULL)
			{
				cout << "\t�����в����ڸ�����" << endl;
				system("pause");
				system("cls");
				return ERROR;
			}
		}
		cout << "\t�����ݴ��ڣ�" << endl;
	}
	system("pause");
	system("cls");
	return SUCCESS;
}

//��ĳ����ǰ������������ݣ�������ʲô������ͬ��ֱ������˫�����������ǰ����룩
Status Dul_ListFunction::Dul_ListInsert(Dul_LinkList* L)
{
	if (this->Dul_ListLengh == 0)
	{
		cout << "\t����Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	Dul_LinkList p, r;
	p = (*L)->next;

	string Data;
	string CheckData;

	cout << "\t��������Ҫ�����Ǹ����ݵ�ǰ��(�ַ���0����)��";
	cin >> CheckData;

	while (p->data != atoi(CheckData.c_str()))//��pָ����Ҫ�ҵ��Ǹ����
	{
		p = p->next;
		if (p == NULL)
		{
			cout << "\tû�ҵ������ݣ������������ݣ�" << endl;
			system("pause");
			system("cls");
			return ERROR;
		}
	}

	while (true)
	{
		string select;
		cout << "\t1��ǰ��  2������" << endl;
		cout << "\t��ѡ�������ǰ�������ں�";
		cin >> select;

		if (select == "1")//ǰ����
		{
			cout << "\t����������������(�ַ���0����)��";
			cin >> Data;
			r = new Dul_Node;
			r->data = atoi(Data.c_str());//��ֵ

			r->prior = p->prior;
			p->prior->next = r;
			r->next = p;
			p->prior = r;

			//���³���
			this->Dul_ListLengh++;

			break;
		}
		else if (select == "2")//�����
		{
			cout << "\t����������������(�ַ���0����)��";
			cin >> Data;
			r = new Dul_Node;
			r->data = atoi(Data.c_str());//��ֵ

			if (p->next == NULL)//�������������
			{
				r->next = p->next;
				r->prior = p;
				p->next = r;

				//���³���
				this->Dul_ListLengh++;

				break;
			}

			r->prior = p;
			r->next = p->next;
			p->next->prior = r;
			p->next = r;

			//���³���
			this->Dul_ListLengh++;

			break;
		}
		else
		{
			cout << "\t��ѡ����ȷ��ѡ�" << endl;
		}
	}
	cout << "\t����ɹ���" << endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//ɾ������������
Status Dul_ListFunction::Dul_ListDelete(Dul_LinkList* L)
{
	if (this->Dul_ListLengh == 0)
	{
		cout << "\t����Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}
	else
	{
		string Data;

		Dul_LinkList p = *L;
		p = p->next;//ָ���һ�����

		cout << "\t����������ɾ��������(�ַ���0����)��";
		cin >> Data;

		while (p->data != atoi(Data.c_str()))//��pָ����Ҫ�ҵ��Ǹ����λ��
		{
			p = p->next;
			if (p == NULL)
			{
				cout << "\tû���ҵ�����Ҫɾ��������" << endl;
				system("pause");
				system("cls");
				return ERROR;
			}
		}

		if (p->next == NULL)//�����������
		{
			//��ǰ����ָ���
			p->prior->next = NULL;
			delete p;

			cout << "\tɾ���ɹ���" << endl;

			//���³���
			this->Dul_ListLengh--;

			system("pause");
			system("cls");
			return SUCCESS;
		}

		//����ɾ��
		p->prior->next = p->next;
		p->next->prior = p->prior;
		delete p;

		cout << "ɾ���ɹ���" << endl;

		//���³���
		this->Dul_ListLengh--;
	}
	system("pause");
	system("cls");
	return SUCCESS;
}

//���������������������ࣩ
Status Dul_ListFunction::Dul_TraList(Dul_LinkList* L)
{
	if (this->Dul_ListLengh == 0)
	{
		cout << "\t����Ϊ�գ�" << endl;
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

//ɾ�������������������ࣩ
Status Dul_ListFunction::Dul_ClearList(Dul_LinkList* L)
{
	if (this->Dul_ListLengh == 0)
	{
		cout << "\t����Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	Dul_LinkList p, q;
	p = (*L)->next;//��pָ���һ�����

	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	(*L)->next = NULL;

	//���³���
	this->Dul_ListLengh = 0;

	cout << "\tɾ���ɹ���" << endl;
	system("pause");
	system("cls");
	return SUCCESS;
}
