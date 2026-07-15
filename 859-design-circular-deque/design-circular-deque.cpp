class MyCircularDeque {
public:
    vector<int>arr;
    int front;
    int K;
    int end;
    MyCircularDeque(int k)
    {
        arr.resize(k);
        front=-1;
        end=-1;
        K=k;
    }
    
    bool insertFront(int value)
    {
        if(isEmpty())
        {
            front=end=0;
            arr[front]=value;
            return true;
        }
        if(isFull())
        {
            return false;
        }
        front--;
        if(front<0)
        front=K-1;
        arr[front]=value;
        return true;

    }
    
    bool insertLast(int value)
    {
        if(isEmpty())
        {
            front=end=0;
            arr[front]=value;
            return true;
        }
        if(isFull())
        {
            return false;
        }
        end++;
        if(end==K)
        end=0;
        arr[end]=value;
        return true;
        
    }
    
    bool deleteFront()
    {
        if(isEmpty())
        return false;
        if(front==end)
        {
            front=-1;
            end=-1;
            return true;
        }
        front++;
        if(front==K)
        front=0;
        return true;
        
    }
    
    bool deleteLast() {
        if(isEmpty())
        return false;
        if(front==end)
        {
            front=-1;
            end=-1;
            return true;
        }
        
        end--;
        if(end<0)
        end=K-1;
        return true;
        
    }
    
    int getFront() {
        if(isEmpty())
        return -1;
        return arr[front];
        
    }
    
    int getRear() {
        if(isEmpty())
        return -1;
        return arr[end];
        
    }
    
    bool isEmpty()
    {
        return (front==-1);
    }
    
    bool isFull()
    {
        return ((end+1)%K)==front;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */