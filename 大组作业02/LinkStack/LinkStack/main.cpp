#include"LinkStack.h"
#include"Calculator.h"
//��ջ

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
			std::cout << "\t��л����ʹ�ã�ף��������죡�ݰ�~~" << std::endl;
			system("pause");
			return 0;
		}
	}
	return 0;
}