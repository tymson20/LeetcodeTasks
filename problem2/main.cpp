// Problem 2. Add Two Numbers

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first_node = new ListNode;
        ListNode* previous_node = nullptr;
        ListNode* current_node = first_node;
        ListNode* current_node_num1 = l1;
        ListNode* current_node_num2 = l2;
        int value = 0;
        first_node->val = current_node_num1->val + current_node_num2->val + value;
        previous_node = current_node;
        if (current_node->val >= 10) {
            value = 1;
            current_node->val -= 10;
        }
        current_node_num1 = current_node_num1->next;
        current_node_num2 = current_node_num2->next;
        while (current_node_num1 != nullptr && current_node_num2 != nullptr) {
            current_node = new ListNode(current_node_num1->val + current_node_num2->val + value);
            value = 0;
            if (current_node->val >= 10) {
                value = 1;
                current_node->val -= 10;
            }
            previous_node->next = current_node;
            current_node_num1 = current_node_num1->next;
            current_node_num2 = current_node_num2->next;
            previous_node = current_node;
        }
        ListNode* current_node_num = current_node_num1 == nullptr ? current_node_num2 : current_node_num1;
        while (current_node_num != nullptr) {
            current_node = new ListNode(current_node_num->val + value);
            value = 0;
            if (current_node->val >= 10) {
                value = 1;
                current_node->val -= 10;
            }
            previous_node->next = current_node;
            current_node_num = current_node_num->next;
            previous_node = current_node;
        }
        if (value == 1) {
            current_node = new ListNode(1);
            previous_node->next = current_node;
        }
        return first_node;
    }

    ListNode* createNumber(int tab[], int length) {
        ListNode* first_node = new ListNode(tab[0]);
        ListNode* current_node;
        ListNode* previous_node = first_node;
        for (std::size_t i = 1; i < length; i++) {
            current_node = new ListNode(tab[i]);
            previous_node->next = current_node;
            previous_node = current_node;
        }
        return first_node;
    }

    void displayNumber(ListNode* list) {
        ListNode* current_node = list;
        std::vector<int> tab = {};
        while (current_node != nullptr) {
            tab.push_back(current_node->val);
            current_node = current_node->next;
        }
        for (int i = tab.size() - 1; i >= 0; i--) {
            std::cout<<tab[i];
        }
        std::cout<<std::endl;
    }

};

int main() {
    int number1[7] = {9, 9, 9, 9, 9, 9, 9};
    int number2[4] = {9, 9, 9, 9};
    int number3[4] = {1, 2, 3, 4};
    Solution solution = Solution();
    ListNode* num1 = solution.createNumber(number1, 7);
    ListNode* num2 = solution.createNumber(number2, 4);
    ListNode* num3 = solution.createNumber(number3, 4);
    ListNode* result = solution.addTwoNumbers(num1, num2);
    solution.displayNumber(result);
    return 0;
}