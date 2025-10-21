//Student Id: 1024030975
//Lakshay Singh
//Assignment question 1 solution
#include <iostream>
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
    void push(int x) { if (!isFull()) arr[++top] = x; else cout << "Stack is Full\n"; }
    void pop() { if (!isEmpty()) top--; else cout << "Stack is Empty\n"; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == capacity - 1; }
    void display() { if (isEmpty()) cout << "Stack is Empty\n"; else { for (int i = top; i >= 0; i--) cout << arr[i] << " "; cout << endl; } }
    int peek() { return isEmpty() ? -1 : arr[top]; }
};
int main() {
    int n;
    cout << "Enter stack capacity: ";
    cin >> n;
    Stack s(n);
    int choice, val;
    while (true) {
        cout << "\n1.Push  2.Pop  3.isEmpty  4.isFull  5.Display  6.Peek  7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) { cout << "Enter value: "; cin >> val; s.push(val); }
        else if (choice == 2) s.pop();
        else if (choice == 3) cout << (s.isEmpty() ? "Yes\n" : "No\n");
        else if (choice == 4) cout << (s.isFull() ? "Yes\n" : "No\n");
        else if (choice == 5) s.display();
        else if (choice == 6) cout << "Top element: " << s.peek() << endl;
        else if (choice == 7) break;
    }
}
