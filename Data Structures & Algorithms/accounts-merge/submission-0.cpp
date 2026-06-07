class Solution {
public:
    void dfs(string src, unordered_map<string, vector<string>>& graph, unordered_set<string>& visited, vector<string>& component){
        if(visited.count(src)) return;
        visited.insert(src);
        component.push_back(src);
        for(auto s: graph[src]){
            if(!visited.count(s)) dfs(s, graph, visited, component);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, string> emailToName;
        
        for(const auto& acc : accounts){
            string name = acc[0];
            string firstEmail = acc[1];

            for(int i = 1; i<acc.size(); i++){
                string currEmail = acc[i];
                emailToName[currEmail] = name;
                if (i > 1) {
                    graph[firstEmail].push_back(currEmail);
                    graph[currEmail].push_back(firstEmail);
                }
            }
        }

        unordered_set<string> visited;
        vector<vector<string>> mergedAccounts;
        for (const auto& pair : emailToName) {
            string email = pair.first;
            string name = pair.second;
            if(!visited.count(email)){
                vector<string> account;
                dfs(email, graph, visited, account);
                sort(account.begin() + 1, account.end());
                account.insert(account.begin(), name);
                mergedAccounts.push_back(account);
                
            }
        }
        return mergedAccounts;

    }
};