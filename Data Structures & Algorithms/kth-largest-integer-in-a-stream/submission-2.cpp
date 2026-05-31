class KthLargest {
    using minHeap = priority_queue<int, vector<int>, greater<int>>;
    vector<int> nums; int k; minHeap pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
        for(int i=0; i< nums.size(); i++){
            if(pq.size() < k) {pq.push(nums[i]); continue;}
            if(pq.size() == k && nums[i] > pq.top()){
                pq.pop(); 
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        pq.push(val);                      // always non-empty after this
        if ((int)pq.size() > k) pq.pop();
        return pq.top();    
    }
};
