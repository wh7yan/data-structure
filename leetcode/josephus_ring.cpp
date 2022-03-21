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

// using array index 
int JosephusRingByArray(int n, int m)
{
    if(n == 0 && m == 0)
        return 0;
    // imitate ring by array
    vector<int> ring_array;
    for(int i = 0; i < n; i++)
        ring_array.push_back(i);

    int count = 1;
    int position = 0;

    int length = n;

    while(length > 1)
    {
        if(ring_array[position] > -1)
        {
            if(count == m)
            {
                ring_array[position] = -1;
                position = (position+1)%n;
                length--;
                count = 1;
                
            }else
            {
                position = (position+1)%n;
                count++;     
            }
        }else
            position = (position+1)%n;
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(ring_array[i] > 0)
            ans = ring_array[i];
    }
    return ans;
}

// using anthor way by array
int JosephusRingByAnthorArray(int n, int m)
{
    vector<int> ring_array;
    for(int i = 0; i < n-1; i++)
        ring_array.push_back(i+1);
    
    // circulate linked list by array
    // 每一个value代表了下一个节点的位置，形成一个循环
    ring_array.push_back(0); 

    int position = 0;
    int prior = n-1;
    int count = 1;
    int length = n;

    while(length > 1)
    {
        if(count == m)
        {
            ring_array[prior] = ring_array[position];
            ring_array[position] = -1;
            position = ring_array[prior];
            count = 1;
            length--;
        }else
        {
            prior = position;
            position = ring_array[position];
            count++;
        }
    }
    return position;
}
