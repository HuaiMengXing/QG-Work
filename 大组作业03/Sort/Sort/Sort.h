#pragma once
#include<iostream>
#include<string>
#include<stack>
#include<stdio.h>
#include<iomanip>
#include<fstream>
#include<windows.h>
#include<time.h>
#define MAXSIZE 1000//用于数组排序个数的最大值
#define MAXSIZE1 10000
#define MAXSIZE2 50000
#define MAXSIZE3 200000

typedef struct
{
	int a[MAXSIZE3 + 1];//a[0]作为哨兵使用
	int length;//记录长度
}Data;

//用户界面菜单
int Menu();

//打印数据
void Print(int* L,int length);

//交换数据
void swap(int* L, int i, int j);

//生成测试数据&文件保存
void SaveRecore();

//读取记录
void LoadRecord(Data* L);

//插入排序算法
class InsertSort
{

public:
	InsertSort(Data* L);
	~InsertSort();

private:

};

void Insert_Sort(Data* L);

//归并排序
class MergeArray
{
public:
	MergeArray(Data* L);
	~MergeArray();

	//分组
	void MSort(int* SR, int* TR, int begin, int end);

	//合并
	void Merge(int* SR, int* TR, int begin, int mid, int end);

private:

};

void Merge_Array(Data* L);

//快速排序（非递归版）
class QuickSort
{
public:
	QuickSort(Data* L);
	~QuickSort();

	//排序、返回pivot
	int Partition1(Data* Q, int begin, int end);
private:

};

void Quick_Sort(Data* L);

//快速排序（递归版）
class QuickSort_Recursion
{
public:
	QuickSort_Recursion(Data* L);
	~QuickSort_Recursion();

	//排序、返回pivot
	int Partition(Data* Q, int begin, int end);
	//分组
	void QSort(Data* Q, int begin, int end);
private:

};

void QSort_Recursion(Data* L);

//计数排序
class CountSort
{
public:
	CountSort(Data* L);
	~CountSort();

private:

};

void Count_Sort(Data* L);

//基数计数排序
class RadixCountSort
{
public:
	RadixCountSort(Data* L);
	~RadixCountSort();

	int GetMaxLength(Data* L); //得到最大数值的长度
private:

};

void Radix_CountSort(Data* L);

//颜色排序
void ColorSort();

//在一个无序序列中找到第K大/小的数
void FindSort(Data* L);

//大数据排序&大量小数据排序
class BigDataSort
{
public:
	BigDataSort(Data* L);
	~BigDataSort();

	//菜单
	int menu();
	//大数据排序时间
	void BigData(Data* L);
	//大量小数据排序
	void Big_Data(Data* L);

private:

};

void BigData_Sort(Data* L);