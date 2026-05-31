class Solution {
    struct Compare{
        bool operator()(pair<int, pair<int,int>>& a, pair<int, pair<int,int>>& b){
            return a.second.first > b.second.first;
        }
    };
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        //at a particular time there are a set of tasks that can pe processed, order them 
        //by min processing time (minHeap),
        //The locked group contains elements ordered by min Enqueue time
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> unlocked;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>> ,Compare> locked;

        int time = 1;
        for(int i=0; i< tasks.size(); i++){
            if(tasks[i][0] <= time) unlocked.push({tasks[i][1], {tasks[i][0], i}});
            else locked.push({tasks[i][1], {tasks[i][0], i}});;
        }
        vector<int> ans;
        while(ans.size() != tasks.size()){
            while(!locked.empty() && locked.top().second.first <= time){
                unlocked.push(locked.top()); locked.pop();
            }
            if(!unlocked.empty()){
                auto [pt, p] = unlocked.top(); unlocked.pop();
                int enqueue_time = p.first, index = p.second;
                ans.push_back(index);
                time += pt;
                continue;
            } 
            time++;
        }
        return ans;

    }
};