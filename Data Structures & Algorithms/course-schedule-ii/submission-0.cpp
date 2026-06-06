class Solution {
public:
    vector<int> kahn(vector<vector<int>>& adjList){
        int n = adjList.size();
        //Construct indegree vector
        vector<int> indeg(n, 0);
        for(int i=0; i<n; i++){
            for(int v : adjList[i])
                indeg[v]++;
        }
        queue<int> qt;
        vector<int> order;
        for(int i=0; i<n; i++){
            if(indeg[i] == 0) qt.push(i);
        }

        while(!qt.empty()){
            int top = qt.front(); qt.pop();
            order.push_back(top);
            for(int v: adjList[top]){
                indeg[v]--;
                if(indeg[v] == 0) qt.push(v);
            }
        }
        if(order.size() != n) return {};
        else return order;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(int i = 0; i< prerequisites.size(); i++)
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        return kahn(adjList);
    }
};
