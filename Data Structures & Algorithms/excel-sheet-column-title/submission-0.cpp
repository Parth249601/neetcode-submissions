class Solution {
public:
    string convertToTitle(int columnNumber) {
        //determine power
        long long num = (long long)columnNumber; string ans;
        if(num <= 0) return "";
        unordered_map<int, char> excel;
        for(int i = 1; i<=26; i++){
            excel[i] = (i-1) + 'A';
        }
        int power = floor((double)(log(25*num + 1)/log(26))- 1);
        int coeff = 1; // coeff <= 26
        while(coeff * pow(26, power) <= num)
            coeff++;
        ans += excel[coeff-1];
        ans += convertToTitle(num - ((coeff-1) * pow(26, power)));
        return ans;
    }
};