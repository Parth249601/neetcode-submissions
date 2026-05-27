class Solution {
public:
    bool canComplete(vector<int>& piles, int h, int k){
        int total_hrs = 0;
        for(auto pile : piles){
            total_hrs += ceil((double)pile/k);
        }
        return total_hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // k would be between 1 and the maximum element in the arr piles
        int start = 1, end = *max_element(piles.begin(), piles.end());
        while(start < end){
            int mid = start + (end - start)/2;
            if(start == end) return start;
            if(canComplete(piles, h, mid))
                end = mid;
            else 
                start = mid + 1; 
        }
        return start;
    }
};
