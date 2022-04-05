#pragma once
#include<iostream>
#include<string>
#include<stack>
#include<stdio.h>
#include<iomanip>
#include<fstream>
#include<windows.h>
#include<time.h>
#define MAXSIZE 1000//��������������������ֵ
#define MAXSIZE1 10000
#define MAXSIZE2 50000
#define MAXSIZE3 200000

typedef struct
{
	int a[MAXSIZE3 + 1];//a[0]��Ϊ�ڱ�ʹ��
	int length;//��¼����
}Data;

//�û�����˵�
int Menu();

//��ӡ����
void Print(int* L,int length);

//��������
void swap(int* L, int i, int j);

//���ɲ�������&�ļ�����
void SaveRecore();

//��ȡ��¼
void LoadRecord(Data* L);

//���������㷨
class InsertSort
{

public:
	InsertSort(Data* L);
	~InsertSort();

private:

};

void Insert_Sort(Data* L);

//�鲢����
class MergeArray
{
public:
	MergeArray(Data* L);
	~MergeArray();

	//����
	void MSort(int* SR, int* TR, int begin, int end);

	//�ϲ�
	void Merge(int* SR, int* TR, int begin, int mid, int end);

private:

};

void Merge_Array(Data* L);

//�������򣨷ǵݹ�棩
class QuickSort
{
public:
	QuickSort(Data* L);
	~QuickSort();

	//���򡢷���pivot
	int Partition1(Data* Q, int begin, int end);
private:

};

void Quick_Sort(Data* L);

//�������򣨵ݹ�棩
class QuickSort_Recursion
{
public:
	QuickSort_Recursion(Data* L);
	~QuickSort_Recursion();

	//���򡢷���pivot
	int Partition(Data* Q, int begin, int end);
	//����
	void QSort(Data* Q, int begin, int end);
private:

};

void QSort_Recursion(Data* L);

//��������
class CountSort
{
public:
	CountSort(Data* L);
	~CountSort();

private:

};

void Count_Sort(Data* L);

//������������
class RadixCountSort
{
public:
	RadixCountSort(Data* L);
	~RadixCountSort();

	int GetMaxLength(Data* L); //�õ������ֵ�ĳ���
private:

};

void Radix_CountSort(Data* L);

//��ɫ����
void ColorSort();

//��һ�������������ҵ���K��/С����
void FindSort(Data* L);

//����������&����С��������
class BigDataSort
{
public:
	BigDataSort(Data* L);
	~BigDataSort();

	//�˵�
	int menu();
	//����������ʱ��
	void BigData(Data* L);
	//����С��������
	void Big_Data(Data* L);

private:

};

void BigData_Sort(Data* L);