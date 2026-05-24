class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int max_area = 0;
        int l = 0, r = n-1;
        while(l < r){
            int currArea = min(heights[l], heights[r]) * (r-l); 
            max_area = max(currArea, max_area);
            if(heights[l] <= heights[r]) l++;
            else r--;
        }
        return max_area;
    }
};
