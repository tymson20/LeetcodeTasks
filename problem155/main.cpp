// 155. Min Stack

#include <iostream>

class MinStack {
public:
    MinStack() {
        size = 0;
        reserved = 2;
        stack = new int[reserved];
        min_array = new int[reserved];
    }

    void push(int val) {
        if (size == 0) {
            stack[size] = val;
            min_array[size] = val;
        }
        else {
            if (size == reserved) resize();
            if (val < min_array[size - 1]) min_array[size] = val;
            else min_array[size] = min_array[size - 1];
            stack[size] = val;
        }
        size++;
    }

    void pop() {
        size--;
    }

    int top() {
        return stack[size - 1];
    }

    int getMin() {
        return min_array[size - 1];
    }

    void test() {
        std::cout<<"Stack: ";
        for (std::size_t i = 0; i < size; i++) std::cout<<stack[i]<<" ";
        std::cout<<"Min Array: ";
        for (std::size_t i = 0; i < size; i++) std::cout<<min_array[i]<<" ";
        std::cout<<std::endl;
    }
private:
    void resize() {
        int* new_stack = new int[2*reserved];
        int* new_min_array = new int[2*reserved];
        for (std::size_t i = 0; i < reserved; i++) {
            new_stack[i] = stack[i];
            new_min_array[i] = min_array[i];
        }
        delete[] stack;
        delete[] min_array;
        stack = new_stack;
        min_array = new_min_array;
        reserved *= 2;
    }

    int* stack;
    int* min_array;
    std::size_t size, reserved;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    std::cout<<minStack->getMin()<<std::endl; // return -3
    minStack->pop();
    std::cout<<minStack->top()<<std::endl;    // return 0
    std::cout<<minStack->getMin()<<std::endl; // return -2
    return 0;
}
