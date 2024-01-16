// 4. Median of Two Sorted Arrays

#include <iostream>
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        if (nums1.empty()) {
            std::size_t size = nums2.size();
            if (size % 2 == 1) return nums2[size/2];
            else return (nums2[size/2 - 1] + nums2[size/2])/2.0;
        }
        else if (nums2.empty()) {
            std::size_t size = nums1.size();
            if (size % 2 == 1) return nums1[size/2];
            else return (nums1[size/2 - 1] + nums1[size/2])/2.0;
        }
        else {
            auto it1_start = nums1.cbegin(), it1_end = nums1.cend();
            auto it2_start = nums2.cbegin(), it2_end = nums2.cend();
            it1_end--, it2_end--;
            if (it1_start == it1_end && it2_start == it2_end) return (*it1_start + *it2_start)/2.0;
            while (it1_start <= it1_end && it2_start <= it2_end) {
                if (*it1_start <= *it2_start) it1_start++;
                else it2_start++;
                if (*it1_end >= *it2_end) it1_end--;
                else it2_end--;
                if (it1_start == it1_end && it2_start == it2_end) return (*it1_start + *it2_start)/2.0;
            }
            if (it1_start > it1_end) {
                int diff = it2_end - it2_start;
                if (diff % 2 == 0) return *(it2_start + diff/2);
                else return (*(it2_start + diff/2) + *(it2_start + diff/2 + 1))/2.0;
            }
            else {
                int diff = it1_end - it1_start;
                if (diff % 2 == 0) return *(it1_start + diff/2);
                else return (*(it1_start + diff/2) + *(it1_start + diff/2 + 1))/2.0;
            }
            return -1.0;
        }
    }
};

int main() {
    Solution solution = Solution();
    std::vector<int> vec1 = {-3};
    std::vector<int> vec2 = {2};
    double res = solution.findMedianSortedArrays(vec1, vec2);
    std::cout<<res<<std::endl;
    return 0;
}
