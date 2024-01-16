#include <iostream>
#include <vector>
#include <unordered_map>

#define CHARS 26

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<int, std::vector<std::size_t>> map; // store vector of indexes of the result vector, which the sum of chars is equal to key
        std::vector<std::vector<std::string>> result;
        for (const std::string& str : strs) {
            int sum_of_chars = 0;
            for (int i = 0; i < str.size(); i++) {
                sum_of_chars += str[i] - 'a';
            }
            if (map.count(sum_of_chars) == 0) {
                map[sum_of_chars].push_back(result.size());
                result.push_back({str});
            }
            else {
                bool is_anagram = false;
                for (const auto idx : map[sum_of_chars]) {
                    is_anagram = isAnagram(str, result[idx][0]);
                    if (is_anagram) {
                        result[idx].push_back(str);
                        break;
                    }
                }
                if (!is_anagram) {
                    map[sum_of_chars].push_back(result.size());
                    result.push_back({str});
                }
            }
        }
        return result;
    }

    bool isAnagram(const std::string& s, const std::string& t) {
        if (s.size() != t.size()) return false;
        short int table[CHARS] = {0};
        for (std::size_t i = 0; i < s.size(); i++) {
            table[s[i]-'a']++;
            table[t[i]-'a']--;
        }
        for (std::size_t i = 0; i < CHARS; i++) {
            if (table[i] != 0) return false;
        }
        return true;
    }
};

int main() {
    Solution solution = Solution();
    std::vector<std::string> strings = {"hb","df","ee","cg","ai","abc","fd","ia"};
    auto result = solution.groupAnagrams(strings);
    return 0;
}
