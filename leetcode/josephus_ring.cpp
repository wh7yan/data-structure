#include "../include/leetcode.h"
#include "../include/link_list.h"

// using circulate link list 
int JosephusRing(int n, int m)
{
    // create ring
    Node_t head = new Node;
    Node_t tail;
    tail = head;

    // tail insert way
    for(int i = 0; i < n; i++)
    {
        Node_t node = new Node;
        node->data = i;     
        tail->next = node;
        tail = tail->next;
    }
    tail->next = head->next;

    // josephus problem ans
    Node_t q, p;

    q = head;
    p = head->next;

    if(p->next == p)
        return 0;
    
    int count = 0;
    while(q != p)
    {
        count++;
        if(count == m)
        {
            q->next = p->next;
            delete p;
            p = q->next;
            count = 0;
        }else
        {
            q = p;
            p = p->next;
        }
    }
    int ans =  p->data;
    delete p;
    return ans;
}

