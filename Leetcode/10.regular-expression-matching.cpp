/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int i = s.size(), j = p.size();
        bool dp[i + 1][j + 1];

        // Boundary condition
        for (int k = 0; k <= i; k++)
            dp[k][0] = false;
        for (int k = 0; k <= j; k++)
            dp[0][k] = false;
        dp[0][0] = true;
        if (p[0] == '.' || p[1] == '*')
            dp[0][1] == true;
        for (int k = 1; k <= j; k++)
        {
            if (p[0] == '.' && p[1] == '*')
                dp[0][k] = true;
        }
    }
};
// @lc code=end
