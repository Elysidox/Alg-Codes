/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
#include <string>
using namespace std;
// #define solution_1 1
#define solution_2 1
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
#ifdef solution_1
        size_t len = s.size();
        int row[len];
        row[0] = 1;
        int current_row = 1, grad = 1;
        for (size_t i = 1; i < len; i++)
        {
            current_row += grad;
            row[i] = current_row;
            if (current_row == numRows || current_row == 1)
                grad = -grad;
        }
        string res;
        for (int i = 1; i <= numRows; i++)
        {
            for (size_t j = 0; j < len; j++)
            {
                if (row[j] == i)
                    res.push_back(s[j]);
            }
        }
        return res;
#endif
#ifdef solution_2
        size_t period = 2 * numRows - 2;
        string res;
        for (int row = 1; row <= numRows; row++)
        {
            if (row == 1 || row == numRows)
            {
                for (size_t i = row - 1; i < s.size(); i += period)
                    res.push_back(s[i]);
            }
            else
            {
                for (size_t i = row - 1; i < s.size(); i += period)
                {
                    res.push_back(s[i]);
                    if (i + 2 * (numRows - row) < s.size())
                        res.push_back(s[i + 2 * (numRows - row)]);
                }
            }
        }
        return res;
#endif
    }
};
// @lc code=end
