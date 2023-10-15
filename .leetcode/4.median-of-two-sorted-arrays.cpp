/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int getKthElement(vector<int> &nums1, vector<int> &nums2, size_t k)
    {
        size_t len1 = nums1.size();
        size_t len2 = nums2.size();
        size_t index1 = 0, index2 = 0;

        while (true)
        {
            // Border condition
            if (index1 == len1)
                return nums2[k + index2 - 1];
            if (index2 == len2)
                return nums1[k + index1 - 1];
            if (k == 1)
                return min(nums1[index1], nums2[index2]);

            // Ordinary condition
            size_t newIndex1 = min(index1 + k / 2 - 1, len1 - 1);
            size_t newIndex2 = min(index2 + k / 2 - 1, len2 - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2)
            {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else
            {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        size_t length = nums1.size() + nums2.size();
        if (length % 2 == 0)
            return ((getKthElement(nums1, nums2, length / 2) +
                     getKthElement(nums1, nums2, length / 2 + 1)) /
                    2.0);
        else
            return (getKthElement(nums1, nums2, (length + 1) / 2));
    };
};
// @lc code=end
