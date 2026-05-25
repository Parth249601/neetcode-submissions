class Solution {
public:
    int longestSub(string& s){
        //return the length of the longest substring with only one char
        int n = s.length();
        if(n == 0 || n == 1) return n;
        unordered_set<char> seen; 
        int left = 0, right = 1, maxLen = 1; seen.insert(s[left]);
        while(left <= right & right < n){
            if(seen.find(s[right]) != seen.end()){
                maxLen = max(maxLen, right - left  +1);
                right++;
            }
            else{
                seen.clear();
                seen.insert(s[right]);
                left = right; right++;
            }
        }
        return maxLen; 
    }
    int characterReplacement(string s, int k) {
        //the question to ask is whether I can make the current window valid if i can then
        //move the right pointer, store the result and continue; and if not then move the right pointer


        int n = s.length();
        if(n == 0 || n == 1) return n;

        unordered_set<char> seen;
        int left = 0, right = 0, maxLen = 1;

        unordered_map<char, int> freq;
 

        while(left <= right && right < n){
            //Total characters - frequency of most common <= k
            int lenWindow = right - left + 1;
            
            if(freq.find(s[right]) != freq.end()) freq[s[right]]++;
            else freq[s[right]] = 1;

            int count = 0;
            for(auto [c, f] : freq)
                count = max(count, f);
            
            if(lenWindow - count <= k) {right++; maxLen = max(maxLen , lenWindow);}
            else {freq[s[left]]--; left++; right++;}
            
        }
        return maxLen;
    }
};
