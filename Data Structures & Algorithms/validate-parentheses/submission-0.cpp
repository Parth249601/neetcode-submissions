class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        int it = 0;
        while(it < s.length()){

            if(st.empty()){
                if(s[it] == '}' || s[it] == ')' || s[it] == ']')
                    return false;
                else{
                    st.push(s[it]);
                    it++;
                }
            }

            bool isClosed = (s[it] == '}' || s[it] == ')' || s[it] == ']');
            if(!isClosed) {st.push(s[it]); it++;}
            else{
                if(s[it] == '}' and st.top() != '{') return false;
                else if(s[it] == ')' and st.top() != '(') return false;
                else if(s[it] == ']' and st.top() != '[') return false;
                else {st.pop(); it++;}
            }

        }
        return st.empty() ? true : false;
    }
};
