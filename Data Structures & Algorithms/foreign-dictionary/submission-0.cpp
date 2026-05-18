class Solution {
public:
    void lexkahn(unordered_map<char, vector<char>>& dag, vector<char>& order){
        //calculate indeg of each of the character
        unordered_map<char, int> indeg;
        for(auto& [node, dependencies] : dag){
            indeg[node] = 0;
        }
        for(auto& [node, dependencies] : dag){
            for(auto& vertex: dependencies)
                indeg[vertex]++;
        }

        priority_queue<char, vector<char>, greater<char>> minHeap;
        for(auto& [key, value] : indeg){
            if(value == 0) minHeap.push(key);
        }

        while(!minHeap.empty()){
            char top = minHeap.top(); minHeap.pop();
            order.push_back(top);
            for(auto v : dag[top])
                if(--indeg[v] == 0) minHeap.push(v);
        }
    }
    void build_dag(string& word1, string& word2, unordered_map<char, vector<char>>& dag, bool& isPossible){
        if(word1 == word2) return;
        int minlen = min(word1.length(), word2.length());
        for(int i=0; i<minlen; i++){
            if(word1[i] == word2[i]) continue;
            else{
                dag[word1[i]].push_back(word2[i]);
                return;
            }
        }
        if(word1.length() > word2.length()) isPossible = false;
    }
    string foreignDictionary(vector<string>& words) {
      ///element with the minimum priority stays at the top and we keep popping from the pq;

       //we should create a unique set of vertices that are individual characters in strings
       unordered_map<char,int> characters;
       for(int i=0; i < words.size(); i++){
            for(int j=0; j<words[i].length(); j++){
                char c = words[i][j];
                if(characters.find(c) == characters.end()) characters[c] = 1;
            }
       }
        vector<char> vertices;
       for(auto& [key,value] : characters)
            vertices.push_back(key);
        //make a DAG now
        unordered_map<char, vector<char>> dag;
        for(int i=0; i<vertices.size(); i++)
            dag[vertices[i]] = {};      
        bool isPossible = true;
        for(int i=0; i< words.size()-1; i++){
            build_dag(words[i], words[i+1], dag, isPossible);
            if(!isPossible) return "";
        }
        

        vector<char> order;
        lexkahn(dag, order);
        if(order.size() != vertices.size()) return "";
        string ans;
        for(int i=0; i < order.size(); i++)
            ans+= order[i];
        return ans;
    }
};
