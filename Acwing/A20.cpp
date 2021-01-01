
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> in, out;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        // 一遍，然后正序一遍即可
        while (out.size()) {
            in.push(out.top());
            out.pop();
        }
        in.push(x);

        while (in.size()) {
            out.push(in.top());
            in.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = out.top();
        out.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        return out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return out.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */