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

int menu();//�˵�����

//ջ�Ͳ�д...�ˣ�O(��_��)O����~
//���ܵ��ÿ⣬�Ǿ��Լ�д�ˣ�queue
template<class T>
class Queue
{
public:
    T data;                  //����      
    Queue<T>* next;         //ָ��ǰ������һ���
};
template<class T>
class Lqueue
{
public:
    Queue<T>* front;            //��ͷ
    Queue<T>* rear;            //��β
};
template<class T>
class LQueue
{
public:
    LQueue();
    Status push(T data);    //�����
    Status pop();    //������
    Queue<T>* front();  //���ض�ͷ
    bool empty();    //�ж��Ƿ�Ϊ��
private:
    Lqueue<T>* node1;
};
template<class T>
LQueue<T>::LQueue()
{  
    node1 = new Lqueue<T>; //��ʼ��
    if (!node1)
        exit(0);

    node1->front = node1->rear = new Queue<T>; //ָ��ͬһ���ڴ棨����ڴ治���ͷţ�
    if (!node1->front)
        exit(0);

    node1->front->next = nullptr;  //�൱��front��rear ��next����Ϊ�գ�ͬһ���ڴ棩
}
//�����
template<class T>
Status LQueue<T>::push(T data)
{
    Queue<T>* Q = new Queue<T>;
    if (!Q)
        exit(0);
    Q->data = data;
    Q->next = nullptr;

    node1->rear->next = Q; //����
    node1->rear = Q;   //�ƶ���ָ�����һ��
}
//������
template<class T>
Status LQueue<T>::pop()
{
    Queue<T>* p;
    if (node1->front == node1->rear) //�п�
        return FALSE;

    p = node1->front->next;   //��ֵ
    node1->front->next = p->next;  //�޸�ָ��

    if (node1->rear == p) //ɾ�����һ��
        node1->rear = node1->front;
    delete p;  //�ͷ�
    return TRUE;
}
//���ض�ͷ
template<class T>
Queue<T>* LQueue<T>::front()
{
    if (node1->front == node1->rear) //�п�
        return nullptr;
    return node1->front->next;
}
//�ж��Ƿ�Ϊ��
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
class Node //���
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

    //��ն�����
    void BST_clear();
    void BST_clear(Node<T>*& Tr);

    //��������
    Status BST_Search();
    bool BST_search(Node<T>* Tr, T key, Node<T>* F, Node<T>** P);

    //��������
    Status BST_insert();

    //ɾ������
    Status BST_delete();
    Status DeleteBST(Node<T>** Tr, T key);
    Status Delete(Node<T>** Tr);

    //BST�ݹ�ǰ�����
    Status BST_preorderR();
    Status BST_preorderR(Node<T>* Tr);

    //BST�ǵݹ�ǰ�����
    Status BST_preorderI();

    //BST�ݹ��������
    Status BST_inorderR();
    Status BST_inorderR(Node<T>* Tr);

    //BST�ǵݹ��������
    Status BST_inorderI();

    //BST�ݹ�������
    Status BST_postorderR();
    Status BST_postorderR(Node<T>* Tr);

    //BST�ǵݹ�������
    Status BST_postorderI();

    //BST�������
    Status BST_levelOrder();

    //������
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
    sqlist = new SqList<T>; //�����ڴ�
    if(!sqlist)
        exit(0);
    this->node = NULL;//��ʼ��
}

template<class T>
BinarySortTree<T>::~BinarySortTree()
{
}

//��������
template<class T>
Status BinarySortTree<T>::BST_insert()
{
    std::cout << "\t����������Ҫ�������������";
    std::string num; //��������������
    std::cin >> num;
    int NUM = atoi(num.c_str());

    while (NUM)
    {
        T data;
        std::cout << "\t����������Ҫ��������ݣ�";
        std::cin >> data;

        Node<T>* p = NULL, * s = NULL; //p�Ƿ��ظ����
        if (!this->BST_search(node, data, NULL, &p))//�ж��Ƿ������ظ�
        {
            s = new Node<T>;
            if (s == NULL)
                exit(0);

            s->value = data;
            s->left = NULL;
            s->right = NULL;
            if (!p)
            {
                node = s; //��һ�����
                node->left = NULL;
                node->right = NULL;
            }
            else if (data < p->value)
            {
                p->left = s;   //����sΪ����
            }
            else
            {
                p->right = s;  //����sΪ�Һ���
            }
        }
        else
        {
            std::cout << "\t���������ʧ�ܣ��Ѿ����ڣ�" << std::endl;
            NUM++;  //ʧ�ܾ�����
        }

        NUM--;
    }
    std::cout << "\t��������ݳɹ���" << std::endl;
    system("pause");
    system("cls");
    return TRUE;
}

