class MyHashMap {

const int MAX_SIZE = 10000;
const double A = 0.6180339887;
vector<vector<int>> arr;
int int_hasher(int key){
    //I will make the function to be [m* {KA}]
    double fractional_part = (key * A - floor(key*A));
    return floor(MAX_SIZE* fractional_part);
}

public:
    MyHashMap() {
        arr.resize(MAX_SIZE, vector<int>(2, -1));
    }
    
    void put(int key, int value) {
        int index = int_hasher(key);
        if(arr[index][0] == -1) arr[index] = {key, value};
        else if(arr[index][0] == key) arr[index][1] = value;
        else{
            for(int i= index + 1; i<MAX_SIZE; i++){
                if(arr[i][0] == -1){arr[i] = {key, value}; return;}
            }  
        }
    }
    
    int get(int key) {
        int index = int_hasher(key);
        if(arr[index][0] == key) return arr[index][1];
        else{
            for(int i= index + 1; i<MAX_SIZE; i++)
                if(arr[i][0] == key) return arr[i][1];
        }
        return -1;
    }
    
    void remove(int key) {
        int index = int_hasher(key);
        if(arr[index][0] == key) arr[index] = {-1,-1};
        else{
            for(int i= index + 1; i<MAX_SIZE; i++){
                if(arr[i][0] == key){
                    arr[i] = {-1,-1}; 
                    return;
                }
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */