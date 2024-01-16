// 128. Longest Consecutive Sequence

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq(std::greater<int>(), nums);
        int max_length = 0;
        int prev_num = pq.top();
        pq.pop();
        int len = 1;
        while (!pq.empty()) {
            if (prev_num + 1 == pq.top()) len++;
            else if (prev_num != pq.top()) {
                if (len > max_length) max_length = len;
                len = 1;
            }
            prev_num = pq.top();
            pq.pop();
        }
        return len > max_length ? len : max_length;
    }
};

int main() {
    Solution solution = Solution();
    std::vector<int> nums = {100,4,200,1,3,2};
    int result = solution.longestConsecutive(nums);
    std::cout<<result<<std::endl;
    return 0;
}
