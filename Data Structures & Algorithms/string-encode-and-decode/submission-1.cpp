class Solution {
    const string stop_sign = ",,,,//";
    bool check_stop_sign(string& query, int start){
        int n = query.length();
        if(start + stop_sign.length() -1 >= n) return false;
        for(int i=start; i<start + stop_sign.length() && i < query.length(); i++)
            if(query[i] != stop_sign[i-start]) return false;
        return true;
    }
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(int i = 0; i < strs.size(); i++){
            s += strs[i];
            s += stop_sign;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string currStr = "";
        for(int i=0; i < s.length(); i++){
            if(s[i] == ',' && check_stop_sign(s, i)){
                ans.push_back(currStr);
                currStr = "";
                i += stop_sign.length()-1;
            }
            else
                currStr += s[i];
        }
        return ans;
    }
};
