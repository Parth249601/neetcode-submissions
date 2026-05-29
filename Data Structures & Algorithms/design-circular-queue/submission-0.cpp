class MyCircularQueue {
    vector<int> qt;
    int front = 0, back = 0,size = 0, tot = 0;
public:
    MyCircularQueue(int k) {
        qt.resize(k, -1);
        tot = k;
    }
    
    bool enQueue(int value) {
        if(size == tot) return false;
        qt[(back%tot)] = value; 
        back++, size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0) return false;
        qt[(front%tot)] = -1; 
        front++; size--;
        return true;
    }
    
    int Front() {
        if(size != 0) return qt[front%tot];
        else return -1;
    }
    
    int Rear() {
        if(size != 0) return qt[(back-1)%tot];
        else return -1;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == tot;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */