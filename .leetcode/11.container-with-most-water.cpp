/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int res = min(height[i], height[j]) * (j - i);
        while (i < j)
        {
            res = height[i] < height[j] ? 
                  max(res, (j - i) * height[i++]) : 
                  max(res, (j - i) * height[j--]);
        }
        return res;
    }
};
// @lc code=end
