class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int maxLen = max(word1.length(), word2.length());
        int minLen = min(word1.length(), word2.length());
        bool word1_is_smaller = (word1.length() < word2.length());
        string s = "";
        for(int i=0; i<maxLen; i++){
            if(i >= minLen && word1_is_smaller) s += word2[i];
            else if(i >= minLen) s+= word1[i];
            else{
                s += word1[i]; s += word2[i];
            }
        }
        return s;
    }
};