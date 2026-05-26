class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //car i will catch car j int time t = ((position[j] - position[[i])/(speed[i] - speed[j]))
        // by that time car j would have travelled to position[j] + speed[j]* t <= target
        // pos[j] < (pos[j]*s[i] - pos[i]*s[j])/ (s[i] - s[j]) <= target
        int n = position.size();
        vector<pair<int,double>> cars(n); //position, time taken to reach the target

        for(int i=0; i<n; i++)
            cars[i] = {position[i], (double)(target - position[i])/speed[i]};
        
        //sort on the basis of position
        sort(cars.begin(), cars.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            return a.first < b.first;
        });

        int fleets = 0; double max_time_so_far = 0;

        for(int i=n-1; i>=0; i--){
            if(cars[i].second > max_time_so_far){
                cout << cars[i].second << " " << max_time_so_far << endl;
                fleets++;
                max_time_so_far = cars[i].second;
            }
        }
        return fleets;
    }
};
