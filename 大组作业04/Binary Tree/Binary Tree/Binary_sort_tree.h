#pragma once
#include<iostream>
#include<stack>
#include<string>
#include<iomanip>
#include<time.h>
#define FALSE 0
#define TRUE 1
#define MAXSIZE 1000

typedef int Status;

int menu();//菜单界面

//栈就不写...了，O(∩_∩)O哈哈~
//不能调用库，那就自己写了，queue
template<class T>
class Queue
{
public:
    T data;                  //数据      
    Queue<T>* next;         //指向当前结点的下一结点
};
template<class T>
class Lqueue
{
public:
    Queue<T>* front;            //队头
    Queue<T>* rear;            //队尾
};
template<class T>
class LQueue
{
public:
    LQueue();
    Status push(T data);    //入队列
    Status pop();    //出队列
    Queue<T>* front();  //返回队头
    bool empty();    //判断是否为空
private:
    Lqueue<T>* node1;
};
template<class T>
LQueue<T>::LQueue()
{  
    node1 = new Lqueue<T>; //初始化
    if (!node1)
        exit(0);

    node1->front = node1->rear = new Queue<T>; //指向同一块内存（这个内存不作释放）
    if (!node1->front)
        exit(0);

    node1->front->next = nullptr;  //相当于front、rear 的next都赋为空（同一块内存）
}
//入队列
template<class T>
Status LQueue<T>::push(T data)
{
    Queue<T>* Q = new Queue<T>;
    if (!Q)
        exit(0);
    Q->data = data;
    Q->next = nullptr;

    node1->rear->next = Q; //接上
    node1->rear = Q;   //移动，指向最后一个
}
//出队列
template<class T>
Status LQueue<T>::pop()
{
    Queue<T>* p;
    if (node1->front == node1->rear) //判空
        return FALSE;

    p = node1->front->next;   //存值
    node1->front->next = p->next;  //修改指向

    if (node1->rear == p) //删除最后一个
        node1->rear = node1->front;
    delete p;  //释放
    return TRUE;
}
//返回队头
template<class T>
Queue<T>* LQueue<T>::front()
{
    if (node1->front == node1->rear) //判空
        return nullptr;
    return node1->front->next;
}
//判断是否为空
template<class T>
bool LQueue<T>::empty()
{
    if (node1->front == node1->rear)
        return TRUE;
    return FALSE;
}



template<class T>
class SqList
{
public:
    T r[MAXSIZE + 1];
    int length = 0;
};
template<class T>
class Node //结点
{
public:
    T value;
    Node<T>* left;
    Node<T>* right;
};

template<class T>
class BinarySortTree
{
public:
	BinarySortTree();
	~BinarySortTree();

    //清空二叉树
    void BST_clear();
    void BST_clear(Node<T>*& Tr);

    //查找数据
    Status BST_Search();
    bool BST_search(Node<T>* Tr, T key, Node<T>* F, Node<T>** P);

    //插入数据
    Status BST_insert();

    //删除数据
    Status BST_delete();
    Status DeleteBST(Node<T>** Tr, T key);
    Status Delete(Node<T>** Tr);

    //BST递归前序遍历
    Status BST_preorderR();
    Status BST_preorderR(Node<T>* Tr);

    //BST非递归前序遍历
    Status BST_preorderI();

    //BST递归中序遍历
    Status BST_inorderR();
    Status BST_inorderR(Node<T>* Tr);

    //BST非递归中序遍历
    Status BST_inorderI();

    //BST递归后序遍历
    Status BST_postorderR();
    Status BST_postorderR(Node<T>* Tr);

    //BST非递归后序遍历
    Status BST_postorderI();

    //BST层序遍历
    Status BST_levelOrder();

    //堆排序
    void swap(SqList<T>* L, int i, int j);
    Status HeapAdjust(SqList<T>* L, int s, int m);
    Status HeapSort();

private:
    Node<T>* node;
    SqList<T>* sqlist; 
};

template<class T>
BinarySortTree<T>::BinarySortTree()
{
    sqlist = new SqList<T>; //开辟内存
    if(!sqlist)
        exit(0);
    this->node = NULL;//初始化
}

template<class T>
BinarySortTree<T>::~BinarySortTree()
{
}

