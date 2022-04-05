#include"Sort.h"

//用户界面菜单
int Menu()
{
	std::cout << "\t********************************************************************" << std::endl;
	std::cout << "\t* ****************排序功能界面***************** *      *注意!*     *" << std::endl;
	std::cout << "\t* 1、插入排序    * 2、归并排序  * 3、递归快排   *  随机数据量大于  *" << std::endl;
	std::cout << "\t* 4、计数排序    * 5、颜色排序  * 6、非递归快排 * 99， 然后调用排  *" << std::endl;
	std::cout << "\t*  * 7、基数计数排序    * 8、无序中找K大/小数   * 序函数,是没有任  *" << std::endl;
	std::cout << "\t*  * 9、大数据排序      * 10、重新随机数据      * 何显示的         *" << std::endl;
	std::cout << "\t*  *           0 & 其他输入、 退出              *(不会调用打印函数)*" << std::endl;
	std::cout << "\t********************************************************************" << std::endl;
	std::cout << "\t请输入您的选择：";
	
	std::string select;
	std::cin >> select;

	return atoi(select.c_str());//将string转为int返回
}

//打印数据
void Print(int* L, int length)
{
	std::cout << "\t";
	for (int i = 1; i <= length; i++)
	{
		std::cout <<std::left<<std::setw(5) << L[i];
		if (i % 15 == 0)
		{
			std::cout << std::endl;
			std::cout << "\t";
		}	
	}
	std::cout << std::endl;
}

//交换数据
void swap(int* L, int i, int j)
{
	int temp = L[i];
	L[i] = L[j];
	L[j] = temp;
}

//生成测试数据&文件保存
void SaveRecore()
{
	srand((unsigned)time(NULL));
	int i = 0;
	std::ofstream ofs;
	ofs.open("data.txt", std::ios::out);//打开文件

	if (!ofs.is_open())
	{
		std::cout << "\t没有打开成功!" << std::endl;
		system("pause");
		exit(0);
	}

	std::string begin, end;//随机数范围
	std::string sum;//随机数个数

	std::cout << "\t************************************************" << std::endl;
	std::cout << "\t* *****************随机数据输入*************** *" << std::endl;
	std::cout << "\t* 请输入数据范围[n,m](n,m之间为空格)：";
	std::cin >> begin >> end;
	std::cout << "\t* 请输入随机数个数：";
	std::cin >> sum;

	while (i < atoi(sum.c_str()))
	{
		ofs << rand() % (atoi(end.c_str()) - atoi(begin.c_str()) + 1) + atoi(begin.c_str())<<" ";
		i++;
	}
	ofs << std::endl;

	ofs.close();
	std::cout << "\t数据保存成功！" << std::endl;
	system("pause");
	system("cls");
}

//读取记录
void LoadRecord(Data* L)
{
	int i = 1;
	std::ifstream ifs("data.txt", std::ios::in);//读取文件
	if (!ifs.is_open())
	{
		std::cout << "\t文件不存在" << std::endl;
		ifs.close();
		system("pasue");
		exit(0);
	}

	while (ifs >> L->a[i])
	{
		i++;
	}
	L->length = i - 1;
	ifs.close();
}


//插入排序算法
InsertSort::InsertSort(Data* L)
{
	LoadRecord(L);//读取数据出来
}
InsertSort::~InsertSort()
{
}
//排序
void Insert_Sort(Data* L)
{
	InsertSort sort(L);

	if (L->length < 100)
	{
		std::cout << "\t排序前数据顺序：" << std::endl;
		Print(L->a, L->length);
	}

	int i = 0, j = 0;
	for (i = 2;i <= L->length ; i++)
	{
		if (L->a[i - 1] > L->a[i])   //
		{
			L->a[0] = L->a[i];     //设置哨兵
			for (j = i - 1; L->a[j] > L->a[0]; j--)
			{
				L->a[j + 1] = L->a[j]; //记录后移
			}
			L->a[j + 1] = L->a[0]; //插入正确的位置
		}
	}
	//打印一下
	if (L->length < 100)
	{
		std::cout << "\t排序后数据顺序：" << std::endl;
		Print(L->a, L->length);

		system("pause");
		system("cls");
	}

}


