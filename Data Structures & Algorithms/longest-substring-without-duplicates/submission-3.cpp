class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //trying to make a O(n), O(n^2) would work tho
        int n = s.length(), left = 0, right = 1;
        if(n == 0 || n == 1) return n;
        unordered_set<char> seen; seen.insert(s[left]);
        int maxLen = 1;
        while(left <= right && right <n){
            if(seen.find(s[right]) == seen.end()){
                seen.insert(s[right]);
                maxLen = max(maxLen, right-left +1);
                right++;
            }
            else{
                seen.erase(s[left]);
                left++;                
            }
            
        }

        return maxLen;
    }
};
