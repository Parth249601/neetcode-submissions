class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> R, D;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') R.push(i);
            else                  D.push(i);
        }

        while (!R.empty() && !D.empty()) {
            int r = R.front(); R.pop();
            int d = D.front(); D.pop();
            // whoever has the smaller index acts first and bans the other;
            // the survivor goes to the back, re-indexed into the next round (+n)
            if (r < d) R.push(r + n);
            else       D.push(d + n);
        }
        return R.empty() ? "Dire" : "Radiant";
        
    }
};