class Solution {
public:
    bool valid_dict(unordered_map<char,int>& t_string, unordered_map<char,int>& sub_string){
        for(auto& [c,f] : t_string){
            if(sub_string[c] < f) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int slen  = s.length(), tlen = t.length();
        int left = 0, right = 0;
        if(tlen == 0 || tlen > slen) return "";
        unordered_map<char, int> t_string;

        for(int i=0; i < tlen; i++){
            if(t_string.find(t[i]) == t_string.end())
                t_string[t[i]] = 1;
            else
                t_string[t[i]]++;
        }

        unordered_map<char, int> s_string;

        for(int i=0; i < slen; i++){
            if(s_string.find(s[i]) == s_string.end())
                s_string[s[i]] = 1;
            else
                s_string[s[i]]++;
        }

        if(!valid_dict(t_string, s_string)) return "";

        unordered_map<char, int> freq; string ans = s;
        int min_window = slen;
        while(right < slen){

            freq[s[right]]++;

            while(valid_dict(t_string, freq)){
                if(right - left + 1 < min_window){
                    min_window = right - left + 1;
                    ans = s.substr(left, min_window);
                }
                freq[s[left]]--;
                left++;
            }
            
            right++;
        }
        return ans;

    }
};
