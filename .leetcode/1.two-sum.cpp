/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        map<int, size_t> hash;
        for (size_t index = 0; index < nums.size(); index++)
            hash[nums[index]] = index;
        for (size_t index = 0; index < nums.size(); index++)
        {
            if (hash.find(target - nums[index]) != hash.end())
            {
                if (hash[target - nums[index]] == index)
                    continue;
                res.push_back(index);
                res.push_back(hash[target - nums[index]]);
                break;
            }
        }
        return res;
    }
};
// @lc code=end
