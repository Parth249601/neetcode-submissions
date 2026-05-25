class MyQueue {
    deque<int> dq;
public:
    MyQueue() {
        deque<int> dq;
    }
    
    void push(int x) {
        dq.push_back(x);
    }
    
    int pop() {
        int top = dq.front();
        dq.pop_front();
        return top;
    }
    
    int peek() {
        return dq.front();
    }
    
    bool empty() {
        return dq.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */