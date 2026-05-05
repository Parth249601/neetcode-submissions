class Solution {
public:
    bool isAnagram(string s, string t) {
        //right of the bat i think that we should unique characters of s in 
        //a hash set and then loop through t
        int a = s.length();
        int b = t.length();
        unordered_map<char, int> unique_chars;
        unordered_map<char,int> j_chars;
        for(int i=0;i < a; i++){
            if(unique_chars.find(s[i]) != unique_chars.end())
                unique_chars[s[i]]++;
            else
                unique_chars[s[i]] = 0;
        }
        for(int i=0; i < b; i++){
             if(j_chars.find(t[i]) != j_chars.end())
                j_chars[t[i]]++;
            else
                j_chars[t[i]] = 0;
        }

        return unique_chars == j_chars;
    }
};
