#include"Sort.h"

int main()
{
	Data* L;
	L = new Data;
	SaveRecore();//随机输入数据&保存在文件中

	while (true)
	{
		int select = Menu();//得到用户选择
		switch (select)
		{
		case 1:
			Insert_Sort(L);
			break;
		case 2:
			Merge_Array(L);
			break;
		case 3:
			QSort_Recursion(L);
			break;
		case 4:
			Count_Sort(L);
			break;
		case 5:
			ColorSort();
			break;
		case 6:
			Quick_Sort(L);
			break;
		case 7:
			Radix_CountSort(L);
			break;
		case 8:
			FindSort(L);
			break;
		case 9:
			BigData_Sort(L);
			break;
		case 10:
			system("cls");
			SaveRecore();//随机输入数据&保存在文件中
			break;
		default:
			std::cout << "\t再见啦！拜拜~~~" << std::endl;
			system("pause");
			exit(0);
			break;
		}
	}	
	return 1;
}