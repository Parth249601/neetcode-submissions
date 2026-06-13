class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        int numGroups = n/groupSize;
        sort(hand.begin(), hand.end());
        vector<vector<int>> groups(numGroups);
        vector<unordered_set<int>> seen(numGroups);
        for(int i=0; i<n; i++){
            for(int j =0; j < numGroups; j++){
                if(!seen[j].count(hand[i]) && groups[j].size() < groupSize){
                    groups[j].push_back(hand[i]);
                    seen[j].insert(hand[i]);
                    break;
                }
            }
        }
        for(int i =0; i < numGroups; i++){
            if(groups[i].size() != groupSize) return false;
            for(int j =0; j < groupSize-1; j++)
                if(groups[i][j+1] - groups[i][j] != 1) return false;
        }
        return true;
    }
};
