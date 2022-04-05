#include "../include/leetcode.h"

int main()
{
    vector<int> nums {2, 9, 1, 5, 6, 3};
    int target = 10;
    // vector<int> ans = TwoSum(nums, 11);
    // vector<int> ans = TwoSumByDoublePoint(nums, target);
    vector<int> ans = TwoSumByHashMap(nums, target);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
