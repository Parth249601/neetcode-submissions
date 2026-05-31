class Solution {
public:
    string reorganizeString(string s) {
        //it is the same problem 
        unordered_map<char, int> mp;
        for(char c: s)
            mp[c]++;
        priority_queue<pair<int, char>> pq;
        for(auto [c, f] : mp)
            pq.push({f,c});
        string ans;

        while(!pq.empty()){
            auto [f1, c1] = pq.top(); pq.pop();
            cout << "Character " << c1 << " freq " << f1 << endl;
            int n = ans.length();
            if(n >= 1 && ans[n-1] == c1){
                if(pq.empty()) 
                    return "";

                auto [f2, c2] = pq.top(); pq.pop();
                ans += c2;
                if(f2 > 1) pq.push({f2-1,c2});
                pq.push({f1,c1});
            }
            else{
                ans += c1;
                if(f1 > 1) pq.push({f1-1, c1});
            }
        }
        return ans;
    }   
};