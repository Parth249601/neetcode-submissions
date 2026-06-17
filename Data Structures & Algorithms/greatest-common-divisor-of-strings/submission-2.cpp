class Solution {
public:
    string subtractString(string lhs, const string& rhs) {
        lhs.erase(0, rhs.length());
        return lhs;
    }
    bool same(const string& s1, const string& s2){
        int minLen = min(s1.length(), s2.length());
        for(int i =0; i<minLen; i++)
            if(s1[i] != s2[i]) return false;
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        bool a = str1.length() < str2.length();
        
        if(str1 == "") return str2;
        if(str2 == "") return str1;
        if(same(str1, str2)){
            if(a) return gcdOfStrings(str1, subtractString(str2, str1));
            else return gcdOfStrings(subtractString(str1, str2), str1);
        }
        else return "";
    }
};