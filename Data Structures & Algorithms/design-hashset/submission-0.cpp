#include<vector>

class MyHashSet {

const int MAX_SIZE = 10000;
const double A = 0.6180339887;

vector<int> arr;

int hash_function(int key){
    //I will make the function to be [m* {KA}]
    double fractional_part = (key * A - floor(key*A));
    return floor(MAX_SIZE* fractional_part);
}
public:
    MyHashSet() {
        arr.resize(MAX_SIZE, -1);
    }
    
    void add(int key) {

        if(contains(key)) return;
        int index = hash_function(key);
        if(arr[index] == -1){arr[index] = key; return;}
        else{
            for(int i= index+1; i<MAX_SIZE; i++){
                if(arr[i] != - 1){arr[i] = key; return;}
            }
        }
    }
    
    void remove(int key) {

        if(!contains(key)) return;
        int predicted_index = hash_function(key);
        if(arr[predicted_index] == key) arr[predicted_index] = -1;
        else{
            for(int i= predicted_index+1; i< MAX_SIZE; i++){
                if(arr[i] == key){arr[i] = -1; return;}
            }
        }

    }
    
    bool contains(int key) {
        
        int predicted_index = hash_function(key);
        if(arr[predicted_index] == key) return true;
        else{
            for(int i= predicted_index+1; i< MAX_SIZE; i++)
                if(arr[i] == key) return true;
            return false;
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */