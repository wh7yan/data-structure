#include "../include/leetcode.h"
#include <algorithm>
#include <unordered_map>


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

vector<int> TwoSumByHashMap(vector<int> &nums, int target)
{
    // create unordered map to nums value : index
    unordered_map<int, int> map;

    // ans of vector
    vector<int> ans;
    int length = nums.size();
    for(int i = 0; i < length; i++)
    {
        int value = target - nums[i];

        if(map.count(value))
        {
            ans.push_back(map.at(value));
            ans.push_back(i);
            return ans;
        }
        map[nums[i]] = i;
    }
    return ans;
}
