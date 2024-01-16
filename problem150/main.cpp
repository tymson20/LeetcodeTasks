// 150. Evaluate Reverse Polish Notation

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stack;
        for (const std::string str : tokens) {
            if (str == "+") {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                stack.push(a + b);
            }
            else if (str == "-") {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                stack.push(a - b);
            }
            else if (str == "*") {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                stack.push(a * b);
            }
            else if (str == "/") {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                stack.push(a / b);
            }
            else {
                stack.push(std::stoi(str));
            }
        }
        return stack.top();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
