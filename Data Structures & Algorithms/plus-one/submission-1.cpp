class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //reversing so that I can just push the carry back
        reverse(digits.begin(), digits.end());
        int carry = 0; int n = digits.size(); int sum;
        for(int i=0; i<n; i++){
            if(i > 0) sum = digits[i] + carry;
            if(i == 0) sum = digits[i] + 1;
            if(sum >= 10){
                carry = 1;
                digits[i] = sum%10;
            }
            else {digits[i] = sum; carry = 0;}
            if(!carry) break;
        }
        if(carry) digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
