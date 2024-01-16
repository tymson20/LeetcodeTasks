// 125. Valid Palindrome

#include <iostream>

class Solution {
private:
    int typeOfChar(char c) { // return: 0 - non-alphanumeric, 1 - alphanumeric (lowercase letter or number), 2 - uppercase letter
        if ((c > 47 && c < 58) || (c > 96 && c < 123)) return 1;
        else if (c > 64 && c < 91) return 2;
        return 0;
    }

public:
    bool isPalindrome(std::string str) {
        int s = 0, e = str.size() - 1;
        while (s < e) {
            int type_s = typeOfChar(str[s]);
            while (!type_s && s < e) {
                s++;
                type_s = typeOfChar(str[s]);
            }
            int type_e = typeOfChar(str[e]);
            while (!type_e && s < e) {
                e--;
                type_e = typeOfChar(str[e]);
            }
            char char_s = type_s == 2 ? char(str[s] + 32) : str[s];
            char char_e = type_e == 2 ? char(str[e] + 32) : str[e];
            if (char_s != char_e) return false;
            s++, e--;
        }
        return true;
    }
};

int main() {
    Solution solution = Solution();
    std::string s = ".,";
    std::cout<<solution.isPalindrome(s);
    return 0;
}
/* strings
 * "Am4,8 u. Gw--gU=84. MA." 1
 * "a." 1
 * ",." 0 doesn't work
 * "ab" 0
 */

//Line 1065: Char 9: runtime error: addition of unsigned offset to 0x7ffe5a8392c0 overflowed to 0x7ffe5a8392bf (basic_string.h)
//SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/basic_string.h:1074:9