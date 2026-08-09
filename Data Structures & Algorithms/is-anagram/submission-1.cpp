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
            unique_chars[s[i]]++;
        }
        for(int i=0; i < b; i++){
            j_chars[t[i]]++;
        }

        return unique_chars == j_chars;
    }
};
