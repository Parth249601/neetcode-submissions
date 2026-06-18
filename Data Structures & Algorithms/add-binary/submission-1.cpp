class Solution {
public:
    string addBinary(string a, string b) {
        string r1(a.rbegin(), a.rend());
        string r2(b.rbegin(), b.rend());
        string ans = "";
        if(r2.length() > r1.length()) swap(r1,r2);
        int carry = 0;
        for(int i=0; i<r2.length();i++){
            int n1 = r1[i] - '0';
            int n2 = r2[i] - '0';
            int sum = n1 + n2 + carry;
            if(sum > 1){
                char c = (sum-2) + '0';
                carry = 1;
                ans += c;
            }
            else{
                ans += (sum + '0');
                carry = 0;
            }
        }
        for(int i = r2.length(); i< r1.length(); i++){
            int n1 = r1[i] - '0';
            int sum = n1 + carry;
            if(sum > 1){
                char c = (sum-2) + '0';
                carry = 1;
                ans += c;
            }
            else{
                ans += (sum + '0');
                carry = 0;
            }
        }
        if(carry == 1) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};