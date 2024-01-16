#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::size_t current_size = 0;
        std::unordered_set<int> used_nums;
        for (int value : nums) {
            used_nums.insert(value);
            if (++current_size != used_nums.size()) return true;
        }
        return false;
    }
};

int main() {
    Solution solution = Solution();
    std::vector<int> vec1 = {1, 3, 4, 7, 2, 3};
    std::cout<<solution.containsDuplicate(vec1);
    return 0;
}
