class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int it = 0; stack<int> st;

        while(it < tokens.size()){
            if(tokens[it] == "+" || tokens[it] == "-" || tokens[it] == "*" || tokens[it] == "/"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                int result;
                if(tokens[it] == "+") result = first + second;
                else if(tokens[it] == "-") result = first - second;
                else if(tokens[it] == "*") result = first * second;
                else result = first/second;
                cout << result << endl;
                st.push(result);
            }
            else {cout << stoi(tokens[it]) << endl; st.push(stoi(tokens[it]));}
            it++;
        }

        return st.top();
    }
};
