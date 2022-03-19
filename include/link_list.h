#ifndef LINK_LIST
#define LINK_LIST

#include <vector>
#include <iostream>

using namespace std;

// link list node
typedef struct Node
{
    int data;
    struct Node *next;
} Node, *Node_t;

Node_t HeadInsertCreateLinkList(std::vector<int> data, int length);
Node_t TailInsertCreateLinkList(std::vector<int> data, int length);
void DisplayLinkList(Node_t head);
int GetLinkListLength(Node_t head);
int SearchLinkListData(Node_t head, int data);
bool InsertLinkListData(Node_t head, int i, int data);
bool DeleteLinkListNode(Node_t head, int data);
bool ClearLinkList(Node_t head);

#endif