//��ն�����
template<class T>
void BinarySortTree<T>::BST_clear()
{
    this->BST_clear(node);

    std::cout << "\t��ճɹ���" << std::endl;
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


//��������
template<class T>
Status BinarySortTree<T>::BST_Search()
{
    T data;
    std::cout << "\t����������Ҫ���ҵ����ݣ�";
    std::cin >> data;

    Node<T>* p = NULL;
    if (this->BST_search(node, data, NULL, &p))//�ж��Ƿ����ݴ���
    {
        std::cout << "\t���ݴ��ڣ�" << std::endl;
        system("pause");
        system("cls");
        return FALSE;
    }
    else
    {
        std::cout << "\t�����ڸ����ݣ�" << std::endl;
        system("pause");
        system("cls");
        return FALSE;
    }
}
template<class T>
bool BinarySortTree<T>::BST_search(Node<T>* Tr, T key, Node<T>* F, Node<T>** P)
{
    if (!Tr)//���Ҳ��ɹ���*p�������һ�����
    {
        *P = F;
        return false;
    }
    else if (key == Tr->value)//���ҳɹ�������������ݵĽ��
    {
        *P = Tr;
        return true;
    }
    else if (key < Tr->value)
        return this->BST_search(Tr->left, key, Tr, P);
    else
        return this->BST_search(Tr->right, key, Tr, P);
}


//ɾ������
template<class T>
Status BinarySortTree<T>::BST_delete()
{
    T data;
    std::cout << "\t����������Ҫɾ�������ݣ�";
    std::cin >> data;

    if (!DeleteBST(&node, data))
    {
        std::cout << "\t�����ڸ����ݣ�"<<std::endl;
        system("pause");
        system("cls");
        return FALSE;
    }
    else
    {
        std::cout << "\tɾ�����ݳɹ���" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }  
}
template<class T>
Status BinarySortTree<T>::DeleteBST(Node<T>** Tr, T key)
{
    if (!*Tr)             //����������
        return FALSE;
    else
    {
        if ((*Tr)->value == key)  //�ҵ��ˣ���ɾ��
            return Delete(Tr);
        else if (key < (*Tr)->value)
            return DeleteBST(&(*Tr)->left, key); //������
        else
            return DeleteBST(&(*Tr)->right, key);
    }
}
template<class T>
Status BinarySortTree<T>::Delete(Node<T>** p)
{
    Node<T>* q = NULL;
    Node<T>* s = NULL;
    if ((*p)->right == NULL) //������Ϊ�գ���Ҫ������������
    {
        q = *p;
        *p = (*p)->left;
        delete q;
    }
    else if ((*p)->left == NULL)  //������Ϊ�գ���Ҫ������������
    {
        q = *p;
        *p = (*p)->right;
        delete q;
    }
    else   //���Ҷ���Ϊ�յ����
    {
        q = *p;
        s = (*p)->left;
        while (s->right) //һֱ�ҵ��Ҿ�ͷ
        {
            q = s;
            s = s->right;
        }
        (*p)->value = s->value; //�ñ�ɾ���ǰ����ֵȡ����ɾ������ֵ
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


//BST�ݹ�ǰ�����
template<class T>
Status  BinarySortTree<T>::BST_preorderR()
{
    if (node == NULL)
    {
        std::cout << "\t����Ϊ�գ�" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }

    std::cout << "\t�ݹ�ǰ�������" << std::endl;
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

//BST�ǵݹ�ǰ�����
template<class T>
Status  BinarySortTree<T>::BST_preorderI()
{
    if (node == NULL)
    {
        std::cout << "\t����Ϊ�գ�" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }

    std::stack<Node<T>*> S; //��ջ������ݹ����
    Node<T>* P = node;

    std::cout << "\t�ǵݹ�ǰ�������" << std::endl;
    std::cout << "\t";
    while ( P != nullptr || !S.empty())
    {
        while ( P != nullptr)
        {
            std::cout << P->value << "  ";
            S.push(P);  //��������ѹ��ջ��
            P = P->left; //��pָ����һ�����
        }
        if (!S.empty())  //������ǵݹ鷵��
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


//BST�ݹ��������
template<class T>
Status  BinarySortTree<T>::BST_inorderR()
{
    if (node == NULL)
    {
        std::cout << "\t����Ϊ�գ�" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }

    std::cout << "\t�ݹ����������" << std::endl;
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

//BST�ǵݹ��������
template<class T>
Status  BinarySortTree<T>::BST_inorderI()
{
    if (node == NULL)
    {
        std::cout << "\t����Ϊ�գ�" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }

    std::stack<Node<T>*> S; //��ջ������ݹ����
    Node<T>* P = node;

    std::cout << "\t�ǵݹ����������" << std::endl;
    std::cout << "\t";
    while (P != nullptr || !S.empty())
    {
        while (P != nullptr)
        {        
            S.push(P);  //��������ѹ��ջ��
            P = P->left; //��pָ����һ�����
        }
        if (!S.empty())  //������ǵݹ鷵��
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


//BST�ݹ�������
template<class T>
Status  BinarySortTree<T>::BST_postorderR()
{
    if (node == NULL)
    {
        std::cout << "\t����Ϊ�գ�" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }

    std::cout << "\t�ݹ���������" << std::endl;
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

//BST�ǵݹ�������
template<class T>
Status  BinarySortTree<T>::BST_postorderI()
{
    if (node == NULL)
    {
        std::cout << "\t����Ϊ�գ�" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }

    std::stack<Node<T>*> S; //��ջ������ݹ����
    std::stack<Node<T>*> S1; //���ջ����ѹ�������˳��
    S.push(node);//��һ���϶������һ��

    Node<T>* P = node;

    std::cout << "\t�ǵݹ���������" << std::endl;
    std::cout << "\t";
    while (!S.empty())
    {
        P = S.top();  //ȡջ����
        S1.push(P);   
        S.pop();  //�Ѿ�ѹ��S1�У��򵯳���

        if (P->left != nullptr)  //�������ѹ��,��Ϊ˳���Ǳ��ұ߿���ջ��
            S.push(P->left);
        if (P->right != nullptr)
            S.push(P->right);
    }
    while (!S1.empty()) //������ǽ�ջ������õ����ݵ�����������
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


//BST�������
template<class T>
Status  BinarySortTree<T>::BST_levelOrder()
{
    LQueue<Node<T>*> queue;  //�Լ�������ģ�����

    if (node == NULL)
    {
        std::cout << "\t����Ϊ�գ�" << std::endl;
        system("pause");
        system("cls");
        return TRUE;
    }
    std::cout << "\t���������" << std::endl;
    std::cout << "\t";

    queue.push(node);  
    Node<T>* p = nullptr;  
    while (!queue.empty())
    {
        p = queue.front()->data;   //ȡ�������е�һ������
        std::cout << p->value << "  ";

        if (p->left != nullptr)  //�����Ƚ���
            queue.push(p->left);
        if (p->right != nullptr)
            queue.push(p->right);
        queue.pop();  //�������Ľ��ͳ�����
    }

    std::cout << std::endl;
    system("pause");
    system("cls");
    return TRUE;
}

//������
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
    temp = L->r[s];  //��ֵ

    for (j = s * 2; j <= m; j *= 2)
    {
        if (j < m && L->r[j] < L->r[j + 1]) //���չؼ������ĺ��ӽ����ɸѡ
            ++j;                            //jΪ�ؼ�������¼���±�
        if (temp >= L->r[j])
            break;                   //���ô�������
        L->r[s] = L->r[j];          //����
        s = j;
    }
    L->r[s] = temp;  //�����

    return TRUE;
}
template<class T>
Status BinarySortTree<T>::HeapSort()
{
    int i = 1;
 
    if (sizeof(T) != 40 && sizeof(T) != 1)  //ģ�������ַ�����
    {
        std::string begin, end;//�������Χ
        std::string sum;//���������
        while (true)
        {
            std::cout << "\t************************************************" << std::endl;
            std::cout << "\t* *****************�����������*************** *" << std::endl;
            std::cout << "\t* ���������ݷ�Χ[n,m](n,m֮��Ϊ�ո�)��";
            std::cin >> begin >> end;
            std::cout << "\t* ���������������(MAX:1000)��";
            std::cin >> sum;

            if (atoi(sum.c_str()) < 1000)
                break;
            else
            {
                std::cout << "������ݸ���̫�࣡����������" << std::endl;
                system("pause");
                system("cls");
            }
        }
        while (i <= atoi(sum.c_str()))//�����ֵ
        {
            sqlist->r[i] = rand() % (atoi(end.c_str()) - atoi(begin.c_str()) + 1) + atoi(begin.c_str());
            i++;
        }
        sqlist->length = atoi(sum.c_str());//������
    }
    else   //�����ַ����⣨��Ϊ���������ֵ��
    {
        std::cout << "\t����������Ҫ�������������";
        std::string num; //��������������
        std::cin >> num;
        int NUM = atoi(num.c_str());
        while (NUM)
        {
            T data;
            std::cout << "\t����������Ҫ��������ݣ�";
            std::cin >> data;
            sqlist->r[i++] = data;
            NUM--;
        }
        sqlist->length = atoi(num.c_str());//������
    }
   


    std::cout << "\t����ǰ���ݣ�" << std::endl;
    std::cout << "\t";
    for (i = 1; i <= sqlist->length; i++)//��ӡ
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
    for (j = sqlist->length / 2; j > 0; j--)  //һ��һ�����������󶥶�
        HeapAdjust(sqlist, j, sqlist->length);
    for (j = sqlist->length; j > 1; j--)
    {
        swap(sqlist, 1, j); //���Ѷ��ļ�¼�͵�ǰδ����������������һ������
        HeapAdjust(sqlist, 1, j - 1);//���µ����󶥶�
    }

    std::cout << "\t��������ݣ�" << std::endl;
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
