class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int start = 0, end = people.size()-1;

        int boats = 0;

        while(start <= end){
            if(people[end] == limit || people[end] + people[start] > limit){end--; boats++; continue;}
            start++; end--; boats++;
        }
        return boats;
    }
};