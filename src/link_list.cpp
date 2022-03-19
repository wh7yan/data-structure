#include <iostream>
#include "../include/link_list.h"


int main()
{
    std::vector<int> data {1, 2, 3, 4, 5, 6, 7};
    int length = data.size();

    std::cout << "list length => " << length << std::endl; 

    Node_t head = new Node;
    head->next = TailInsertCreateLinkList(data, length);

    DisplayLinkList(head);
    std::cout << "clear node link list\n";
    ClearLinkList(head);
    DisplayLinkList(head);
    return 0;
}

// 头插法创建一个链表
Node_t HeadInsertCreateLinkList(vector<int> data, int length)
{
    // 创建头节点
    Node_t head = new Node;
    head->next = NULL;

    // 头插法
    for(int i = 0; i < length; i++)
    {
        Node_t node = new Node;
        node->data = data[i];
        node->next = head->next;
        head->next = node;
    }

    return head;
}

// 尾插法创建链表
Node_t TailInsertCreateLinkList(vector<int> data, int length)
{
    Node_t head =  new Node;
    Node_t tail;
    head->next = NULL;
    tail = head;

    for(int i = 0; i < length; i++)
    {
        Node_t node = new Node;
        node->data = data[i];
        node->next = NULL;
        tail->next = node;
        tail = node;
    }
    // 不加也可以
    tail->next = NULL;
    return head;
    
}

// 单链表的遍历
void DisplayLinkList(Node_t head)
{
    // 指向第一个元素
    Node_t p = head->next;
    while(p != NULL)
    {
        std::cout << p->data << std::endl;
        p = p->next;
    }
}

// 链表的元素个数
int GetLinkListLength(Node_t head)
{
    int count = 0;
    Node_t p = head->next;

    while(p != NULL)
    {
        count ++;
        p = p->next;
    }
    return count;
}

// 链表元素查找，找到返回true，否则返回false
int SearchLinkListData(Node_t head, int data)
{
    Node_t p = head->next;
    int count = 0;
    while(p != NULL)
    {
        if(data == p->data)
            return count;
        p = p->next;
        count++;
    }
    return false;
}

// 链表插入数据
bool InsertLinkListData(Node_t head, int i, int data)
{
    // 找到要插入的位置的前一个节点
    Node_t p = head->next;
    int index = 0;

    while(p != NULL)
    {
        if(index < i-1) 
            break;
        p = p->next;
    }

    if(p == NULL)
        return false;
    // 加入节点
    Node_t insert_node = new Node;
    insert_node->data = data;
    insert_node->next = p->next;
    p->next = insert_node;
    return true;
}

// 删除链表的节点
bool DeleteLinkListNode(Node_t head, int data)
{
    Node_t q = head;
    Node_t p = head->next;

    while(p != NULL)
    {
        if(p->data == data)
        {
            q->next = p->next;
            delete p;
            return true;
        }else
        {
            q = p;
            p = p->next;
        }
    }

    return false;
}

// 清除链表
bool ClearLinkList(Node_t head)
{
    Node_t p = head;
    while(head != NULL)
    {
        p = head;
        head = head->next;
        delete p;
    }
    return true;
}
