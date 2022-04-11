#include"Binary_sort_tree.h"

int menu()
{
	std::cout << "\t* ********************************************* *" << std::endl;
	std::cout << "\t* ******************����������***************** *" << std::endl;
	std::cout << "\t* 1����������   * 2����������   * 3��ɾ������   *" << std::endl;
	std::cout << "\t* 4���ݹ�ǰ��   * 5���ݹ��б�   * 6���ݹ���   *" << std::endl;
	std::cout << "\t* 7���ǵݹ�ǰ�� * 8���ǵݹ��б� * 9���ǵݹ��� *" << std::endl;
	std::cout << "\t* 10���������  *11���������� *12���������  *" << std::endl;
	std::cout << "\t*             *  ������&0���˳�   *             *" << std::endl;
	std::cout << "\t* ********************************************* *" << std::endl;
	std::cout << "\t����������ѡ��";

	std::string select;
	std::cin >> select;

	return atoi(select.c_str());
}

int main()
{
	//ģ�� int string double char...
	BinarySortTree<int> Tr;
	int select = 0;
	while (true)
	{
		select = menu();
		switch (select)
		{
		case 1:Tr.BST_insert();
			break;
		case 2:Tr.BST_Search();
			break;
		case 3:Tr.BST_delete();
			break;
		case 4:Tr.BST_preorderR();
			break;
		case 5:Tr.BST_inorderR();
			break;
		case 6:Tr.BST_postorderR();
			break;
		case 7:Tr.BST_preorderI();
			break;
		case 8:Tr.BST_inorderI();
			break;
		case 9:Tr.BST_postorderI();
			break;
		case 10:Tr.BST_levelOrder();
			break;
		case 11:Tr.HeapSort();
			break;
		case 12:Tr.BST_clear();
			break;
		case 0:
			std::cout << "\t��л����ʹ�ã�ף��������죡�ݰ�~~"<<std::endl;
			system("pause");
			return 1;
		default:
			std::cout << "\t����������������룡" << std::endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 1;
}