//插入数据
template<class T>
Status BinarySortTree<T>::BST_insert()
{
    std::cout << "\t请输入您想要插入的数据量：";
    std::string num; //处理乱输入问题
    std::cin >> num;
    int NUM = atoi(num.c_str());

    while (NUM)
    {
        T data;
        std::cout << "\t请输入您想要插入的数据：";
        std::cin >> data;

        Node<T>* p = NULL, * s = NULL; //p是返回父结点
        if (!this->BST_search(node, data, NULL, &p))//判断是否数据重复
        {
            s = new Node<T>;
            if (s == NULL)
                exit(0);

            s->value = data;
            s->left = NULL;
            s->right = NULL;
            if (!p)
            {
                node = s; //第一个结点
                node->left = NULL;
                node->right = NULL;
            }
            else if (data < p->value)
            {
                p->left = s;   //插入s为左孩子
            }
            else
            {
                p->right = s;  //插入s为右孩子
            }
        }
        else
        {
            std::cout << "\t插入的数据失败！已经存在！" << std::endl;
            NUM++;  //失败就重新
        }

        NUM--;
    }
    std::cout << "\t插入的数据成功！" << std::endl;
    system("pause");
    system("cls");
    return TRUE;
}

//清空二叉树
template<class T>
void BinarySortTree<T>::BST_clear()
{
    this->BST_clear(node);

    std::cout << "\t清空成功！" << std::endl;
    system("pause");
    system("cls");
}
template<class T>
void BinarySortTree<T>::BST_clear(Node<T>*& Tr)
{
	if (Tr != nullptr)
	{
		if (Tr->left != nullptr)
			this->BST_clear(Tr->left);
		if (Tr->right != nullptr)
			this->BST_clear(Tr->right);

		delete Tr;
        Tr = nullptr;
	}
}


//查找数据
template<class T>
Status BinarySortTree<T>::BST_Search()
{
    T data;
    std::cout << "\t请输入您想要查找的数据：";
    std::cin >> data;

    Node<T>* p = NULL;
    if (this->BST_search(node, data, NULL, &p))//判断是否数据存在
    {
        std::cout << "\t数据存在！" << std::endl;
        system("pause");
        system("cls");
        return FALSE;
    }
    else
    {
        std::cout << "\t不存在该数据！" << std::endl;
        system("pause");
        system("cls");
        return FALSE;
    }
}
template<class T>
bool BinarySortTree<T>::BST_search(Node<T>* Tr, T key, Node<T>* F, Node<T>** P)
{
    if (!Tr)//查找不成功，*p返回最后一个结点
    {
        *P = F;
        return false;
    }
    else if (key == Tr->value)//查找成功，返回这个数据的结点
    {
        *P = Tr;
        return true;
    }
    else if (key < Tr->value)
        return this->BST_search(Tr->left, key, Tr, P);
    else
        return this->BST_search(Tr->right, key, Tr, P);
}


//删除数据
template<class T>
Status BinarySortTree<T>::BST_delete()
{
    T data;
    std::cout << "\t请输入您想要删除的数据：";
    std::cin >> data;

    if (!DeleteBST(&node, data))
    {
        std::cout << "\t不存在该数据！"<<std::endl;
        system("pause");
        system("cls");
        return FALSE;
    }
    else
    {
        std::cout << "\t删除数据成功！" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }  
}
template<class T>
Status BinarySortTree<T>::DeleteBST(Node<T>** Tr, T key)
{
    if (!*Tr)             //不存在数据
        return FALSE;
    else
    {
        if ((*Tr)->value == key)  //找到了，则删除
            return Delete(Tr);
        else if (key < (*Tr)->value)
            return DeleteBST(&(*Tr)->left, key); //继续找
        else
            return DeleteBST(&(*Tr)->right, key);
    }
}
template<class T>
Status BinarySortTree<T>::Delete(Node<T>** p)
{
    Node<T>* q = NULL;
    Node<T>* s = NULL;
    if ((*p)->right == NULL) //右子树为空，则要接它的左子树
    {
        q = *p;
        *p = (*p)->left;
        delete q;
    }
    else if ((*p)->left == NULL)  //左子树为空，则要接它的右子树
    {
        q = *p;
        *p = (*p)->right;
        delete q;
    }
    else   //左右都不为空的情况
    {
        q = *p;
        s = (*p)->left;
        while (s->right) //一直找到右尽头
        {
            q = s;
            s = s->right;
        }
        (*p)->value = s->value; //用被删结点前驱的值取代被删除结点的值
        if (q != *p)
        {
            q->right = s->left;
        }
        else
            q->left = s->left;
        delete s;
    }
    return TRUE;
}