//归并排序
MergeArray::MergeArray(Data* L)
{
	LoadRecord(L);//读取数据出来
}
MergeArray::~MergeArray()
{
}
//合并
void MergeArray::Merge(int* SR, int* TR, int begin, int mid, int end)
{
	int firstIndex = begin;
	
	int n = end - begin + 1;//长度
	int secondFirst = mid + 1;
	int j = 0; //临时索引
	while (begin <= mid && secondFirst <= end) 
	{
		if (SR[begin] <= SR[secondFirst]) 
		{
			TR[j++] =SR[begin++]; //后移一个
		}
		else 
		{
			TR[j++] = SR[secondFirst++];
		}
	}

	//考虑没有移动完的数据
	//前一段
	while (begin <= mid) 
	{
		TR[j++] = SR[begin++];
	}

	//后一段
	while (secondFirst <= end) 
	{
		TR[j++] = SR[secondFirst++];
	}

	//最后将临时数据拷贝到源数组，这区间数据代表排序完成
	for (int i = 0; i < n; i++) 
	{
		SR[firstIndex++] = TR[i];
	}
}
//分组
void MergeArray::MSort(int* SR, int* TR, int begin, int end)
{
	int mid = 0;
	if (begin == end)
	{
		return;
	}
	else
	{
		mid = (begin + end) / 2;        //将SR平分为SR[begin...mid]和[mid+1...end]
		MSort(SR, TR, begin, mid);      //递归将SR[begin...mid]归并为有序Tr[begin...mid]		       
		MSort(SR, TR, mid + 1, end);    //递归将SR[mid+1...end]归并为有序Tr[mid+1...end]
		Merge(SR, TR, begin, mid, end); //将Tr[begin...mid]和Tr[mid+1...end]合并到TR[begin...mid]
	}
}
//排序
void Merge_Array(Data* L)
{
	MergeArray sort(L);

	int* S = new int[MAXSIZE3 + 1];

	if (L->length < 100)
	{
		std::cout << "\t排序前数据顺序：" << std::endl;
		Print(L->a, L->length);
	}

	sort.MSort(L->a, S, 1, L->length);


	//打印一下
	if (L->length < 100)
	{
		std::cout << "\t排序后数据顺序：" << std::endl;
		Print(L->a, L->length);

		system("pause");
		system("cls");
	}
}


