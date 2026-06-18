class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i =0; i<=n; i++){
            int count = 0;
            int tmp = i;
            while(tmp){
                count += (tmp&1);
                tmp = tmp >> 1;
            }
            ans[i] = count;
        }
        return ans;
    }
};
