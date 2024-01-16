// 11. Container With Most Water

#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0, right = int(height.size()) - 1;
        int area, max_area = 0;
        while (left < right) {
            if (height[left] > height[right]) {
                area = (right - left) * height[right];
                right--;
            }
            else {
                area = (right - left) * height[left];
                left++;
            }
            max_area = std::max(max_area, area);
        }
        return max_area;
    }
};

int main() {
    Solution solution = Solution();
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    std::cout<<solution.maxArea(height)<<std::endl;
    return 0;
}
