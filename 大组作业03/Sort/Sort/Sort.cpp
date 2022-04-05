#include"Sort.h"

//�û�����˵�
int Menu()
{
	std::cout << "\t********************************************************************" << std::endl;
	std::cout << "\t* ****************�����ܽ���***************** *      *ע��!*     *" << std::endl;
	std::cout << "\t* 1����������    * 2���鲢����  * 3���ݹ����   *  �������������  *" << std::endl;
	std::cout << "\t* 4����������    * 5����ɫ����  * 6���ǵݹ���� * 99�� Ȼ�������  *" << std::endl;
	std::cout << "\t*  * 7��������������    * 8����������K��/С��   * ����,��û����  *" << std::endl;
	std::cout << "\t*  * 9������������      * 10�������������      * ����ʾ��         *" << std::endl;
	std::cout << "\t*  *           0 & �������롢 �˳�              *(������ô�ӡ����)*" << std::endl;
	std::cout << "\t********************************************************************" << std::endl;
	std::cout << "\t����������ѡ��";
	
	std::string select;
	std::cin >> select;

	return atoi(select.c_str());//��stringתΪint����
}

//��ӡ����
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

//��������
void swap(int* L, int i, int j)
{
	int temp = L[i];
	L[i] = L[j];
	L[j] = temp;
}

//���ɲ�������&�ļ�����
void SaveRecore()
{
	srand((unsigned)time(NULL));
	int i = 0;
	std::ofstream ofs;
	ofs.open("data.txt", std::ios::out);//���ļ�

	if (!ofs.is_open())
	{
		std::cout << "\tû�д򿪳ɹ�!" << std::endl;
		system("pause");
		exit(0);
	}

	std::string begin, end;//�������Χ
	std::string sum;//���������

	std::cout << "\t************************************************" << std::endl;
	std::cout << "\t* *****************�����������*************** *" << std::endl;
	std::cout << "\t* ���������ݷ�Χ[n,m](n,m֮��Ϊ�ո�)��";
	std::cin >> begin >> end;
	std::cout << "\t* �����������������";
	std::cin >> sum;

	while (i < atoi(sum.c_str()))
	{
		ofs << rand() % (atoi(end.c_str()) - atoi(begin.c_str()) + 1) + atoi(begin.c_str())<<" ";
		i++;
	}
	ofs << std::endl;

	ofs.close();
	std::cout << "\t���ݱ���ɹ���" << std::endl;
	system("pause");
	system("cls");
}

