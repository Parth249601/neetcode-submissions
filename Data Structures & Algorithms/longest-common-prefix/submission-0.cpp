class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        int n = strs.size();
        int minLen = INT_MAX;
        for(int i =0; i <n; i++){
            int currlen = strs[i].length();
            minLen = min(minLen, currlen);
        }
        
        for(int j=0;j <minLen; j++){
            bool isSame = true;
            for(int i=0; i<n-1; i++){
                if(strs[i][j] != strs[i+1][j]) isSame = false;
            }
            //cout << strs[0][j] << endl;
            if(isSame) s+= strs[0][j];
            else break;
        }
        return s;
        
    }
};