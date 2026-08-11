class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        if(l2 < l1) return false;

        //need a sliding window of size l1
        int left =0, right = l1 - 1;
        unordered_map<char, int> freq, s1_map;
        for(int i = left; i <=right; i++) freq[s2[i]]++;
        for(int i =0; i < l1; i++) s1_map[s1[i]]++;
        while(right < l2){
            if(s1_map == freq) return true;

            freq[s2[left]]--;
            if (freq[s2[left]] == 0) {
                freq.erase(s2[left]);
            }
            
            left++; right++; 

            if(right < l2) freq[s2[right]]++;
        }

        return false;
    }
};
