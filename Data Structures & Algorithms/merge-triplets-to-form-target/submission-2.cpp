class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int size = triplets.size();
        unordered_map<int, bool> invalid;
        for(int j = 0; j<3; j++){
            for(int i=0; i <size; i++){
                if(!invalid[i]){
                    if(triplets[i][j] > target[j]) invalid[i] = true;
                }
            }
        }
        for(int j = 0; j<3; j++){
            bool found = false;
            for(int i =0; i< size; i++){
                if(!invalid[i] && triplets[i][j] == target[j]) found = true;
            }
            if(!found) return false;
        }
        return true;
    }
};
