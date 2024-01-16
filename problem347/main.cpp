#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:

    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> number_of_values; // pair<particular element, num_of_element>
        for (const auto num : nums) {
            number_of_values[num]++;
        }
        std::priority_queue<std::pair<int, int>> priority_queue; // pair<num_of_element, particular element>
        for (const auto pair: number_of_values) {
            priority_queue.emplace(pair.second, pair.first);
        }
        std::vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = priority_queue.top().second;
            priority_queue.pop();
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    std::vector<int> nums1 = {1, 3, 2, 2, 6, 2, 1, 3, 1};
    std::vector<int> result = solution.topKFrequent(nums1, 1);
    for (int num : result) {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
