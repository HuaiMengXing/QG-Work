#include"LinkStack.h"
//链栈

LStack::LStack()
{

}

LStack::~LStack()
{

}

//界面菜单
void LStack::menu() {

	system("cls");

	LinkStack* stack = NULL;//栈
	LStack LStack;//接口
	while (true)
	{
		std::cout << "\t* ****************************************************** *" << std::endl;
		std::cout << "\t* ********************栈功能系统界面******************** *" << std::endl;
		std::cout << "\t*   1、创建栈         * 2、入栈          * 3、出栈       *" << std::endl;
		std::cout << "\t*   4、找栈顶元素     * 5、检测栈长度    * 6、判断栈状态 *" << std::endl;
		std::cout << "\t*   7、遍历栈         * 8、清空栈        * 9、销毁栈     *" << std::endl;
		std::cout << "\t*                     * 10 、退出                        *" << std::endl;
		std::cout << "\t* ****************************************************** *" << std::endl;
		std::cout << "\t请输入你的选择：";

		std::string select;
		std::cin >> select;

		switch (atoi(select.c_str()))
		{
		case 1:LStack.initLStack(&stack);
			break;
		case 2:LStack.pushLStack(&stack);
			break;
		case 3:LStack.popLStack(&stack);
			break;
		case 4:LStack.getTopLStack(stack);
			break;
		case 5:LStack.LStackLength(stack);
			break;
		case 6:LStack.isEmptyLStack(stack);
			break;
		case 7:LStack.TraStack(stack);
			break;
		case 8:LStack.clearLStack(&stack);
			break;
		case 9:LStack.destroyLStack(&stack);
			break;
		case 10:
			std::cout << "\t感谢您的使用，祝您生活愉快！拜拜~~" << std::endl;
			system("pause");
			system("cls");
			return;
		default:
			std::cout << "\t输入错误！请重新选择!" << std::endl;
			system("pause");
			system("cls");
			break;
		}

	}
	return;
}

//创建栈
Status LStack::initLStack(LinkStack** s){

	(*s) = new LinkStack;
	(*s)->top = NULL;
	(*s)->count = 0;
	std::cout << "\t创建成功！" << std::endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//判断栈是否为空或者没有栈
Status LStack::isEmptyLStack(LinkStack* s) {

	if (s == NULL)//不存在栈
	{
		std::cout << "\t栈不存在!或者已经销毁！" << std::endl;
		system("pause");
		system("cls");
		return INEXISTENCE;
	}
	else if (s->count == 0)//栈存在，但是为空
	{
		std::cout << "\t栈已经创建,但栈为空！" << std::endl;
		system("pause");
		system("cls");
		return ERROR;
	}
	//存在栈且不为空
	std::cout << "\t栈已经创建,栈不为空！" << std::endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//得到栈顶元素
Status LStack::getTopLStack(LinkStack* S) {

	if (S == NULL || S->count == 0)//栈不存在!或者为空
	{
		std::cout << "\t栈不存在!或者为空！" << std::endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	std::cout << "\t栈顶元素为：" << S->top->data << std::endl;
	system("pause");
	system("cls");
	return S->top->data;
}

//清空栈
Status LStack::clearLStack(LinkStack** S) {

	if ((*S) == NULL || (*S)->count == 0)//栈不存在!或者为空
	{
		std::cout << "\t栈不存在!或者已经为空！" << std::endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkStackPtr temp;
	while ((*S)->top != NULL)
	{
		temp = (*S)->top;//保留下来释放
		(*S)->top = (*S)->top->next;//后移
		delete temp;//释放
	}

	(*S)->count = 0;//更新长度

	std::cout << "\t栈已经清空！" << std::endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//销毁栈
Status LStack::destroyLStack(LinkStack** S){

	if ((*S) == NULL)//栈不存在!
	{
		std::cout << "\t栈已经不存在!" << std::endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkStackPtr temp;
	while ((*S)->top != NULL)
	{
		temp = (*S)->top;//保留下来释放
		(*S)->top = (*S)->top->next;//后移
		delete temp;//释放
	}
	delete *S;//创建栈的也释放
	(*S) = NULL;

	std::cout << "\t栈销毁成功！" << std::endl;
	system("pause");
	system("cls");
	return SUCCESS;
}

//检测栈长度
Status LStack::LStackLength(LinkStack* S) {

	if (S == NULL)//栈不存在或者被销毁，则不可以入栈了
	{
		std::cout << "\t栈不存在!或者已经销毁！" << std::endl;
		system("pause");
		system("cls");
		return INEXISTENCE;
	}

	std::cout << "\t检测出现栈长度为：" << S->count << std::endl;
	system("pause");
	system("cls");
	return S->count;
}

//入栈
Status LStack::pushLStack(LinkStack** S) {

	if (*S == NULL)//栈不存在或者被销毁，则不可以入栈了
	{
		std::cout << "\t栈不存在!或者已经销毁！" << std::endl;
		system("pause");
		system("cls");
		return INEXISTENCE;
	}
	else 
	{
		LinkStackPtr s = new (StackNode);

		//赋值
		std::string data;
		std::cout << "\t请输入您想进栈的值(字符当0处理)：";
		std::cin >> data;
		s->data = atoi(data.c_str());

		//入栈
		s->next = (*S)->top;//将当前栈顶元素后继新结点
		(*S)->top = s;//栈顶指针移位
		(*S)->count++;//长度++

		std::cout << "\t入栈成功!" << std::endl;
	}
	system("pause");
	system("cls");
	return SUCCESS;
}

//出栈
Status LStack::popLStack(LinkStack** S) {

	if ((*S) == NULL || (*S)->count == 0)//栈不存在!或者为空
	{
		std::cout << "\t栈不存在!或者为空！" << std::endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkStackPtr p = (*S)->top;

	int num = p->data;

	(*S)->top = (*S)->top->next;//栈顶后移
	delete p;
	(*S)->count--;

	std::cout << "\t弹出成功！" << std::endl;
	system("pause");
	system("cls");
	return num;//返回弹出的值
}

//栈的遍历
Status LStack::TraStack(LinkStack* S) {

	if (S == NULL || S->count == 0)//栈不存在!或者为空
	{
		std::cout << "\t栈不存在!或者为空！" << std::endl;
		system("pause");
		system("cls");
		return ERROR;
	}

	LinkStackPtr temp = S->top;//不动栈顶指向，用里面的链表

	std::cout << "\t";//界面美观
	while (temp != NULL)
	{
		std::cout << temp->data << "-";
		temp = temp->next;
	}
	std::cout << "栈底" << std::endl;

	system("pause");
	system("cls");
	return SUCCESS;
}