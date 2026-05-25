class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans; stack<int> st;
        for(int i=0; i < asteroids.size(); i++){
            if(st.empty()){st.push(asteroids[i]); continue;}
        
            int top = st.top();
            int curr = asteroids[i];
            bool push_current = true;
            while(!st.empty() && curr < 0 && st.top() > 0){
                if(st.top() < -1 * curr) st.pop();
                else if(st.top() == -1* curr){st.pop(); push_current = false; break; }
                else{push_current = false; break;}
            }
            if(push_current) st.push(curr);
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};