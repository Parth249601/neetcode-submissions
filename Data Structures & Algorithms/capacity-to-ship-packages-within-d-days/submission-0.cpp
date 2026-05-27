class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int maxCap){
        int days_req = 0, total_weight = 0;
        if(*max_element(weights.begin() ,weights.end()) > maxCap) return false;

        for(int i=0; i< weights.size(); i++){
            total_weight += weights[i];
            if(total_weight > maxCap) {days_req++; total_weight = 0; i--;}
        }
        return days_req + 1 <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
       //the maximum capacity is in between 1 and total Sum
        int maxCap =0;
        for(int num : weights)
            maxCap += num;
        
        int start = 0, end = maxCap;
        while(start < end){
            int mid = start + (end-start)/2;
            if(start == end) return start;
            if(isPossible(weights, days, mid))
                end = mid;
            else
                start = mid + 1;
        } 
        return start;
    }
};