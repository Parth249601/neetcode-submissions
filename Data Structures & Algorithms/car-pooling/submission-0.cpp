class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //so we have start locations and ending locations of the passengers 
        //push starting locations in a minHeap and ending locations in a maxHeap one by one
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> end; //to, tr
        int passengers = 0;
        for(int i =0; i < trips.size(); i++){
            int to = trips[i][2] , from = trips[i][1], tr = trips[i][0];
            while(!end.empty() && from >= end.top().first){
                passengers -= end.top().second;
                end.pop();
            }
            if(tr + passengers <= capacity){
                passengers += tr;
            }
            else
                return false;
            end.push({to, tr});
        }
        return true;
    }
};