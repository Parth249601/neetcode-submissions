class Solution {
public:

    bool check(string& s, int left, int right){
        while(left <= right){
            if(s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left =0, right = s.length() -1;
        if(check(s, left, right)) return true;

        int count = 0;

        while(left <= right){
            if(s[left] != s[right] && count < 1){
                count++;
                if(check(s, left +1, right)){left++; continue;}
                if(check(s, left, right -1)){right--; continue;}
                return false;
            }
            left++; right--;
        }
        return true;
    }
};