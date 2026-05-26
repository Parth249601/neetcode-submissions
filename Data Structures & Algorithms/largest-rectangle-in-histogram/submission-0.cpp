class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st; int maxArea = INT_MIN;

        for(int i= 0; i < heights.size(); i++){
            int ele = heights[i];
            int start = i;
            if(st.empty()){
                st.push({i,ele}); continue;
            }

            if(ele >= st.top().second){
                st.push({i,ele}); continue;
            }

            else{
                while(!st.empty() && st.top().second >= ele){
                    int index = st.top().first;
                    int height = st.top().second;
                    int width = i - index;
                    st.pop();
                    maxArea = max(maxArea, height * width);
                    start = index;
                }
                st.push({start,ele});
            }
        }
        int n = heights.size();
        while(!st.empty()){ 
            int index = st.top().first;
            int height = st.top().second;
            int width = n - index;
            maxArea = max(maxArea, width * height);
            st.pop();
        }
        return maxArea;
    }
};