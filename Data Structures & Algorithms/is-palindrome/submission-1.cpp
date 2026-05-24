class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        int diff = 'A' - 'a';
        while(left <= right){
            if(s[left] == ' ' || s[right] == ' '){
                if(s[left] == ' ') left++;
                if(s[right] == ' ') right--;
                continue;
            }

            if(s[left] < 48 || (s[left] > 57 && s[left] < 65) || s[left] > 122 || (s[left] > 90 && s[left] < 97)){
                left++; continue;
            }
            if(s[right] < 48 || (s[right] > 57 && s[right] < 65) || s[right] > 122 || (s[right] > 90 && s[right] < 97)){
                right--;
                continue;
            }
                
            if(s[left] != s[right]){
                if(s[left] + diff == s[right] && s[left] > 57 && s[right] > 57){left++; right--;continue;}
                else if(s[left] - diff == s[right] && s[left] > 57 && s[right] > 57){left++; right--;continue;}
                else{ 
                    cout << "Left character = " << s[left] << " Right character = " << s[right] << endl;
                    return false;
                }
            }
            left++; right--;
        }
        return true;
    }
};