//快速排序（非递归版）
QuickSort::QuickSort(Data* L)
{
	LoadRecord(L);//读取数据出来
}
QuickSort::~QuickSort()
{
}
//排序、返回pivot
int QuickSort::Partition1(Data* Q, int begin, int end)
{
	int pivotkey;
	//不使用呢，是为了兼顾下面，在一个无序序列中找到第K大/小的数的函数
	//因为调用三数取中，会导致返回的k位置出问题，导致无限循环
	
	//三数取中
	//int mid = begin + (end - begin) / 2;
	//if (Q->a[begin] > Q->a[end])
	//	swap(Q->a, begin, end);
	//if (Q->a[mid] > Q->a[end])
	//	swap(Q->a, mid, end);
	//if (Q->a[mid] > Q->a[begin])
	//	swap(Q->a, mid, begin);

	pivotkey = Q->a[begin]; //用子表的第一个作为枢轴

	while (begin < end) //从表两边交替向中间扫描
	{
		while (begin < end && Q->a[end] >= pivotkey)
			end--;
		swap(Q->a, begin, end);  //交换
		while (begin < end && Q->a[begin] <= pivotkey)
			begin++;
		swap(Q->a,begin,end);   //交换
	}
	return begin;  //返回枢轴位置
}
//排序
void Quick_Sort(Data* L)
{
	QuickSort sort(L);

	if (L->length < 100)
	{
		std::cout << "\t排序前数据顺序：" << std::endl;
		Print(L->a, L->length);
	}

	std::stack<int> st;   // 用栈保存每一个待排序子串的首尾元素下标

	int pivot = sort.Partition1(L, 1, L->length);
	if (pivot > 2)
	{
		st.push(1);           //将待排序子串的首尾元素下标压入
		st.push(pivot - 1);
	}
	if (pivot < L->length - 1)
	{
		st.push(pivot + 1);   //将待排序子串的首尾元素下标压入
		st.push(L->length);
	}

	while (!st.empty())
	{
		int end = st.top();   //将待排序子串的首尾元素下标弹出
		st.pop();
		int begin = st.top();
		st.pop();

		pivot = sort.Partition1(L, begin, end); //排序，返回

		if (begin < pivot-1)
		{
			st.push(begin);
			st.push(pivot - 1);
		}
		if (end > pivot +1)
		{
			st.push(pivot + 1);
			st.push(end);
		}
	}


	//打印一下
	if (L->length < 100)
	{
		std::cout << "\t排序后数据顺序：" << std::endl;
		Print(L->a, L->length);

		system("pause");
		system("cls");
	}
}


//快速排序（递归版）
QuickSort_Recursion::QuickSort_Recursion(Data* L)
{
	LoadRecord(L);//读取数据出来
}
QuickSort_Recursion::~QuickSort_Recursion()
{
}
//排序、返回pivot
int QuickSort_Recursion::Partition(Data *Q, int begin, int end)
{
	int pivotkey;
	//三数取中
	int mid = begin + (end - begin) / 2;
	if (Q->a[begin] > Q->a[end])
		swap(Q->a, begin, end);
	if (Q->a[mid] > Q->a[end])
		swap(Q->a, mid, end);
	if (Q->a[mid] > Q->a[begin])
		swap(Q->a, mid, begin);

	pivotkey = Q->a[begin]; //用子表的第一个作为枢轴
	Q->a[0] = pivotkey; //将枢轴关键字备份到哨兵

	while (begin < end) //从表两边交替向中间扫描
	{
		while (begin < end && Q->a[end] >= pivotkey)
			end--;
		Q->a[begin] = Q->a[end];  //采用替换方式
		while (begin < end && Q->a[begin] <= pivotkey)
			begin++;
		Q->a[end] = Q->a[begin];   //采用替换方式
	}
	Q->a[begin] = Q->a[0];   //将枢轴数值替换回备份的值
	return begin;  //返回枢轴位置
}
//分组
void QuickSort_Recursion::QSort(Data *Q, int begin, int end)
{
	int pivot;

	while (begin < end)
	{
		pivot = Partition(Q, begin, end); //将Q[begin....end]一分为二，算出枢轴
		QSort(Q, begin, pivot - 1);       //对低子表递归排序
		begin = pivot + 1;                //尾递归，减少空间消耗
	}

	//if ((end - begin) > 7) //小数据用插入排序更好,这里因为界面问题，就不用了
	//{
	//}
	//else
	//	Insert_Sort(Q);
}
//排序
void QSort_Recursion(Data* L)
{
	QuickSort_Recursion sort(L);

	if (L->length < 100)
	{
		std::cout << "\t排序前数据顺序：" << std::endl;
		Print(L->a, L->length);
	}

	sort.QSort(L,1,L->length);

	//打印一下
	if (L->length < 100)
	{
		std::cout << "\t排序后数据顺序：" << std::endl;
		Print(L->a, L->length);

		system("pause");
		system("cls");
	}

}


