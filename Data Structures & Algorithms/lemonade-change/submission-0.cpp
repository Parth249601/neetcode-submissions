class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> freq;
        int totalCash = 0; freq[0] = bills.size();
        for(int i=0; i< bills.size(); i++){
            if(totalCash == 0){
                if(bills[i] != 5) return false;
                else {freq[5] = 1; totalCash = 5;}
            }

            else{
                //offer is bills[i], do I have something like bills[i]- 5?
                int change = bills[i] - 5;
                if(freq.find(change) == freq.end()){
                    if(change == 15){
                        if(!freq[5] || (!freq[10] && freq[5] < 3)) return false;
                        if(freq[10]){
                            freq[10]--; freq[5]--; totalCash += 5; freq[20]++;
                        }
                        else{
                            freq[5] -= 3; totalCash+=5; freq[20]++; 
                        }
                    }
                    if(change == 10){
                        if(freq[5] < 2) return false;
                        else {freq[5] -= 2; totalCash += 5; freq[10]++;}
                    }
                }
                else{
                    freq[bills[i]]++;
                    totalCash += 5;
                    freq[change]--;
                }
            }
        }      
        return true;
    }
};