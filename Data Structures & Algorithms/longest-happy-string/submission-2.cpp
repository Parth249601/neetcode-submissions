class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a) pq.push({a, 'a'}); 
        if(b) pq.push({b, 'b'}); 
        if(c) pq.push({c, 'c'});

        string s;
        int tick = 1; 
        queue<pair<pair<int, char>, int>> qt;
        while(!pq.empty()){
            auto [f1, c1] = pq.top(); pq.pop();
            int n = s.length();
            if(n >= 2 && s[n-1] == c1 && s[n-2] == c1){
                // can't place c1 now; try the next best
                if(pq.empty()) break;
                auto [f2, c2] = pq.top(); pq.pop();
                s += c2;
                if(f2 - 1 > 0) pq.push({f2 - 1, c2});
                pq.push({f1, c1});   // put c1 back
            }
            else{
                s += c1;
                if(f1 - 1 > 0) pq.push({f1 - 1, c1});
            }
        }
        return s;
    }
};