//计数排序
CountSort::CountSort(Data* L)
{
	LoadRecord(L);//读取数据出来
}
CountSort::~CountSort()
{
}
//排序
void Count_Sort(Data* L)
{
	CountSort sort(L);

	if (L->length < 100)
	{
		std::cout << "\t排序前数据顺序：" << std::endl;
		Print(L->a, L->length);
	}

	int max = L->a[1]; //记录最大值
	int min = L->a[1]; //记录最小值

	for (int i = 1;i <= L->length; i++)
	{
		if (L->a[i] > max)
			max = L->a[i];

		if (L->a[i] < min)
			min = L->a[i];
	}

	int s = max - min + 1;  //计算出数列最大最小值得差值,避免开辟过多空间
	int* Count_a = new int[s];  //开辟统计元素个数的数组
	for (int i = 0; i < s; i++) //初始化数组
	{
		Count_a[i] = 0;
	}

	for (int i = 1; i <= L->length; i++)
	{
		Count_a[L->a[i] - min]++; //统计元素个数
	}

	int sum = 0;
	for (int i = 0; i < s; i++)  //后面的元素等于前面的元素之和
	{
		sum += Count_a[i]; //让算法成为稳定性排序算法
		Count_a[i] = sum;
	}

	int* Sort_a = new int[L->length + 1]; //开辟储存排序后的数组，+1是因为有哨兵
	for (int i = L->length; i >= 1; i--)   //倒序遍历原始数组，从统计数组中找到正确位置
	{
		Sort_a[Count_a[L->a[i] - min]] = L->a[i];
		Count_a[L->a[i] - min]--;     //有重复的数据，--位置是让下一个排序不冲突
	}

	delete[] Count_a; //释放

	//打印一下
	if (L->length < 100)
	{
		std::cout << "\t排序后数据顺序：" << std::endl;
		Print(Sort_a, L->length);

		system("pause");
		system("cls");
	}
	delete[] Sort_a;

}


//基数计数排序
RadixCountSort::RadixCountSort(Data* L)
{
	LoadRecord(L);//读取数据出来
}
RadixCountSort::~RadixCountSort()
{
}
//得到最大数值的长度
int RadixCountSort::GetMaxLength(Data* L) 
{
	int k = 1;
	long sum = 10;
	for (int i = 0; i < (*L).length; i++)
	{
		while ((*L).a[i] >= sum)
		{
			k++;
			sum *= 10;
		}
	}
	return k;
}
//排序
void Radix_CountSort(Data* L)
{
	RadixCountSort sort(L);

	if (L->length < 100)
	{
		std::cout << "\t排序前数据顺序：" << std::endl;
		Print(L->a, L->length);
	}

	int min = L->a[1]; //记录最小值

	for (int i = 1; i <= L->length; i++)
	{
		if (L->a[i] < min)
			min = L->a[i];
	}

	if (min < 0)//处理负数清空，所有数加上负数绝对值
	{
		for (int i = 1; i <= L->length; i++)
		{
			L->a[i] -= min;
		}
	}

	int time = sort.GetMaxLength(L); //得到最大数的位数

	int* tmp = new int[L->length + 1]; //临时数组
	int* count = new int[10];  //统计个数，分配位置

	int k = 0;
	int deno = 1;//作为分母，取位数

	while (time)
	{
		for (int i = 0; i < 10; i++)
		{
			count[i] = 0;//每次清空一下
		}
		for (int i = 1; i <= L->length; i++)
		{
			count[(L->a[i] / deno) % 10]++;   //统计个数
		}
		int sum = 0;
		for (int i = 0; i < 10; i++)  //后面的元素等于前面的元素之和,分配位置
		{
			sum += count[i]; //让算法成为稳定性排序算法
			count[i] = sum;
		}
		for (int i = L->length; i >= 1; i--)//利用count函数收集数据排序
		{
			k = (L->a[i] / deno) % 10;
			tmp[count[k]] = L->a[i];
			count[k]--;       //为了不影响相同数据下次赋值
		}
		for (int i = 1; i <= L->length; i++)//将临时数组赋值回去，因为下次排序要在上次排序的前提下排序
		{
			L->a[i] = tmp[i];
		}
		deno *= 10;//下一位了
		time--; //排序次数
	}

	if (min < 0)//还原回来，加回来
	{
		for (int i = 1; i <= L->length; i++)
		{
			L->a[i] += min;
		}
	}

	delete[] tmp;  //释放一下
	delete[] count;

	//打印一下
	if (L->length < 100)
	{
		std::cout << "\t排序后数据顺序：" << std::endl;
		Print(L->a, L->length);

		system("pause");
		system("cls");
	}

}


