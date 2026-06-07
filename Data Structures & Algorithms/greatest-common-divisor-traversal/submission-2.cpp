class Solution {
class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false;

        // Union by size
        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
        return true;
    }
};
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int MAX = *max_element(nums.begin(), nums.end());
        if(count(nums.begin(), nums.end(), 1)) return false;

        DSU dsu(n + MAX + 1);

        vector<int> spf(MAX+1);
        for(int i = 2; i<= MAX; i++) spf[i] = i;
        for(int i= 2; i * i <= MAX; i++){
            if(spf[i] == i){
                for(int j = i*i; j<= MAX; j+=i){
                    if(spf[j] == j) spf[j] = i;
                }
            }
        }


        for(int i=0; i<n; i++){
            int val = nums[i];
            while(val > 1){
                int prime = spf[val];
                dsu.unite(i, n+prime);
                while(val%prime == 0)
                    val /= prime;
            }
        }

        int rootId = dsu.find(0);
        for (int i = 1; i < n; i++) {
            if (dsu.find(i) != rootId) {
                return false; 
            }
        }
        return true;
    }
};