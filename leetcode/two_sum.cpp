#include "../include/leetcode.h"
#include <algorithm>


vector<int> TwoSumByDoublePoint(vector<int> &nums, int target)
{
    // create a array include index 
    vector<int> indices;
    int length = nums.size();
    for(int i = 0; i < length; i++)
        indices.push_back(i);

    // sort indices
    sort(indices.begin(), indices.end(), 
            [nums, indices](int i, int j)
            {
                return nums[indices[i]] < nums[indices[j]];  
            }
         );

    int head = 0;
    int tail = length - 1;

    vector<int> ans;
    while(head < tail)
    {
        int sum = nums[indices[head]] + nums[indices[tail]];

        if(sum == target)
        {
            ans.push_back(indices[head]); 
            ans.push_back(indices[tail]);
            break;
        }else if(sum < target)
        {
            head++;
        }else
        {
            tail--;
        }
    }
    return ans;
}
