class MyCircularQueue {
public:
    vector<int>arr;
    int end;
    int front;
    int K;
    MyCircularQueue(int k) {
        K=k;
        arr.resize(k);
        front=-1;
        end=-1;
        
    }
    
    bool enQueue(int value) {
        if(isFull())
        return false;
        if(end==-1&&front==-1)
        {
            end=front=0;
            arr[end]=value;
            return true;
        }
        if(end<K-1&&end>=front)
        {
            end++;
            arr[end]=value;
            return true;
        }
        if(end==K-1&&front>0)
        {
            end=0;
            arr[end]=value;
            return true;
        }
        if(end<front)
        {
            end++;
            arr[end]=value;
            return true;
        }
        return false;
    }
    bool deQueue()
    {
        if(front==-1)
        {
            return false;
        }
        if(front==end)
        {
            front=-1;
            end=-1;
            return true;
        }
        

        if(front<end)
        {
            front++;
            return true;
        }
        if(end!=-1&&front<K-1)
        {
            front++;
            return true;
        }
        if(front==K-1&&end!=-1)
        {
            front=0;
            return true;
        }
        return false;        
    }
    
    int Front() {
        if(isEmpty())
        return -1;
        return arr[front];
        
    }
    
    int Rear() {
        if(isEmpty())
        return -1;
        return arr[end];
        
    }
    
    bool isEmpty() {
        if(front==-1&&end==-1)
        return true;
        return false;
    }
    
    bool isFull() {
        return((end+1)%K==front);
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