//��ȡ��¼
void LoadRecord(Data* L)
{
	int i = 1;
	std::ifstream ifs("data.txt", std::ios::in);//��ȡ�ļ�
	if (!ifs.is_open())
	{
		std::cout << "\t�ļ�������" << std::endl;
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


//���������㷨
InsertSort::InsertSort(Data* L)
{
	LoadRecord(L);//��ȡ���ݳ���
}
InsertSort::~InsertSort()
{
}
//����
void Insert_Sort(Data* L)
{
	InsertSort sort(L);

	if (L->length < 100)
	{
		std::cout << "\t����ǰ����˳��" << std::endl;
		Print(L->a, L->length);
	}

	int i = 0, j = 0;
	for (i = 2;i <= L->length ; i++)
	{
		if (L->a[i - 1] > L->a[i])   //
		{
			L->a[0] = L->a[i];     //�����ڱ�
			for (j = i - 1; L->a[j] > L->a[0]; j--)
			{
				L->a[j + 1] = L->a[j]; //��¼����
			}
			L->a[j + 1] = L->a[0]; //������ȷ��λ��
		}
	}
	//��ӡһ��
	if (L->length < 100)
	{
		std::cout << "\t���������˳��" << std::endl;
		Print(L->a, L->length);

		system("pause");
		system("cls");
	}

}


//�鲢����
MergeArray::MergeArray(Data* L)
{
	LoadRecord(L);//��ȡ���ݳ���
}
MergeArray::~MergeArray()
{
}
//�ϲ�
void MergeArray::Merge(int* SR, int* TR, int begin, int mid, int end)
{
	int firstIndex = begin;
	
	int n = end - begin + 1;//����
	int secondFirst = mid + 1;
	int j = 0; //��ʱ����
	while (begin <= mid && secondFirst <= end) 
	{
		if (SR[begin] <= SR[secondFirst]) 
		{
			TR[j++] =SR[begin++]; //����һ��
		}
		else 
		{
			TR[j++] = SR[secondFirst++];
		}
	}

	//����û���ƶ��������
	//ǰһ��
	while (begin <= mid) 
	{
		TR[j++] = SR[begin++];
	}

	//��һ��
	while (secondFirst <= end) 
	{
		TR[j++] = SR[secondFirst++];
	}

	//�����ʱ���ݿ�����Դ���飬���������ݴ����������
	for (int i = 0; i < n; i++) 
	{
		SR[firstIndex++] = TR[i];
	}
}
//����
void MergeArray::MSort(int* SR, int* TR, int begin, int end)
{
	int mid = 0;
	if (begin == end)
	{
		return;
	}
	else
	{
		mid = (begin + end) / 2;        //��SRƽ��ΪSR[begin...mid]��[mid+1...end]
		MSort(SR, TR, begin, mid);      //�ݹ齫SR[begin...mid]�鲢Ϊ����Tr[begin...mid]		       
		MSort(SR, TR, mid + 1, end);    //�ݹ齫SR[mid+1...end]�鲢Ϊ����Tr[mid+1...end]
		Merge(SR, TR, begin, mid, end); //��Tr[begin...mid]��Tr[mid+1...end]�ϲ���TR[begin...mid]
	}
}
//����
void Merge_Array(Data* L)
{
	MergeArray sort(L);

	int* S = new int[MAXSIZE3 + 1];

	if (L->length < 100)
	{
		std::cout << "\t����ǰ����˳��" << std::endl;
		Print(L->a, L->length);
	}

	sort.MSort(L->a, S, 1, L->length);


	//��ӡһ��
	if (L->length < 100)
	{
		std::cout << "\t���������˳��" << std::endl;
		Print(L->a, L->length);

		system("pause");
		system("cls");
	}
}


//�������򣨷ǵݹ�棩
QuickSort::QuickSort(Data* L)
{
	LoadRecord(L);//��ȡ���ݳ���
}
QuickSort::~QuickSort()
{
}
//���򡢷���pivot
int QuickSort::Partition1(Data* Q, int begin, int end)
{
	int pivotkey;
	//��ʹ���أ���Ϊ�˼�����棬��һ�������������ҵ���K��/С�����ĺ���
	//��Ϊ��������ȡ�У��ᵼ�·��ص�kλ�ó����⣬��������ѭ��
	
	//����ȡ��
	//int mid = begin + (end - begin) / 2;
	//if (Q->a[begin] > Q->a[end])
	//	swap(Q->a, begin, end);
	//if (Q->a[mid] > Q->a[end])
	//	swap(Q->a, mid, end);
	//if (Q->a[mid] > Q->a[begin])
	//	swap(Q->a, mid, begin);

	pivotkey = Q->a[begin]; //���ӱ�ĵ�һ����Ϊ����

	while (begin < end) //�ӱ����߽������м�ɨ��
	{
		while (begin < end && Q->a[end] >= pivotkey)
			end--;
		swap(Q->a, begin, end);  //����
		while (begin < end && Q->a[begin] <= pivotkey)
			begin++;
		swap(Q->a,begin,end);   //����
	}
	return begin;  //��������λ��
}
//����
void Quick_Sort(Data* L)
{
	QuickSort sort(L);

	if (L->length < 100)
	{
		std::cout << "\t����ǰ����˳��" << std::endl;
		Print(L->a, L->length);
	}

	std::stack<int> st;   // ��ջ����ÿһ���������Ӵ�����βԪ���±�

	int pivot = sort.Partition1(L, 1, L->length);
	if (pivot > 2)
	{
		st.push(1);           //���������Ӵ�����βԪ���±�ѹ��
		st.push(pivot - 1);
	}
	if (pivot < L->length - 1)
	{
		st.push(pivot + 1);   //���������Ӵ�����βԪ���±�ѹ��
		st.push(L->length);
	}

	while (!st.empty())
	{
		int end = st.top();   //���������Ӵ�����βԪ���±굯��
		st.pop();
		int begin = st.top();
		st.pop();

		pivot = sort.Partition1(L, begin, end); //���򣬷���

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


	//��ӡһ��
	if (L->length < 100)
	{
		std::cout << "\t���������˳��" << std::endl;
		Print(L->a, L->length);

		system("pause");
		system("cls");
	}
}


//�������򣨵ݹ�棩
QuickSort_Recursion::QuickSort_Recursion(Data* L)
{
	LoadRecord(L);//��ȡ���ݳ���
}
QuickSort_Recursion::~QuickSort_Recursion()
{
}
//���򡢷���pivot
int QuickSort_Recursion::Partition(Data *Q, int begin, int end)
{
	int pivotkey;
	//����ȡ��
	int mid = begin + (end - begin) / 2;
	if (Q->a[begin] > Q->a[end])
		swap(Q->a, begin, end);
	if (Q->a[mid] > Q->a[end])
		swap(Q->a, mid, end);
	if (Q->a[mid] > Q->a[begin])
		swap(Q->a, mid, begin);

	pivotkey = Q->a[begin]; //���ӱ�ĵ�һ����Ϊ����
	Q->a[0] = pivotkey; //������ؼ��ֱ��ݵ��ڱ�

	while (begin < end) //�ӱ����߽������м�ɨ��
	{
		while (begin < end && Q->a[end] >= pivotkey)
			end--;
		Q->a[begin] = Q->a[end];  //�����滻��ʽ
		while (begin < end && Q->a[begin] <= pivotkey)
			begin++;
		Q->a[end] = Q->a[begin];   //�����滻��ʽ
	}
	Q->a[begin] = Q->a[0];   //��������ֵ�滻�ر��ݵ�ֵ
	return begin;  //��������λ��
}
//����
void QuickSort_Recursion::QSort(Data *Q, int begin, int end)
{
	int pivot;

	while (begin < end)
	{
		pivot = Partition(Q, begin, end); //��Q[begin....end]һ��Ϊ�����������
		QSort(Q, begin, pivot - 1);       //�Ե��ӱ�ݹ�����
		begin = pivot + 1;                //β�ݹ飬���ٿռ�����
	}

	//if ((end - begin) > 7) //С�����ò����������,������Ϊ�������⣬�Ͳ�����
	//{
	//}
	//else
	//	Insert_Sort(Q);
}
//����
void QSort_Recursion(Data* L)
{
	QuickSort_Recursion sort(L);

	if (L->length < 100)
	{
		std::cout << "\t����ǰ����˳��" << std::endl;
		Print(L->a, L->length);
	}

	sort.QSort(L,1,L->length);

	//��ӡһ��
	if (L->length < 100)
	{
		std::cout << "\t���������˳��" << std::endl;
		Print(L->a, L->length);

		system("pause");
		system("cls");
	}

}


//��������
CountSort::CountSort(Data* L)
{
	LoadRecord(L);//��ȡ���ݳ���
}
CountSort::~CountSort()
{
}
//����
void Count_Sort(Data* L)
{
	CountSort sort(L);

	if (L->length < 100)
	{
		std::cout << "\t����ǰ����˳��" << std::endl;
		Print(L->a, L->length);
	}

	int max = L->a[1]; //��¼���ֵ
	int min = L->a[1]; //��¼��Сֵ

	for (int i = 1;i <= L->length; i++)
	{
		if (L->a[i] > max)
			max = L->a[i];

		if (L->a[i] < min)
			min = L->a[i];
	}

	int s = max - min + 1;  //��������������Сֵ�ò�ֵ,���⿪�ٹ���ռ�
	int* Count_a = new int[s];  //����ͳ��Ԫ�ظ���������
	for (int i = 0; i < s; i++) //��ʼ������
	{
		Count_a[i] = 0;
	}

	for (int i = 1; i <= L->length; i++)
	{
		Count_a[L->a[i] - min]++; //ͳ��Ԫ�ظ���
	}

	int sum = 0;
	for (int i = 0; i < s; i++)  //�����Ԫ�ص���ǰ���Ԫ��֮��
	{
		sum += Count_a[i]; //���㷨��Ϊ�ȶ��������㷨
		Count_a[i] = sum;
	}

	int* Sort_a = new int[L->length + 1]; //���ٴ������������飬+1����Ϊ���ڱ�
	for (int i = L->length; i >= 1; i--)   //�������ԭʼ���飬��ͳ���������ҵ���ȷλ��
	{
		Sort_a[Count_a[L->a[i] - min]] = L->a[i];
		Count_a[L->a[i] - min]--;     //���ظ������ݣ�--λ��������һ�����򲻳�ͻ
	}

	delete[] Count_a; //�ͷ�

	//��ӡһ��
	if (L->length < 100)
	{
		std::cout << "\t���������˳��" << std::endl;
		Print(Sort_a, L->length);

		system("pause");
		system("cls");
	}
	delete[] Sort_a;

}


//������������
RadixCountSort::RadixCountSort(Data* L)
{
	LoadRecord(L);//��ȡ���ݳ���
}
RadixCountSort::~RadixCountSort()
{
}
//�õ������ֵ�ĳ���
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
//����
void Radix_CountSort(Data* L)
{
	RadixCountSort sort(L);

	if (L->length < 100)
	{
		std::cout << "\t����ǰ����˳��" << std::endl;
		Print(L->a, L->length);
	}

	int min = L->a[1]; //��¼��Сֵ

	for (int i = 1; i <= L->length; i++)
	{
		if (L->a[i] < min)
			min = L->a[i];
	}

	if (min < 0)//��������գ����������ϸ�������ֵ
	{
		for (int i = 1; i <= L->length; i++)
		{
			L->a[i] -= min;
		}
	}

	int time = sort.GetMaxLength(L); //�õ��������λ��

	int* tmp = new int[L->length + 1]; //��ʱ����
	int* count = new int[10];  //ͳ�Ƹ���������λ��

	int k = 0;
	int deno = 1;//��Ϊ��ĸ��ȡλ��

	while (time)
	{
		for (int i = 0; i < 10; i++)
		{
			count[i] = 0;//ÿ�����һ��
		}
		for (int i = 1; i <= L->length; i++)
		{
			count[(L->a[i] / deno) % 10]++;   //ͳ�Ƹ���
		}
		int sum = 0;
		for (int i = 0; i < 10; i++)  //�����Ԫ�ص���ǰ���Ԫ��֮��,����λ��
		{
			sum += count[i]; //���㷨��Ϊ�ȶ��������㷨
			count[i] = sum;
		}
		for (int i = L->length; i >= 1; i--)//����count�����ռ���������
		{
			k = (L->a[i] / deno) % 10;
			tmp[count[k]] = L->a[i];
			count[k]--;       //Ϊ�˲�Ӱ����ͬ�����´θ�ֵ
		}
		for (int i = 1; i <= L->length; i++)//����ʱ���鸳ֵ��ȥ����Ϊ�´�����Ҫ���ϴ������ǰ��������
		{
			L->a[i] = tmp[i];
		}
		deno *= 10;//��һλ��
		time--; //�������
	}

	if (min < 0)//��ԭ�������ӻ���
	{
		for (int i = 1; i <= L->length; i++)
		{
			L->a[i] += min;
		}
	}

	delete[] tmp;  //�ͷ�һ��
	delete[] count;

	//��ӡһ��
	if (L->length < 100)
	{
		std::cout << "\t���������˳��" << std::endl;
		Print(L->a, L->length);

		system("pause");
		system("cls");
	}

}


//��ɫ����
void ColorSort()
{
	int color[10] = { 2,0,1,2,1,1,0,0,1,2 }; //�������Ӳ��Ҫ��0,1,2���ǾͲ�д��������ˡ�
	int red = 0;  //ָ���һλ
	int blue = sizeof(color)/4 - 1;  //ָ�����һλ

	std::cout << "\t��ɫ����ǰ:" << std::endl;
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
			swap(color, i, red++);//ÿ�κ�0������red++
		}
		else if (color[i] == 2)
		{
			swap(color, i--, blue--); //����i--��Ϊ�ˣ�����һ�¿����ܲ����ٽ���������for��i++�ֻص�ԭλ
		}
	}

	std::cout << "\t��ɫ�����:" << std::endl;
	std::cout << "\t";
	for (int i = 0; i < 10; i++)
	{
		std::cout << color[i] << "  ";
	}
	std::cout << std::endl;

	system("pause");
	system("cls");
}


//��һ�������������ҵ���K��/С����
void FindSort(Data* L)
{
	QuickSort sort(L);  //����һ�¿��ŵĺ�����ͬʱ��L��ֵ

	std::string k;
	std::cout << "\t������Ҫ�ҵ�K������ݣ�";
	std::cin >> k;

	if (atoi(k.c_str()) == 0)
	{
		std::cout << "\t��Ǹ��û�е�0������ݣ�" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	int pivot = sort.Partition1(L, 1, L->length);  //���飬������
	int ran = L->length + 1 - atoi(k.c_str());    //������Ǵ������

	while (true)
	{
		if (pivot == ran) //��һ�ξ��ҵ���
			break;
		else if (pivot > ran)
			pivot = sort.Partition1(L, 1, pivot - 1);
		else
			pivot = sort.Partition1(L, pivot + 1, L->length);
	}
	std::cout << "\t��k�������Ϊ" << L->a[pivot] << std::endl;
	system("pause");
	system("cls");
}


//����������&����С��������
BigDataSort::BigDataSort(Data* L)
{
	LoadRecord(L);//��ȡ���ݳ���
}
BigDataSort::~BigDataSort()
{
}
//�˵�
int BigDataSort::menu()
{
	system("cls");
	std::cout << "\t*************************************************" << std::endl;
	std::cout << "\t* ****************�������������*************** *" << std::endl;
	std::cout << "\t*   1���������µ���ʱ(��10�������������)       *" << std::endl;
	std::cout << "\t*   2������С������������ʱ(��10�������������) *" << std::endl;
	std::cout << "\t*               ������ �˳�                     *" << std::endl;
	std::cout << "\t*************************************************" << std::endl;
	std::cout << "\t����������ѡ��";

	std::string select;
	std::cin >> select;

	return atoi(select.c_str());//��stringתΪint����
}
//����������ʱ��
void BigDataSort::BigData(Data* L)
{

	if ( L->length < 100)
	{
		std::cout << "\t����������100������ô�ӡ�����ģ�����" << std::endl;//Ϊ�˷�ֹ���������ӡ�������Ե���
		system("pause");
		system("cls");
		return;
	}

	clock_t start1 = clock();
	Merge_Array(L);
	clock_t diff1 = clock() - start1;
	std::cout << "\t�鲢�����������ʱ��" << diff1 << "ms" << std::endl;
	
	clock_t start2 = clock();
	Quick_Sort(L);
	clock_t diff2 = clock() - start2;
	std::cout << "\t�������򣨷ǵݹ�棩��������ʱ��" << diff2 << "ms" << std::endl;

	clock_t start3 = clock();
	QSort_Recursion(L);
	clock_t diff3 = clock() - start3;
	std::cout << "\t�������򣨵ݹ�棩��������ʱ��" << diff3 << "ms" << std::endl;

	clock_t start = clock();
	Insert_Sort(L);
	clock_t diff = clock() - start;
	std::cout << "\t���������������ʱ��" << diff << "ms" << std::endl;

	clock_t start4 = clock();
	Count_Sort(L);
	clock_t diff4 = clock() - start4;
	std::cout << "\t���������������ʱ��" << diff4 << "ms" << std::endl;

	clock_t start5 = clock();
	Radix_CountSort(L);
	clock_t diff5 = clock() - start5;
	std::cout << "\t�������������������ʱ��" << diff5 << "ms" << std::endl;

	system("pause");
	system("cls");

}
//����С��������
void BigDataSort::Big_Data(Data* L)
{
	if (L->length > 1000 || L->length < 100)
	{
		std::cout << "\t�������ǲ���̫���ˣ�����������10000��Σ��£�" << std::endl;
		std::cout << "\t��������������100������ô�ӡ�����ģ�����" << std::endl;//Ϊ�˷�ֹ���������ӡ�������Ե���
		system("pause");
		system("cls");
		return;
	}

	std::string num;
	std::cout << "\t���������д���(��Ȼ����̫����)��";  
	std::cin >> num;

	int NUM = atoi(num.c_str());

	clock_t start1 = clock();
	while (NUM--)
	{
		Merge_Array(L);
	}	
	clock_t diff1 = clock() - start1;
	std::cout << "\t�鲢�������С����������ʱ��" << diff1 << "ms" << std::endl;

	NUM = atoi(num.c_str());
	clock_t start2 = clock();
	while (NUM--)
	{
		Quick_Sort(L);
	}
	clock_t diff2 = clock() - start2;
	std::cout << "\t�������򣨷ǵݹ�棩����С����������ʱ��" << diff2 << "ms" << std::endl;

	NUM = atoi(num.c_str());
	clock_t start3 = clock();
	while (NUM--)
	{
		QSort_Recursion(L);
	}
	clock_t diff3 = clock() - start3;
	std::cout << "\t�������򣨵ݹ�棩����С����������ʱ��" << diff3 << "ms" << std::endl;

	NUM = atoi(num.c_str());
	clock_t start = clock();
	while (NUM--)
	{
		Insert_Sort(L);
	}
	clock_t diff = clock() - start;
	std::cout << "\t�����������С����������ʱ��" << diff << "ms" << std::endl;

	NUM = atoi(num.c_str());
	clock_t start4 = clock();
	while (NUM--)
	{
		Count_Sort(L);
	}
	clock_t diff4 = clock() - start4;
	std::cout << "\t�����������С����������ʱ��" << diff4 << "ms" << std::endl;

	NUM = atoi(num.c_str());
	clock_t start5 = clock();
	while (NUM--)
	{
		Radix_CountSort(L);
	}
	clock_t diff5 = clock() - start5;
	std::cout << "\t���������������С����������ʱ��" << diff5 << "ms" << std::endl;

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