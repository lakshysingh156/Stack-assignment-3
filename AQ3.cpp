//Student Id: 1024030975
//Lakshay Singh
//Assignment question 3 solution
#include <iostream>
#include <cstring>
using namespace std;
class Stack {
    int top, capacity;
    char* arr;
public:
    Stack(int cap) {
        capacity = cap;
        arr = new char[capacity];
        top = -1;
    }
    void push(char c) { if (top != capacity - 1) arr[++top] = c; }
    char pop() { return (top == -1) ? '\0' : arr[top--]; }
    bool isEmpty() { return top == -1; }
    char peek() { return (top == -1) ? '\0' : arr[top]; }
};
bool isBalanced(char exp[]) {
    int len = strlen(exp);
    Stack s(len);
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (c == '(' || c == '[' || c == '{') s.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (s.isEmpty()) return false;
            char t = s.pop();
            if ((c == ')' && t != '(') || (c == ']' && t != '[') || (c == '}' && t != '{')) return false;
        }
    }
    return s.isEmpty();
}
int main() {
    char exp[1000];
    cout << "Enter an expression: ";
    cin >> exp;
    if (isBalanced(exp)) cout << "Balanced\n"; 
    else cout << "Not Balanced\n";
}
