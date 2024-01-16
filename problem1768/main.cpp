#include <iostream>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string result;
        result.reserve(word1.size() + word2.size());
        int common_size = word1.size() > word2.size() ? word2.size() : word1.size();
        for (int i = 0; i < common_size; i++) {
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }
        if (common_size == word1.size()) result.append(word2.cbegin() + common_size, word2.cend());
        else result.append(word1.cbegin() + common_size, word1.cend());
        return result;
    }
};

int main() {
    Solution solution = Solution();
    std::string str1 = "a";
    std::string str2 = "wghzx";
    std::cout<<solution.mergeAlternately(str1, str2)<<std::endl;
    return 0;
}
