/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    pair<int, int> expandAroundCenter(const string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    /*
        string longestPalindrome(string s)
        {
            size_t half_length = 0;
            size_t max_length = 1;
            size_t max_index = 0;

            // case1: substring of odd length
            for (size_t core = 0; core <= s.size() - 1; core++)
            {
                half_length = 0;
                // if (s[core] != s[core + 1])
                while (core - half_length - 1 >= 0 && core - half_length - 1 <= s.size() - 1 &&
                       core + half_length + 1 >= 0 && core + half_length + 1 <= s.size() - 1)
                {
                    if (s[core - half_length - 1] == s[core + half_length + 1])
                    {
                        half_length++;
                        if (2 * half_length + 1 > max_length)
                        {
                            max_index = core;
                            max_length = 2 * half_length + 1;
                        }
                    }

                    else
                        break;
                }
            }

            // case 2:substring of even length
            for (size_t core = 0; core + 1 <= s.size() - 1; core++)
            {
                if (s[core] == s[core + 1])
                {
                    if (2 > max_length)
                    {
                        max_index = core;
                        max_length = 2;
                    }
                    while (core - half_length - 1 >= 0 && core - half_length - 1 <= s.size() - 1 &&
                           core + half_length + 2 >= 0 && core + half_length + 2 <= s.size() - 1)
                    {
                        if (s[core - half_length - 1] == s[core + half_length + 2])
                        {
                            half_length++;
                            if (2 * half_length + 2 > max_length)
                            {
                                max_index = core;
                                max_length = 2 * half_length + 2;
                            }
                        }

                        else
                            break;
                    }
                }
            }

            string res = s.substr(max_index - (max_length - 1) / 2, max_length);
            return res;
        }
    */
};
// @lc code=end
