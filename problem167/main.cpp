// 167. Two Sum II - Input Array Is Sorted

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int num1_idx = 0, num2_idx = 1;
        int diff;
        std::vector<int> result = {0, 0};
        while (true) {
            diff = target - numbers[num1_idx];
            while (num2_idx <= numbers.size() - 1 && numbers[num2_idx] <= diff) {
                if (numbers[num2_idx] == diff) {
                    result[0] = num1_idx + 1;
                    result[1] = num2_idx + 1;
                    return result;
                }
                else {
                    num2_idx++;
                }
            }
            while (numbers[num1_idx] == numbers[num1_idx + 1]) {num1_idx++;}
            num1_idx++;
            num2_idx = num1_idx + 1;
        }
    }
};

int main() {
    Solution solution = Solution();
    std::vector<int> nums = {-1,-1,-1,-1,-1,-1,-1,-1,1,1};
    auto result = solution.twoSum(nums, 2);
    std::cout<<"["<<result[0]<<","<<result[1]<<"]"<<std::endl;
    return 0;
}
