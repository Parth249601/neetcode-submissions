class TimeMap {
    unordered_map<string, vector<pair<string, int>>> dict;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dict[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> values = dict[key];
        //timestamp has to be greater than first recorded incident of set
        if(values.size() == 0 || values[0].second > timestamp) return "";
        
        //Binary Search on values[i].second
        int start = 0, end = values.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(values[mid].second == timestamp)
                return values[mid].first;
            else if(values[mid].second > timestamp)
                end = mid -1;
            else 
                start = mid + 1;
        }
        return values[end].first;
        
    }
};
