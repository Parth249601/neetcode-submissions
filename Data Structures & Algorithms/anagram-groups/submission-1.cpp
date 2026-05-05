class Solution {
public:
    bool isAnagram(string& s, string& t){
        int a = s.length();
        int b = t.length();
        if(a != b)
            return false;
        if(a == 0 && b == 0)
            return true;
        unordered_map<char, int> s_chars;
        unordered_map<char, int> t_chars;

        for(int i = 0; i <a; i++){
            if(s_chars.find(s[i]) != s_chars.end())
                s_chars[s[i]]++;
            else
                s_chars[s[i]] = 0;
        }

        for(int i =0; i < b; i++){
            if(t_chars.find(t[i]) != t_chars.end())
                t_chars[t[i]]++;
            else
                t_chars[t[i]] = 0;
        }

        return s_chars == t_chars;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //create a function to check whether two strings are anagram or not
        vector<vector<string>> ans;
        unordered_map<string, bool> lookup_table;
        for(int i = 0; i <strs.size(); i++){
            if(lookup_table.find(strs[i]) == lookup_table.end()){
                    ans.push_back({strs[i]});
                for(int j = i+1; j < strs.size(); j++){
                    bool ij_check = isAnagram(strs[i], strs[j]);
                    if(ij_check){
                        lookup_table[strs[j]] = true;
                        ans[ans.size()- 1].push_back(strs[j]);
                    }
                }
            }
        }
        return ans;
    }
};