//BST递归前序遍历
template<class T>
Status  BinarySortTree<T>::BST_preorderR()
{
    if (node == NULL)
    {
        std::cout << "\t数据为空！" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }

    std::cout << "\t递归前序遍历：" << std::endl;
    std::cout << "\t";
    this->BST_preorderR(node);
    std::cout << std::endl;

    system("pause");
    system("cls");
    return TRUE;
}
template<class T>
Status  BinarySortTree<T>::BST_preorderR(Node<T>* Tr)
{
    if(Tr == NULL)
    return TRUE;
    
    std::cout << Tr->value << "  ";
    this->BST_preorderR(Tr->left);
    this->BST_preorderR(Tr->right);
}

//BST非递归前序遍历
template<class T>
Status  BinarySortTree<T>::BST_preorderI()
{
    if (node == NULL)
    {
        std::cout << "\t数据为空！" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }

    std::stack<Node<T>*> S; //用栈来代替递归操作
    Node<T>* P = node;

    std::cout << "\t非递归前序遍历：" << std::endl;
    std::cout << "\t";
    while ( P != nullptr || !S.empty())
    {
        while ( P != nullptr)
        {
            std::cout << P->value << "  ";
            S.push(P);  //将这个结点压入栈中
            P = P->left; //让p指向下一个结点
        }
        if (!S.empty())  //这里便是递归返回
        {
            P = S.top();
            S.pop();
            P = P->right;
        }
    }

    std::cout << std::endl;
    system("pause");
    system("cls");
    return TRUE;
}


//BST递归中序遍历
template<class T>
Status  BinarySortTree<T>::BST_inorderR()
{
    if (node == NULL)
    {
        std::cout << "\t数据为空！" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }

    std::cout << "\t递归中序遍历：" << std::endl;
    std::cout << "\t";
    this->BST_inorderR(node);
    std::cout << std::endl;

    system("pause");
    system("cls");
    return TRUE;
}
template<class T>
Status  BinarySortTree<T>::BST_inorderR(Node<T>* Tr)
{
    if (Tr == NULL)
        return TRUE;

    this->BST_inorderR(Tr->left);
    std::cout << Tr->value << "  ";
    this->BST_inorderR(Tr->right);
}

//BST非递归中序遍历
template<class T>
Status  BinarySortTree<T>::BST_inorderI()
{
    if (node == NULL)
    {
        std::cout << "\t数据为空！" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }

    std::stack<Node<T>*> S; //用栈来代替递归操作
    Node<T>* P = node;

    std::cout << "\t非递归中序遍历：" << std::endl;
    std::cout << "\t";
    while (P != nullptr || !S.empty())
    {
        while (P != nullptr)
        {        
            S.push(P);  //将这个结点压入栈中
            P = P->left; //让p指向下一个结点
        }
        if (!S.empty())  //这里便是递归返回
        {
            P = S.top();
            S.pop();
            std::cout << P->value << "  ";
            P = P->right;
        }
    }

    std::cout << std::endl;
    system("pause");
    system("cls");
    return TRUE;
}


//BST递归后序遍历
template<class T>
Status  BinarySortTree<T>::BST_postorderR()
{
    if (node == NULL)
    {
        std::cout << "\t数据为空！" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }

    std::cout << "\t递归后序遍历：" << std::endl;
    std::cout << "\t";
    this->BST_postorderR(node);
    std::cout << std::endl;

    system("pause");
    system("cls");
    return TRUE;
}
template<class T>
Status  BinarySortTree<T>::BST_postorderR(Node<T>* Tr)
{
    if (Tr == NULL)
        return TRUE;

    this->BST_postorderR(Tr->left);
    this->BST_postorderR(Tr->right);
    std::cout << Tr->value << "  ";
}

//BST非递归后序遍历
template<class T>
Status  BinarySortTree<T>::BST_postorderI()
{
    if (node == NULL)
    {
        std::cout << "\t数据为空！" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }

    std::stack<Node<T>*> S; //用栈来代替递归操作
    std::stack<Node<T>*> S1; //这个栈用来压入遍历的顺序
    S.push(node);//第一个肯定是最后一个

    Node<T>* P = node;

    std::cout << "\t非递归后序遍历：" << std::endl;
    std::cout << "\t";
    while (!S.empty())
    {
        P = S.top();  //取栈顶点
        S1.push(P);   
        S.pop();  //已经压入S1中，则弹出来

        if (P->left != nullptr)  //左边优先压入,因为顺序是比右边靠近栈顶
            S.push(P->left);
        if (P->right != nullptr)
            S.push(P->right);
    }
    while (!S1.empty()) //这里就是将栈中排序好的数据弹出来就行了
    {
        P = S1.top();
        std::cout << P->value << "  ";
        S1.pop();
    }

    std::cout << std::endl;
    system("pause");
    system("cls");
    return TRUE;
}


