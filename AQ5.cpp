//Student Id: 1024030975
//Lakshay Singh
//Assignment question 5 solution
#include <iostream>
#include <cstring>
using namespace std;
class Stack {
    int top, capacity;
    int* arr;
public:
    Stack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }
    void push(int x) { if (top != capacity - 1) arr[++top] = x; }
    int pop() { return (top == -1) ? 0 : arr[top--]; }
    bool isEmpty() { return top == -1; }
};
int evaluate(char exp[]) {
    int len = strlen(exp);
    Stack s(len);
    for (int i = 0; i < len; i++) {
        char c = exp[i];
        if (c >= '0' && c <= '9') s.push(c - '0');
        else {
            int val2 = s.pop();
            int val1 = s.pop();
            if (c == '+') s.push(val1 + val2);
            else if (c == '-') s.push(val1 - val2);
            else if (c == '*') s.push(val1 * val2);
            else if (c == '/') s.push(val1 / val2);
        }
    }
    return s.pop();
}
int main() {
    char exp[1000];
    cout << "Enter postfix expression: ";
    cin >> exp;
    cout << "Evaluation result: " << evaluate(exp) << endl;
}
