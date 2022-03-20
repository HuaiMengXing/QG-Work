#include"Headers.h"

void List()
{
	LinkList L;
	string select;

	ListFunction list;
	
	while (true)
	{
		list.Menu();
		cout << "\t����������ѡ��";
		cin >> select;
		switch (atoi(select.c_str()))
		{
		case 1:list.InitList(&L);
			break;
		case 2:list.ListInsert(&L);
			break;
		case 3:list.ListDelete(&L);
			break;
		case 4:list.TraList(&L);
			break;
		case 5:list.ReverseList(&L);
			break;
		case 6:list.Odd_EvenList(&L);
			break;
		case 7:list.CentreList(&L);
			break;
		case 8:list.ClearList(&L);
			break;
		case 9:list.LoopList(&L);
			break;
		case 0:
			system("cls");
			return;
		default:
			cout << "\t��ѡ����ȷ��ѡ�" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

}

void Dul_List()
{
	Dul_LinkList L;
	string select;

	Dul_ListFunction list;

	while (true)
	{
		list.Dul_Menu();
		cout << "\t����������ѡ��";
		cin >> select;

		switch (atoi(select.c_str()))
		{
		case 1:list.Dul_InitList(&L);
			break;
		case 2:list.Dul_ListInsert(&L);
			break;
		case 3:list.Dul_ListDelete(&L);
			break;
		case 4:list.Dul_TraList(&L);
			break;
		case 5:list.Dul_ClearList(&L);
			break;
		case 6:list.Dul_Check(&L);
			break;
		case 0:
			system("cls");
			return;
		default:
			cout << "\t��ѡ����ȷ��ѡ��!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

int main()
{
	string select;

	while (true)
	{
		cout << "\t* **************����ϵͳ���ܽ���************ *" << endl;
		cout << "\t**********************************************" << endl;
		cout << "\t  1��������   *   2��˫������    *  0���˳�   " << endl;
		cout << "\t**********************************************" << endl;
		cout << "\t��ѡ��";
		cin >> select;
		if (select == "1")
		{
			system("cls");
			List();
		}
		else if (select == "2")
		{
			system("cls");
			Dul_List();
		}
		else if (select == "0")
		{
			return 1;
		}
		else
		{
			cout << "\t������������������!" << endl;
			system("pause");
			system("cls");
		}
	}
	return 1;
}