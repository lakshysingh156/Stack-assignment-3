//Student Id: 1024030975
//Lakshay Singh
//Assignment question 2 solution
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
};
int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;
    int len = strlen(str);
    Stack s(len);
    for (int i = 0; i < len; i++) s.push(str[i]);
    cout << "Reverse is ";
    while (!s.isEmpty()) cout << s.pop();
    cout << endl;
    return 0;
}
