class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, right = k-1;
        if(k>=n) return {*max_element(nums.begin(), nums.end())};
        if(k == 1) return nums;
        vector<int> ans; 
        
        priority_queue<pair<int,int>> pq; //value, index

        for(int i = left; i<=right; i++){
            pq.push({nums[i], i});
        }
        

        while(right < n){
            
            if(right != k-1) pq.push({nums[right], right});

            if(pq.size() >= k){
                while(pq.top().second < left)
                    pq.pop();
                ans.push_back(pq.top().first);
            }
            
            left++; right++;
            
        }

        return ans;
    }
};
