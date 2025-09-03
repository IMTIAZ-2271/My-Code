#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> stk1, stk2;

public:
    void push(int x) {
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk2.push(x);
        while (!stk2.empty()) {
            stk1.push(stk2.top()); 
            stk2.pop();
        }
    }

    int front() {
        if (stk1.empty())
            return -1;
        return stk1.top();
    }

    void pop() {
        if (!stk1.empty()) stk1.pop();
    }

    int size() {
        return stk1.size();
    }
};

int main() {
    Queue q1;

    q1.push(2);
    q1.push(0);
    q1.push(2);
    q1.push(5);

    while (q1.size() > 0) {
        cout << q1.front() << " ";
        q1.pop();
    }

    cout << "\nSize after pops: " << q1.size() << endl;
    return 0;
}
