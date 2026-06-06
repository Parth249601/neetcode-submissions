class Solution {
public:
    bool compare(string& s1, string& s2, unordered_map<char, int>& mp){
        bool a = s1.length() <= s2.length();
        int minLen = min(s1.length(), s2.length());
        for(int i=0; i< minLen; i++){
            char c1 = s1[i];
            char c2 = s2[i];
            if(mp[c1] < mp[c2]) return true;
            else if (mp[c1] > mp[c2]) return false;
            else continue;
        }

        //If the function is till here it means all the characters matched 
        return a;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        if(words.size() == 1) return true;
        for(int i=0; i< order.length(); i++)
            mp[order[i]] = i+1;
        
        for(int i =0; i < words.size() - 1; i++){
            if(!compare(words[i], words[i+1], mp)) return false;
        }
        return true;
    }
};