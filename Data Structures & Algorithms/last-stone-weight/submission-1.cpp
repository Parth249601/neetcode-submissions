class Solution {
    using maxHeap = priority_queue<int>;
public:
    int helper(maxHeap& pq){
        if(pq.size() == 0) return 0;
        if(pq.size() == 1) return pq.top();

        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        if(first == second) return helper(pq);
        else{
            pq.push(abs(first-second));
            return helper(pq);
        }
    }
    int lastStoneWeight(vector<int>& stones) {
        maxHeap pq;
        for(int i=0; i< stones.size(); i++)
            pq.push(stones[i]);
        return helper(pq);
        
    }
};
