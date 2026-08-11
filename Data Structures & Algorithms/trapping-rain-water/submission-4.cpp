class Solution {
public:
    int trap(vector<int>& height) {
        int l =0, r =(int) height.size() - 1;
        int maxL =0, maxR=0, ans =0;

        while(l < r){
            if(height[l] <= height[r]){
                maxL = max(maxL, height[l]);
                ans += maxL - height[l];
                l++;
            }
            else{
                maxR = max(maxR, height[r]);
                ans += maxR - height[r];
                r--;
            }
        }
        return ans;
    }
};