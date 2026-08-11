class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //trying to make a O(n), O(n^2) would work tho
        int n = s.length();
        if(n == 0) return 0;
        unordered_set<char> store;
        int l = 0, r = 0;
        int best = 1;
        while(r < n && l <= r){
            if (store.find(s[r]) == store.end()) {
                store.insert(s[r]);
                best = max(best, r - l + 1);
                r++; // Expand the window to the right
            }
            else{
                store.erase(s[l]);
                l++;
            }
        }
        return best;
    }
};
