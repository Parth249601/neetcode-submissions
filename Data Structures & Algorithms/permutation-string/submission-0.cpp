class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        if(l2 < l1) return false;

        //need a sliding window of size l1
        int left =0, right = l1 - 1;

        unordered_map<char, int> s1_map;
        
        for(int i = left; i <= right; i++){
            if(s1_map.find(s1[i]) != s1_map.end()) s1_map[s1[i]]++;
            else s1_map[s1[i]] = 1;
        }

        while(right < l2){
            unordered_map<char, int> freq;
            
            for(int i = left; i <= right; i++){
                if(freq.find(s2[i]) != freq.end()) freq[s2[i]]++;
                else freq[s2[i]] = 1;
            }

            if(freq == s1_map) return true;

            freq[left]--; freq[right]--;
            left++; right++; 
        }

        return false;
    }
};
