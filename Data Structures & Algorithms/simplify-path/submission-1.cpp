class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length(); stack<string> st;
        stringstream ss(path);
        string token;
        while(getline(ss, token,'/')){
            if(token == "." || token == "")continue;
            if (token == ".."){
                if(!st.empty()) st.pop();
            }
            else st.push(token);

        }
        
        cout << st.size() << endl;


        string s;
        stack<string> rev;
        while(!st.empty()){
            rev.push(st.top());
            st.pop();
        }

        while(!rev.empty()){
            s += '/'; s += rev.top();
            rev.pop();
        }
        if(s == "") return "/";
        return s;
    }
};