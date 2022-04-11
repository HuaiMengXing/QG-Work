#include"Binary_sort_tree.h"

int menu()
{
	std::cout << "\t* ********************************************* *" << std::endl;
	std::cout << "\t* ******************二叉树排序***************** *" << std::endl;
	std::cout << "\t* 1、插入数据   * 2、查找数据   * 3、删除数据   *" << std::endl;
	std::cout << "\t* 4、递归前遍   * 5、递归中遍   * 6、递归后遍   *" << std::endl;
	std::cout << "\t* 7、非递归前遍 * 8、非递归中遍 * 9、非递归后遍 *" << std::endl;
	std::cout << "\t* 10、层序遍历  *11、堆排序功能 *12、清空数据  *" << std::endl;
	std::cout << "\t*             *  非数字&0、退出   *             *" << std::endl;
	std::cout << "\t* ********************************************* *" << std::endl;
	std::cout << "\t请输入您的选择：";

	std::string select;
	std::cin >> select;

	return atoi(select.c_str());
}

int main()
{
	//模板 int string double char...
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
			std::cout << "\t感谢您的使用，祝您生活愉快！拜拜~~"<<std::endl;
			system("pause");
			return 1;
		default:
			std::cout << "\t输入错误！请重新输入！" << std::endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 1;
}