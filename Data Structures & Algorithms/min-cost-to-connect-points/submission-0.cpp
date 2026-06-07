class Solution {
struct DSU{
    vector<int> p, r;

    DSU(int n){
        p.resize(n); r.resize(n, 1); 
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
    bool unite(int a, int b){
        int rootA= find(a);
        int rootB= find(b);

        if(rootA == rootB) return false;

        if(r[rootA] > r[rootB]){
            p[rootB] = rootA;
            r[rootA] += r[rootB];
        }
        else{
            p[rootA] = rootB;
            r[rootB] += r[rootA];
        }
        return true;
    }

};
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<tuple<int,int,int>> E;
        int n = points.size();
        for(int i=0; i<n; i++){
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i+1; j<n; j++){
                int x2 = points[j][0], y2 = points[j][1];
                int w = abs(x2-x1) + abs(y2-y1);
                E.push_back({w,i,j});
            }
        }
        
        sort(E.begin(), E.end());
        DSU dsu(n);
        int w = 0; int picked = 0;
        for(auto [c, u, v] : E){
            if(dsu.unite(u,v)){
                w += c;
                if(++picked == n-1) break;
            }
        }
        return w;

    }
};
