//Student Id: 1024030975
//Lakshay Singh
//Assignment question 4 solution
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
    char peek() { return (top == -1) ? '\0' : arr[top]; }
    bool isEmpty() { return top == -1; }
};
int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return -1;
}
void infixToPostfix(char exp[]) {
    int len = strlen(exp);
    Stack s(len);
    cout << "Postfix expression: ";
    for (int i = 0; i < len; i++) {
        char c = exp[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) cout << c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') cout << s.pop();
            if (!s.isEmpty()) s.pop();
        }
        else {
            while (!s.isEmpty() && prec(s.peek()) >= prec(c)) cout << s.pop();
            s.push(c);
        }
    }
    while (!s.isEmpty()) cout << s.pop();
    cout << endl;
}
int main() {
    char exp[1000];
    cout << "Enter infix expression: ";
    cin >> exp;
    infixToPostfix(exp);
}
