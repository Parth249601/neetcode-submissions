class Solution {
    //second is captial
    struct Compare {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
            return a.second > b.second;  // min-heap (smallest on top)
        }
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>, Compare> locked;
    priority_queue<pair<int,int>> unlocked;
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        for(int i=0; i<profits.size(); i++){
            if(capital[i] > w) locked.push({profits[i], capital[i]});
            else unlocked.push({profits[i], capital[i]});
        }

        while(!unlocked.empty() && k--){
            auto [p,c] = unlocked.top(); unlocked.pop();
            w += p;
            while(!locked.empty() && locked.top().second <= w){
                unlocked.push(locked.top());
                locked.pop();
            }
        }
        return w;


    }
};