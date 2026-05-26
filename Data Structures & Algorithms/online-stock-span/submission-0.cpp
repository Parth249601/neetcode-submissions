class StockSpanner {
    stack<pair<int,int>> st;
    vector<int> prices;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans;

        while(!st.empty() && st.top().second <= price){
            //cout << "Top price " << st.top().second << " Price of today" << price << endl; 
            st.pop();
        }
        prices.push_back(price);

        if(st.empty()){
            ans = prices.size();
            // cout << "1 "<< prices.size() << endl;
        }
        else{ 
            ans = prices.size()- 1 - st.top().first;
            // cout << "2 " << prices.size() << " " <<st.top().first << endl;
        }

        st.push({prices.size() - 1, price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */