class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, bool> visited;
        queue<string> qt;

        for(int i=0; i<deadends.size(); i++)
            visited[deadends[i]] = true;
        
        if(!visited["0000"]) {qt.push("0000"); visited["0000"] = true;}
        int depth = 0;
        while(!qt.empty()){
            //two possible directions for each lock turn that shi up or down
            int size = qt.size();
            while(size--){
                string top = qt.front(); qt.pop();
                if(top == target) return depth;
                for(int k=0; k<4;k++){
                    char og = top[k];
                    top[k] = (og == '9') ? '0' : og + 1;
                    if(!visited[top]) {qt.push(top); visited[top] = true;}
                    top[k] = og;
                    top[k] = (og == '0') ? '9' : og - 1;
                    if(!visited[top]) {qt.push(top); visited[top] = true;}
                    top[k] = og;
                }
            }
            depth++;
        }
        return -1;
    }
};