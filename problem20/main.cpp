// 20. Valid Parentheses

#include <iostream>
#include <stack>
#include <map>

class Solution {
public:
    bool isValid(std::string s) {
        std::map<char, char> map = {{'(', ')'}, {'[', ']'}, {'{', '}'}, {')', '0'}, {']', '0'}, {'}', '0'}};
        std::stack<char> stack;
        for (const char character : s) {
            if (map[character] != '0') stack.push(map[character]);
            else {
                if (!stack.empty() && stack.top() == character) stack.pop();
                else return false;
            }
        }
        if (stack.empty()) return true;
        return false;
    }
};

int main() {
    Solution solution = Solution();
    std::string s = ")}[]";
    std::cout<<solution.isValid(s)<<std::endl;
    return 0;
}
