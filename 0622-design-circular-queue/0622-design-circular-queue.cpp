class MyCircularQueue {
    int size;
    int count;
    int idx;
    int front_idx;
    vector<int> myQueue;
public:
    MyCircularQueue(int k) {
        size = k;
        count = 0;
        idx = -1;
        front_idx = 0;
        myQueue.reserve(k);
    }

    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        ++idx; ++count;
        if(idx >= size) idx = 0;
        myQueue[idx] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        ++front_idx; --count;
        if(front_idx >= size) front_idx = 0;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : myQueue[front_idx];
    }
    
    int Rear() {
        return isEmpty() ? -1 : myQueue[idx];
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