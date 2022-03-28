#include"LinkStack.h"
#include"Calculator.h"
//链栈

int main()
{

	while (true)
	{
		std::string Select = main_menu();
		if (Select == "1")
		{
			Calculator();
		}
		else if (Select == "2")
		{
			LStack lstack;
			lstack.menu();
		}
		else
		{
			std::cout << "\t感谢您的使用，祝您生活愉快！拜拜~~" << std::endl;
			system("pause");
			return 0;
		}
	}
	return 0;
}