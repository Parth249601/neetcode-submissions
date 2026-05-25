class MyStack {
    deque<int> dq;
public:
    MyStack() {
        deque<int> dq;
    }
    
    void push(int x) {
        dq.push_front(x);
    }
    
    int pop() {
        int top = dq.front();
        dq.pop_front();
        return top;
    }
    
    int top() {
        return dq.front();
    }
    
    bool empty() {
        return dq.size() == 0;
    }
};
//q1 -> push the thing and q2-> (3->2->1) 

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */