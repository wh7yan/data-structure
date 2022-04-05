#include "../include/leetcode.h"

int main()
{
    vector<int> nums {2, 1, 4, 5, 6, 3};
    int target = 11;
    vector<int> ans = TwoSumByDoublePoint(nums, target);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
