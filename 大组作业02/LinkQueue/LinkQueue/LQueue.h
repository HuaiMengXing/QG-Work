#pragma once
#include<iostream>
#include<string>

#define FALSE 0;
#define TRUE 1;

typedef int Status;

typedef struct node
{
    void* data;                    //数据
    int size;                      //数据大小，用来索引
    struct node* next;            //指向当前结点的下一结点
}Node;

typedef struct Lqueue
{
    Node* front;                   //队头
    Node* rear;                    //队尾
    size_t length;            //队列长度
}LQueue;


class Link_Queue
{
public:
	Link_Queue();
	~Link_Queue();
    
    std::string menu();//菜单

    void InitLQueue(LQueue** Q);//创建队列

    Status DestoryLQueue(LQueue** Q);//销毁队列

    void* GetHeadLQueue(LQueue* Q);//查看队头元素

    size_t LengthLQueue(LQueue* Q);//确定队列长度

    Status EnLQueue(LQueue** Q);//入队操作

    Status DeLQueue(LQueue** Q);//出队操作

    Status ClearLQueue(LQueue** Q);//清空队列

    Status TraverseLQueue(const LQueue* Q);//遍历函数操作

private:
};

void* TypeSelect(void* data,int& size);//赋值

void LPrint(void* q,int size);//打印

Status IsEmptyLQueue(const LQueue* Q);//检查队列是否为空