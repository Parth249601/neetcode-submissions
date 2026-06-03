class Solution {
public:
    bool isValid(string& s){
        if(s.length() == 0) return true;
        stack<char> st; st.push(s[0]);

        for(int i= 1; i< s.length(); i++){
            if(st.empty() && s[i] == ')') return false;
            if(s[i] == '(') st.push(s[i]);
            if(s[i] == ')' && st.top() == '(') {st.pop(); continue;}
        }
        return st.empty();
    }
    void backtrack(string& state, vector<string>& out, const int& n){
        int len = state.length();
        if(len == 2*n){
            bool crt = isValid(state);
            if(crt) out.push_back(state);
            return;
        }
        //There are two legal choices that I append '(' ot I append ')' character
        
        state.push_back('(');
        backtrack(state, out, n);
        state.pop_back();

        state.push_back(')');
        backtrack(state, out, n);
        state.pop_back();
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        string state;
        backtrack(state, out, n);
        return out;
    }
};
