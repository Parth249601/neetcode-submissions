class Solution {
public:
    bool dfs(int s, vector<vector<int>>& adjList, vector<int>& color){
        color[s] = 1;
        for(int v : adjList[s]){
            if(color[v] == 1) return true;
            if(color[v] == 0){ 
                if(dfs(v, adjList, color)) return true;
            }
        }
        color[s] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(int i=0; i < prerequisites.size(); i++)
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        vector<int> color(numCourses, 0);
        //just detect if there is a cycle in this graph
        for(int i = 0; i < numCourses; i++) {
            // Only start a DFS if the node hasn't been visited yet
            if(color[i] == 0) {
                if(dfs(i, adjList, color)) return false; 
            }
        }

        return true;
    }
};
