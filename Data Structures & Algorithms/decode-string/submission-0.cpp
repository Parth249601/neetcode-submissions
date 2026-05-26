class Solution {
public:
    // Notice the reference '&' on the integer 'i'
    string helper(const string& s, int& i) {
        string res = "";
        
        // Keep going until we hit the end of the string OR a closing bracket
        while (i < s.length() && s[i] != ']') {
            
            // CASE 1: It's a letter -> just add it to our result
            if (isalpha(s[i])) {
                res += s[i];
                i++;
            } 
            // CASE 2: It's a number -> time to decode a nested string
            else if (isdigit(s[i])) {
                int num = 0;
                // Parse the full number (could be multiple digits like "100")
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                
                i++; // Skip the '[' character
                
                // RECURSION: Get the decoded string inside the brackets
                string decodedString = helper(s, i); 
                
                i++; // Skip the ']' character
                
                // Append the decoded string 'num' times
                while (num > 0) {
                    res += decodedString;
                    num--;
                }
            }
        }
        
        return res; 
    }

    string decodeString(string s) {
        int i = 0;
        return helper(s, i);
    }
};