class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> roman;
        roman["IV"] = 4; roman["IX"] = 9;
        roman["XL"] = 40; roman["XC"] = 90;
        roman["CD"] = 400; roman["CM"] = 900;
        roman["I"] = 1; roman["V"] = 5; roman["X"] = 10; roman["L"] = 50; roman["C"] = 100; roman["D"] = 500; roman["M"] = 1000;

        int num = 0;
        for(int i=0; i< s.length(); i++){
            char c = s[i];
            string t = "";
            if(i < s.length() - 1){
                if(c == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')){
                    t += s[i]; t += s[i+1];
                    num += roman[t];
                    i++;
                }
                else if(c == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')){
                    t += s[i]; t += s[i+1];
                    num += roman[t];
                    i++;
                }
                else if(c == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')){
                    t += s[i]; t += s[i+1];
                    num += roman[t];
                    i++;
                }
                else{
                    t += c;
                    num += roman[t];
                }
            }
            else{
                t += c;
                num += roman[t];
            }
        }
        return num;
    }
};