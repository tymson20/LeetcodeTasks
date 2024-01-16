// 238. Product of Array Except Self

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf1(std::vector<int>& nums) {
        std::vector<int> result(nums.size(), 1);
        for (std::size_t i = 0; i < nums.size(); i++) {
            for (std::size_t j = 0; j < nums.size(); j++) {
                if (j != i) result[j]*=nums[i];
            }
        }
        return result;
    }

    std::vector<int> productExceptSelf2(std::vector<int>& nums) {
        std::size_t size = nums.size();
        std::vector<int> left_product(size, 1);
        std::vector<int> right_product(size, 1);

        for (std::size_t i = 1; i < size; i++) {
            left_product[i] = left_product[i - 1] * nums[i - 1];
        }
        for (int i = size - 2; i >= 0; i--) {
            right_product[i] = right_product[i + 1] * nums[i + 1];
        }
        std::vector<int> result(size);
        for (std::size_t i = 0; i < size; i++) {
            result[i] = left_product[i] * right_product[i];
        }
        return result;
    }

    std::vector<int> productExceptSelf3(std::vector<int>& nums) { // Memory usage optimized
        std::size_t size = nums.size();
        std::vector<int> result(size, 1);

        for (std::size_t i = 1; i < size; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        int right_product = 1;

        for (int i = size - 2; i >= 0; i--) {
            right_product *= nums[i + 1];
            result[i] *= right_product;
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    std::vector<int> nums1 = {1, 3, 4, 3, -1, 2, -5};
    std::vector<int> nums2 = {1, 2, 8, 5, 3, 3};
    auto result1 = solution.productExceptSelf1(nums2);
    auto result2 = solution.productExceptSelf3(nums2);
    for (auto num : result1) {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    for (auto num : result2) {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
