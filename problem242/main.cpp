// Problem 242. Valid Anagram
#include <iostream>
#include <algorithm>
#include <functional>
#define SIZE 26

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        for (std::size_t i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) return false;
        }
        return true;
    }

    bool isAnagram2(std::string s, std::string t) {
        if (s.size() != t.size()) return false;
        short int table[SIZE] = {0};
        for (std::size_t i = 0; i < s.size(); i++) {
            table[s[i]-'a']++;
            table[t[i]-'a']--;
        }
        for (std::size_t i = 0; i < SIZE; i++) {
            if (table[i] != 0) return false;
        }
        return true;
    }
};

int main() {
    Solution solution = Solution();
    std::string s1 = "nl";
    std::string t1 = "cx";
    std::cout<<solution.isAnagram2(s1, t1);
    return 0;
}