//BST层序遍历
template<class T>
Status  BinarySortTree<T>::BST_levelOrder()
{
    LQueue<Node<T>*> queue;  //自己创建个模板队列

    if (node == NULL)
    {
        std::cout << "\t数据为空！" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }
    std::cout << "\t层序遍历：" << std::endl;
    std::cout << "\t";

    queue.push(node);  
    Node<T>* p = nullptr;  
    while (!queue.empty())
    {
        p = queue.front()->data;   //取出来队列第一个数据
        std::cout << p->value << "  ";

        if (p->left != nullptr)  //左孩子先进入
            queue.push(p->left);
        if (p->right != nullptr)
            queue.push(p->right);
        queue.pop();  //遍历过的结点就出队列
    }

    std::cout << std::endl;
    system("pause");
    system("cls");
    return TRUE;
}

//堆排序
template<class T>
void BinarySortTree<T>::swap(SqList<T>* L, int i, int j)
{
    T temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}
template<class T>
Status BinarySortTree<T>::HeapAdjust(SqList<T>* L, int s, int m)
{
    T temp;
    int j = 0;
    temp = L->r[s];  //赋值

    for (j = s * 2; j <= m; j *= 2)
    {
        if (j < m && L->r[j] < L->r[j + 1]) //按照关键字最大的孩子结点下筛选
            ++j;                            //j为关键字最大记录的下标
        if (temp >= L->r[j])
            break;                   //不用处理的情况
        L->r[s] = L->r[j];          //插入
        s = j;
    }
    L->r[s] = temp;  //插回来

    return TRUE;
}
template<class T>
Status BinarySortTree<T>::HeapSort()
{
    int i = 1;
 
    if (sizeof(T) != 40 && sizeof(T) != 1)  //模板用了字符处理
    {
        std::string begin, end;//随机数范围
        std::string sum;//随机数个数
        while (true)
        {
            std::cout << "\t************************************************" << std::endl;
            std::cout << "\t* *****************随机数据输入*************** *" << std::endl;
            std::cout << "\t* 请输入数据范围[n,m](n,m之间为空格)：";
            std::cin >> begin >> end;
            std::cout << "\t* 请输入随机数个数(MAX:1000)：";
            std::cin >> sum;

            if (atoi(sum.c_str()) < 1000)
                break;
            else
            {
                std::cout << "随机数据个数太多！请重新输入" << std::endl;
                system("pause");
                system("cls");
            }
        }
        while (i <= atoi(sum.c_str()))//随机赋值
        {
            sqlist->r[i] = rand() % (atoi(end.c_str()) - atoi(begin.c_str()) + 1) + atoi(begin.c_str());
            i++;
        }
        sqlist->length = atoi(sum.c_str());//赋长度
    }
    else   //处理字符问题（因为不能随机赋值）
    {
        std::cout << "\t请输入您想要插入的数据量：";
        std::string num; //处理乱输入问题
        std::cin >> num;
        int NUM = atoi(num.c_str());
        while (NUM)
        {
            T data;
            std::cout << "\t请输入您想要插入的数据：";
            std::cin >> data;
            sqlist->r[i++] = data;
            NUM--;
        }
        sqlist->length = atoi(num.c_str());//赋长度
    }
   


    std::cout << "\t排序前数据：" << std::endl;
    std::cout << "\t";
    for (i = 1; i <= sqlist->length; i++)//打印
    {
        std::cout << std::left << std::setw(5) << sqlist->r[i];
        if (i % 15 == 0)
        {
            std::cout << std::endl;
            std::cout << "\t";
        }        
    }
    std::cout << std::endl;

    int j = 0;
    for (j = sqlist->length / 2; j > 0; j--)  //一个一个子树构建大顶堆
        HeapAdjust(sqlist, j, sqlist->length);
    for (j = sqlist->length; j > 1; j--)
    {
        swap(sqlist, 1, j); //将堆顶的记录和当前未经过排序的子序最后一个交换
        HeapAdjust(sqlist, 1, j - 1);//重新调整大顶堆
    }

    std::cout << "\t排序后数据：" << std::endl;
    std::cout << "\t";
    for (i = 1; i <= sqlist->length; i++)
    {
        std::cout << std::left << std::setw(5) << sqlist->r[i];
        if (i % 15 == 0)
        {
            std::cout << std::endl;
            std::cout << "\t";
        }       
    }
    std::cout << std::endl;

    system("pause");
    system("cls");
    return TRUE;
}
