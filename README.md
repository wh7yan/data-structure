#### Data Structure Foundation Knowledge

##### Contents Tree

```C++
.
├── README.md
├── include
│   ├── leetcode.h
│   └── link_list.h
├── leetcode
│   ├── josephus_ring.cpp
│   └── two_sum.cpp
└── src
    ├── link_list.cpp
    ├── main.cpp
```

##### Link List
* **structure**

  ```C++
  typedef struct Node
  {
    int data;
    struct Node *next;
  } Node, *Node_t;
  ```

* **File**
  1. header file => ./include/link_list.h
  2. src file => ./src/link_list.cpp

* **Function**

  ```C++
  // Two way create link list 
  Node_t HeadInsertCreateLinkList(std::vector<int> data, int length);
  Node_t TailInsertCreateLinkList(std::vector<int> data, int length);
  
  // Traverse link list
  void DisplayLinkList(Node_t head);
  
  // Get link list length
  int GetLinkListLength(Node_t head);
  
  // Search data from link list
  int SearchLinkListData(Node_t head, int data); 
  
  // Insert data into link list
  bool InsertLinkListData(Node_t head, int i, int data);
  
  // Delete link list node
  bool DeleteLinkListNode(Node_t head, int data);
  
  // Clear link list
  bool ClearLinkList(Node_t head);
  ```



* **LeetCode**

  * Josephus ring problem using circulate link list 

  * ```c++
    int JosephusRing(int n, int m);
    int JosephusRingByArray(int n, int m);
    int JosephusRingByAnthorArray(int, int m);
    int JosephusRingByMath(int n, int m)；
    ```
  
     * Two Sum problem using double pionts 
  
     * ```c++
       vector<int> TwoSum(vector<int> &nums, int target);
       vector<int> TwoSumByDoublePoint(vector<int> &nums, int target);
       vcetor<int> TwoSumByHashMap(vector<int> &nums, int target);
       ```
  
       
