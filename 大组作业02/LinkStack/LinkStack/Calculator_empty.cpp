#include"LinkStack.h"
#include"Calculator.h"


std::map<char, float> mp;//���������ַ��������
//������˵�
std::string main_menu()
{
	std::cout << "\t* ****************************************************** *" << std::endl;
	std::cout << "\t* ********************ϵͳ���ܽ���********************** *" << std::endl;
	std::cout << "\t*      1������������   * 2��ջ����     * �������˳�      *" << std::endl;
	std::cout << "\t* ****************************************************** *" << std::endl;
	std::cout << "\t���������ѡ��";

	std::string select;
	std::cin >> select;

	system("cls");
	return select;
}

//Ԥ�ȴ�����ֹ�������������룡����
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
	if (str[i-1]!='=')//�������ڲ�����=����Щ������Ȼ�����������ǳ�����ֵ�Ͳ���ȷ��
	{
		return "#";
	}
	return str;
}

//���ܵ���
void Calculator()
{
	while (true)
	{
		std::cout << "\t* ****************************************************** *" << std::endl;
		std::cout << "\t* ******************����������ϵͳ����****************** *" << std::endl;
		std::cout << "\t*                                             �˳���#    *" << std::endl;
		std::cout << "\t*    ע�⣺��֧��'-'�ڵ�һλ!��֧������'()'! ��-3+2=     *" << std::endl;
		std::cout << "\t*    �ɣ�(-3)+2.5*11-(25+11)/2=                          *" << std::endl;
		std::cout << "\t*    ����3+(2*3)-6+(18/2)*(-2)=                          *" << std::endl;
		std::cout << "\t*                                ��������              *" << std::endl;
		std::cout << "\t* ****************************************************** *" << std::endl;
		std::cout << "\t�����룺";

		std::string String;
		std::cin >> String;

		if (String == "#")
		{
			system("pause");
			system("cls");
			return;
		}
		//Ԥ�ȴ���String
		std::string STR= Preprocess(String);

		if (STR == "#")
		{
			std::cout << "\t����������������룡" << std::endl;
			system("pause");
			system("cls");
			continue;
		}

		float num = Calculator_empty(STR);
		std::cout << "\t                                    ��������" << num << std::endl;
		system("pause");
		system("cls");
	}

}

numStack Num;//����ջ�ӿ�
charStack Char;//�ַ�ջ�ӿ�

//�������ȼ��ж�
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

//����&ѹ��
int count()
{
	float num1 = 0;
	float num2 = 0;
	if (Num.empty())//����ջ�����ã��϶����������
	{
		std::cout << "\t��������ˣ��ǲ��Ƕ�����������ˣ�" << std::endl;
		return 0;
	}
	else
	{
		num1 = Num.pop();
	}
	
	if (Num.empty())//����ջ�����ã��϶����������
	{
		std::cout << "\t��������ǲ��Ƕ�����������ˣ�" << std::endl;
		return 0;
	}
	else
	{
		num2 = Num.pop();
	}

	if(Char.get_head() == '+')
		Num.push(num2 + num1);//���������ݺ���ѹ��ջ��
	if(Char.get_head() == '-')
		Num.push(num2 - num1);//���������ݲ���ѹ��ջ��
	if(Char.get_head() == '*')
		Num.push(num2 * num1);//����������*��ѹ��ջ��
	if(Char.get_head() == '/')
		Num.push(num2 / num1);//����������/��ѹ��ջ��

	Char.pop();//��������
	return 1;
}

//ѹ�ˣ����㣬��������
float Calculator_empty(std::string& str)
{
	int len = (int)str.size();//ȡ�ַ�������
	char ch;
	float l, num;

	for (ch = '0', l = 0; ch <= '9'; ch++, l++) //map�������ַ���Ӧ�ſ����ҵ���Ӧ������
		mp[ch] = l;

	for (int i = 0; i < len; ++i)//���������ַ���
	{
		if (str[i] == '(' && str[i + 1] == '-' && str[i + 3] == ')')//����-3�����
		{
			i = i+2;
			num = 0;

			for (; str[i] >= '0' && str[i] <= '9'; i++)//���ܴ��ڼ�����������һ���
			{
				num = num * 10 + mp[str[i]];
			}
			i++;//��-3����Щȫ����Ҫ��� -3 ѹ�룬���У�-3����û���ˣ�i++
			Num.push(-num);
		}
		
		if (str[i] == '.')//����С�������
		{
			i = i + 1;
			float num1 = 0;
			float den = 1;

			for (; str[i] >= '0' && str[i] <= '9'; i++)//���ܴ��ڼ�����������һ���
			{
				den *= 10;
				num1 = num1 * 10 + mp[str[i]];
			}
			float num2 = Num.pop();//�������� 2.33   num2=2  num1=33  den=100
			Num.push(num2 + num1/den);
		}

		if (str[i] >= '0' && str[i] <= '9')//�������
		{
			num = 0;

			for (; str[i] >= '0' && str[i] <= '9'; i++)//���ܴ��ڼ�����������һ���
			{
				num = num * 10 + mp[str[i]];
			}

			Num.push(num);//��ջ
			i--;//��Ϊ��Ҫ�ص�for��++
		}
		else//�ַ����
		{
			if (Char.empty()) //�ַ�ջΪ��ʱֱ��push �������ж����ȼ�
			{
				Char.push(str[i]);
			}
			else if (priority(str[i]) > priority(Char.get_head()) || str[i] == '(' || str[i] == ')')//����ջ��������ȼ��߻���'('��')'push 
			{
				Char.push(str[i]);

				if (str[i] == ')')        //Ϊ')'ʱ�ȵ���')' ���ҡ�����
				{
					Char.pop();
					if (Char.get_head() != '(') //op.top��Ϊ'('ʱ��������������� 
					{
						if (!count())
						{
							//�ܽ�����˵�������д������һ��ջ����ֹ�´����������
							Num.clear();
							Char.clear();
							return 0;
						}
					}
					Char.pop(); //pop��'('
				}

			}
			else //����ջ�����str[i]���ȼ������ַ�ջ���ַ�ʱ���ȶ�ջ����������м���
			{
				if (!count())
				{
					//�ܽ�����˵�������д������һ��ջ����ֹ�´����������
					Num.clear();
					Char.clear();
					return 0;
				}				
				Char.push(str[i]); //��str[i]�����ַ�ջ��
			}
			if (!Char.empty())//����ͷ�����������Ϊ��������ᱻ�����������һ��ǵ�һλ������Ϊ�գ���ô����Char.get_head()�϶�����
				if (Char.get_head() == '=')//���������
					break;
		}
	}
	if (Char.get_head() == '=')//ǰ�涼����ˣ��ǰ�ջ�������Ҳȫ���ó��������
	{
		Char.pop();
		while (Char.empty() != true)
		{
			if (!count())
			{
				//�ܽ�����˵�������д������һ��ջ����ֹ�´����������
				Num.clear();
				Char.clear();
				return 0;
			}
		}
	}

	float NUM = Num.get_head();
	Num.clear();
	Char.clear();//������Ϊ�˴����һ������(1+1=2)��ȷ�󣬵ڶ���������������(1++8=)�����������(=11)����Ϊ��һ�ε�ֵ��������ջ��
	return NUM;
}