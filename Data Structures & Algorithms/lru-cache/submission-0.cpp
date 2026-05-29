class LRUCache {

    struct Node {int val, key; Node* prev; Node* next;};
    unordered_map<int, Node*> mp;
    Node* head = new Node(); Node* tail = new Node();
    //Need to make helper functions 
    //Insert at head
    void insertFront(Node* n){
        n->next = head->next; n->prev = head;
        head->next->prev = n; head->next= n;
    }
    void remove(Node* n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }
    int size = 0, maxSize = 0;

public:
    LRUCache(int capacity) {
        maxSize = capacity;
        head->key = -1; head->val = -1; head->prev = NULL; head->next = tail;
        tail->prev = head; tail->next = NULL; tail->val = -1; tail->key = -1;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            int value = mp[key]->val;
            remove(mp[key]); insertFront(mp[key]);
            return value;
        }   
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            mp[key]->val = value;
            remove(mp[key]); insertFront(mp[key]);
            return;
        }
        if(size >= maxSize) {
           mp.erase(tail->prev->key);
           remove(tail->prev);
           size--;
        }

        mp[key] = new Node();
        mp[key]->val = value;
        mp[key]->key = key;
        insertFront(mp[key]);
        size++;
    }
};
