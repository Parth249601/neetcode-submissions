class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.size() == 0) return 0;
        unordered_map<char, int> mp;
        for(int i=0; i< tasks.size(); i++)
            mp[tasks[i]]++;
        priority_queue<pair<int, char>> pq;
        for(auto [c,f] : mp){
            pq.push({f,c});
        }

        int tick = 1;
        queue<pair<pair<int, char>, int>> qt;
        while(!pq.empty() || !qt.empty()){
            if(!qt.empty() && qt.front().second == tick){
                auto [qu, t] = qt.front(); qt.pop();
                pq.push(qu);
            }
            if(!pq.empty()) {
                auto [f, c] = pq.top(); pq.pop();
                if(f > 1) qt.push({{f-1,c}, tick + n + 1});
            }
            tick++;
        }
        return tick - 1;

    }
};
