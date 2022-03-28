#pragma once
#include<iostream>
#include<string>

#define FALSE 0;
#define TRUE 1;

typedef int Status;

typedef struct node
{
    void* data;                    //����
    int size;                      //���ݴ�С����������
    struct node* next;            //ָ��ǰ������һ���
}Node;

typedef struct Lqueue
{
    Node* front;                   //��ͷ
    Node* rear;                    //��β
    size_t length;            //���г���
}LQueue;


class Link_Queue
{
public:
	Link_Queue();
	~Link_Queue();
    
    std::string menu();//�˵�

    void InitLQueue(LQueue** Q);//��������

    Status DestoryLQueue(LQueue** Q);//���ٶ���

    void* GetHeadLQueue(LQueue* Q);//�鿴��ͷԪ��

    size_t LengthLQueue(LQueue* Q);//ȷ�����г���

    Status EnLQueue(LQueue** Q);//��Ӳ���

    Status DeLQueue(LQueue** Q);//���Ӳ���

    Status ClearLQueue(LQueue** Q);//��ն���

    Status TraverseLQueue(const LQueue* Q);//������������

private:
};

void* TypeSelect(void* data,int& size);//��ֵ

void LPrint(void* q,int size);//��ӡ

Status IsEmptyLQueue(const LQueue* Q);//�������Ƿ�Ϊ��