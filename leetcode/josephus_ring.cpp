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
