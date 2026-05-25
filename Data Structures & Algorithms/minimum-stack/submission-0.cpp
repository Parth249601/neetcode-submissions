class MinStack {
    stack<pair<int,int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) st.push({val, val});
        else{
            pair<int,int> top = st.top();
            if(val < top.second) st.push({val, val});
            else st.push({val, top.second});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
