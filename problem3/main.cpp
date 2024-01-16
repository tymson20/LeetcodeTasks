// Problem 3. Longest Substring Without Repeating Characters

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        unsigned short int max_length = 0;
        for (std::size_t i = 0; i < s.size(); i++) {
            unsigned short int length = 1;
            std::size_t j = i + 1;
            std::vector<char> used_characters = {s[i]};
            while (auto find_it = std::find(used_characters.cbegin(), used_characters.cend(), s[j]) == used_characters.cend() && s[j] != '\0') {
                used_characters.push_back(s[j]);
                length++;
                j++;
            }
            if (length > max_length) max_length = length;
        }
        return max_length;
    }
};*/


class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        unsigned int max_length = 0, length = 0;
        std::unordered_map<char, unsigned int> used_chars;
        unsigned int start = 0;
        for (std::size_t i = 0; i < s.size(); i++) {
            used_chars.insert({s[i], i});
            length++;
            if (length != used_chars.size()) {
                length--;
                max_length = length > max_length ? length : max_length;
                for (std::size_t j = start; j < used_chars[s[i]]; j++) {
                    used_chars.erase(used_chars.find(s[j]));
                }
                start = used_chars[s[i]] + 1;
                used_chars[s[i]] = i;
                length = used_chars.size();
            }
        }
        max_length = length > max_length ? length : max_length;
        return int(max_length);
    }
};

int main() {
    Solution solution = Solution();
    int len = solution.lengthOfLongestSubstring("abcdedgham");
    std::cout<<len<<std::endl;

    // TEST

    /*std::unordered_map<char, int> map;
    std::string s = "abcd";
    map.insert({s[0], 2});
    map.insert({s[1], 3});
    map.erase(s[0]);
    std::cout<<map.size();*/
    return 0;
}