//颜色排序
void ColorSort()
{
	int color[10] = { 2,0,1,2,1,1,0,0,1,2 }; //这个例子硬性要求0,1,2，那就不写输入代码了。
	int red = 0;  //指向第一位
	int blue = sizeof(color)/4 - 1;  //指向最后一位

	std::cout << "\t颜色排序前:" << std::endl;
	std::cout << "\t";
	for (int i = 0; i < 10; i++)
	{
		std::cout << color[i] << "  ";
	}
	std::cout << std::endl;

	for (int i = 0; i <= blue; i++)
	{
		if (color[i] == 0)
		{
			swap(color, i, red++);//每次和0交换，red++
		}
		else if (color[i] == 2)
		{
			swap(color, i--, blue--); //这里i--是为了，处理一下看看能不能再交换，所有for那i++又回到原位
		}
	}

	std::cout << "\t颜色排序后:" << std::endl;
	std::cout << "\t";
	for (int i = 0; i < 10; i++)
	{
		std::cout << color[i] << "  ";
	}
	std::cout << std::endl;

	system("pause");
	system("cls");
}


//在一个无序序列中找到第K大/小的数
void FindSort(Data* L)
{
	QuickSort sort(L);  //利用一下快排的函数，同时给L赋值

	std::string k;
	std::cout << "\t请问想要找第K大的数据：";
	std::cin >> k;

	if (atoi(k.c_str()) == 0)
	{
		std::cout << "\t抱歉，没有第0大的数据！" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	int pivot = sort.Partition1(L, 1, L->length);  //分组，返枢轴
	int ran = L->length + 1 - atoi(k.c_str());    //后面才是大的数据

	while (true)
	{
		if (pivot == ran) //第一次就找到了
			break;
		else if (pivot > ran)
			pivot = sort.Partition1(L, 1, pivot - 1);
		else
			pivot = sort.Partition1(L, pivot + 1, L->length);
	}
	std::cout << "\t第k大的数据为" << L->a[pivot] << std::endl;
	system("pause");
	system("cls");
}


//大数据排序&大量小数据排序
BigDataSort::BigDataSort(Data* L)
{
	LoadRecord(L);//读取数据出来
}
BigDataSort::~BigDataSort()
{
}
//菜单
int BigDataSort::menu()
{
	system("cls");
	std::cout << "\t*************************************************" << std::endl;
	std::cout << "\t* ****************大数据排序界面*************** *" << std::endl;
	std::cout << "\t*   1、大数据下的用时(先10、重新随机数据)       *" << std::endl;
	std::cout << "\t*   2、大量小数据下排序用时(先10、重新随机数据) *" << std::endl;
	std::cout << "\t*               其他、 退出                     *" << std::endl;
	std::cout << "\t*************************************************" << std::endl;
	std::cout << "\t请输入您的选择：";

	std::string select;
	std::cin >> select;

	return atoi(select.c_str());//将string转为int返回
}
//大数据排序时间
void BigDataSort::BigData(Data* L)
{

	if ( L->length < 100)
	{
		std::cout << "\t数据量少于100，会调用打印函数的！！！" << std::endl;//为了防止函数里面打印函数可以调用
		system("pause");
		system("cls");
		return;
	}

	clock_t start1 = clock();
	Merge_Array(L);
	clock_t diff1 = clock() - start1;
	std::cout << "\t归并排序大数据用时：" << diff1 << "ms" << std::endl;
	
	clock_t start2 = clock();
	Quick_Sort(L);
	clock_t diff2 = clock() - start2;
	std::cout << "\t快速排序（非递归版）大数据用时：" << diff2 << "ms" << std::endl;

	clock_t start3 = clock();
	QSort_Recursion(L);
	clock_t diff3 = clock() - start3;
	std::cout << "\t快速排序（递归版）大数据用时：" << diff3 << "ms" << std::endl;

	clock_t start = clock();
	Insert_Sort(L);
	clock_t diff = clock() - start;
	std::cout << "\t插入排序大数据用时：" << diff << "ms" << std::endl;

	clock_t start4 = clock();
	Count_Sort(L);
	clock_t diff4 = clock() - start4;
	std::cout << "\t计数排序大数据用时：" << diff4 << "ms" << std::endl;

	clock_t start5 = clock();
	Radix_CountSort(L);
	clock_t diff5 = clock() - start5;
	std::cout << "\t基数计数排序大数据用时：" << diff5 << "ms" << std::endl;

	system("pause");
	system("cls");

}
//大量小数据排序
void BigDataSort::Big_Data(Data* L)
{
	if (L->length > 1000 || L->length < 100)
	{
		std::cout << "\t数据量是不是太多了！！，再运行10000多次，怕！" << std::endl;
		std::cout << "\t或者数据量少于100，会调用打印函数的！！！" << std::endl;//为了防止函数里面打印函数可以调用
		system("pause");
		system("cls");
		return;
	}

	std::string num;
	std::cout << "\t请输入运行次数(当然请勿太过分)：";  
	std::cin >> num;

	int NUM = atoi(num.c_str());

	clock_t start1 = clock();
	while (NUM--)
	{
		Merge_Array(L);
	}	
	clock_t diff1 = clock() - start1;
	std::cout << "\t归并排序大量小数据排序用时：" << diff1 << "ms" << std::endl;

	NUM = atoi(num.c_str());
	clock_t start2 = clock();
	while (NUM--)
	{
		Quick_Sort(L);
	}
	clock_t diff2 = clock() - start2;
	std::cout << "\t快速排序（非递归版）大量小数据排序用时：" << diff2 << "ms" << std::endl;

	NUM = atoi(num.c_str());
	clock_t start3 = clock();
	while (NUM--)
	{
		QSort_Recursion(L);
	}
	clock_t diff3 = clock() - start3;
	std::cout << "\t快速排序（递归版）大量小数据排序用时：" << diff3 << "ms" << std::endl;

	NUM = atoi(num.c_str());
	clock_t start = clock();
	while (NUM--)
	{
		Insert_Sort(L);
	}
	clock_t diff = clock() - start;
	std::cout << "\t插入排序大量小数据排序用时：" << diff << "ms" << std::endl;

	NUM = atoi(num.c_str());
	clock_t start4 = clock();
	while (NUM--)
	{
		Count_Sort(L);
	}
	clock_t diff4 = clock() - start4;
	std::cout << "\t计数排序大量小数据排序用时：" << diff4 << "ms" << std::endl;

	NUM = atoi(num.c_str());
	clock_t start5 = clock();
	while (NUM--)
	{
		Radix_CountSort(L);
	}
	clock_t diff5 = clock() - start5;
	std::cout << "\t基数计数排序大量小数据排序用时：" << diff5 << "ms" << std::endl;

	system("pause");
	system("cls");
}
void BigData_Sort(Data* L)
{
	BigDataSort S(L);

	int select = S.menu();

	if (select == 1)
	{
		S.BigData(L);
	}
	else if (select == 2)
	{
		S.Big_Data(L);
	}
	else
	{
		system("pause");
		system("cls");
		return;
	}
}