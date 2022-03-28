#include"LinkStack.h"
#include"Calculator.h"


std::map<char, float> mp;//可以用于字符变成整形
//主界面菜单
std::string main_menu()
{
	std::cout << "\t* ****************************************************** *" << std::endl;
	std::cout << "\t* ********************系统功能界面********************** *" << std::endl;
	std::cout << "\t*      1、计算器功能   * 2、栈功能     * 其他、退出      *" << std::endl;
	std::cout << "\t* ****************************************************** *" << std::endl;
	std::cout << "\t请输入你的选择：";

	std::string select;
	std::cin >> select;

	system("cls");
	return select;
}

//预先处理，防止乱来！！乱输入！！！
std::string Preprocess(std::string str)
{
	int len = (int)str.size();
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (str[i]<'0' || str[i]>'9')
		{
			if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '(' && str[i] != ')' && str[i] != '.'&& str[i]!='=')
			{
				return "#";
			}
		}
	}
	if (str[i-1]!='=')//问题在于不输入=，这些代码虽然不崩溃，但是出来的值就不正确了
	{
		return "#";
	}
	return str;
}

//功能调用
void Calculator()
{
	while (true)
	{
		std::cout << "\t* ****************************************************** *" << std::endl;
		std::cout << "\t* ******************计算器功能系统界面****************** *" << std::endl;
		std::cout << "\t*                                             退出：#    *" << std::endl;
		std::cout << "\t*    注意：不支持'-'在第一位!不支持中文'()'! 如-3+2=     *" << std::endl;
		std::cout << "\t*    可：(-3)+2.5*11-(25+11)/2=                          *" << std::endl;
		std::cout << "\t*    例：3+(2*3)-6+(18/2)*(-2)=                          *" << std::endl;
		std::cout << "\t*                                计算结果：              *" << std::endl;
		std::cout << "\t* ****************************************************** *" << std::endl;
		std::cout << "\t请输入：";

		std::string String;
		std::cin >> String;

		if (String == "#")
		{
			system("pause");
			system("cls");
			return;
		}
		//预先处理String
		std::string STR= Preprocess(String);

		if (STR == "#")
		{
			std::cout << "\t输入错误！请重新输入！" << std::endl;
			system("pause");
			system("cls");
			continue;
		}

		float num = Calculator_empty(STR);
		std::cout << "\t                                    计算结果：" << num << std::endl;
		system("pause");
		system("cls");
	}

}

numStack Num;//整形栈接口
charStack Char;//字符栈接口

//符号优先级判断
int priority(char ch)
{
	int pri = 0;
	if (ch == '=')
	{
		pri = 0;
	}
	if (ch == '(' || ch == ')')
	{
		pri = 1;
	}
	if (ch == '+' || ch == '-')
	{
		pri = 2;
	}
	if (ch == '*' || ch == '/')
	{
		pri = 3;
	}
	return pri;
}

//计算&压入
int count()
{
	float num1 = 0;
	float num2 = 0;
	if (Num.empty())//数字栈不够用，肯定输入错误了
	{
		std::cout << "\t输入错误了！是不是多输入运算符了！" << std::endl;
		return 0;
	}
	else
	{
		num1 = Num.pop();
	}
	
	if (Num.empty())//数字栈不够用，肯定输入错误了
	{
		std::cout << "\t输入错误！是不是多输入运算符了！" << std::endl;
		return 0;
	}
	else
	{
		num2 = Num.pop();
	}

	if(Char.get_head() == '+')
		Num.push(num2 + num1);//将两个数据和再压入栈中
	if(Char.get_head() == '-')
		Num.push(num2 - num1);//将两个数据差再压入栈中
	if(Char.get_head() == '*')
		Num.push(num2 * num1);//将两个数据*再压入栈中
	if(Char.get_head() == '/')
		Num.push(num2 / num1);//将两个数据/再压入栈中

	Char.pop();//弹出符号
	return 1;
}

//压人，计算，弹出流程
float Calculator_empty(std::string& str)
{
	int len = (int)str.size();//取字符串长度
	char ch;
	float l, num;

	for (ch = '0', l = 0; ch <= '9'; ch++, l++) //map方法，字符对应着可以找到相应的整形
		mp[ch] = l;

	for (int i = 0; i < len; ++i)//遍历整个字符串
	{
		if (str[i] == '(' && str[i + 1] == '-' && str[i + 3] == ')')//处理（-3）情况
		{
			i = i+2;
			num = 0;

			for (; str[i] >= '0' && str[i] <= '9'; i++)//可能存在几个整形是在一起的
			{
				num = num * 10 + mp[str[i]];
			}
			i++;//（-3）这些全部都要变成 -3 压入，所有（-3）都没有了，i++
			Num.push(-num);
		}
		
		if (str[i] == '.')//处理小数点情况
		{
			i = i + 1;
			float num1 = 0;
			float den = 1;

			for (; str[i] >= '0' && str[i] <= '9'; i++)//可能存在几个整形是在一起的
			{
				den *= 10;
				num1 = num1 * 10 + mp[str[i]];
			}
			float num2 = Num.pop();//比如这样 2.33   num2=2  num1=33  den=100
			Num.push(num2 + num1/den);
		}

		if (str[i] >= '0' && str[i] <= '9')//整形入口
		{
			num = 0;

			for (; str[i] >= '0' && str[i] <= '9'; i++)//可能存在几个整形是在一起的
			{
				num = num * 10 + mp[str[i]];
			}

			Num.push(num);//入栈
			i--;//因为又要回到for中++
		}
		else//字符入口
		{
			if (Char.empty()) //字符栈为空时直接push ，不用判断优先级
			{
				Char.push(str[i]);
			}
			else if (priority(str[i]) > priority(Char.get_head()) || str[i] == '(' || str[i] == ')')//待入栈运算符优先级高或是'('和')'push 
			{
				Char.push(str[i]);

				if (str[i] == ')')        //为')'时先弹出')' ，找‘（’
				{
					Char.pop();
					if (Char.get_head() != '(') //op.top不为'('时计算括号中运算符 
					{
						if (!count())
						{
							//能进来，说明输入有错误，清空一下栈，防止下次输入出问题
							Num.clear();
							Char.clear();
							return 0;
						}
					}
					Char.pop(); //pop掉'('
				}

			}
			else //待入栈运算符str[i]优先级低于字符栈顶字符时，先对栈顶运算符进行计算
			{
				if (!count())
				{
					//能进来，说明输入有错误，清空一下栈，防止下次输入出问题
					Num.clear();
					Char.clear();
					return 0;
				}				
				Char.push(str[i]); //将str[i]放入字符栈中
			}
			if (!Char.empty())//处理开头（）情况，因为到（这里，会被弹出来，而且还是第一位，所有为空，那么下面Char.get_head()肯定报错
				if (Char.get_head() == '=')//到最后面了
					break;
		}
	}
	if (Char.get_head() == '=')//前面都完成了，那把栈里的数据也全部拿出来计算吧
	{
		Char.pop();
		while (Char.empty() != true)
		{
			if (!count())
			{
				//能进来，说明输入有错误，清空一下栈，防止下次输入出问题
				Num.clear();
				Char.clear();
				return 0;
			}
		}
	}

	float NUM = Num.get_head();
	Num.clear();
	Char.clear();//这里是为了处理第一次输入(1+1=2)正确后，第二次输入多符号那种(1++8=)，结果不报错(=11)，因为第一次的值保留在了栈中
	return NUM;
}