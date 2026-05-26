class FreqStack {
    unordered_map<long long, int> freqs; //val -> freq
    unordered_map<int, stack<int>> groupMap;
    int maxFreq = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {

        freqs[val]++;
        maxFreq = max(maxFreq, freqs[val]); 
        groupMap[freqs[val]].push(val);

    }
    
    
    int pop() {
        int val = groupMap[maxFreq].top();
        groupMap[maxFreq].pop();
        freqs[val]--;

        if(groupMap[maxFreq].empty()){
            maxFreq--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */