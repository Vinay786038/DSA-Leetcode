class LRUCache {
public:
    class node
    {
        public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int k,int value)
        {
            val=value;
            key=k;
            prev=NULL;
            next=NULL;
        }
    };
    int capacity;
    unordered_map<int,node*>mp;
    node* head;
    node* tail;

    LRUCache(int capacity)
    {
        this->capacity=capacity;
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void addNode(node* temp)
    {
        temp->next=head->next;
        temp->prev=head;
        head->next->prev=temp;
        head->next=temp;
    }
    void deleteNode(node* temp)
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }

    
    int get(int key)
    {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        node* temp=mp[key];
        deleteNode(temp);
        addNode(temp);
        return temp->val;
    }
    
    void put(int key, int value)
    {
        if(mp.find(key)!=mp.end())
        {
            node* temp=mp[key];
            temp->val=value;
            deleteNode(temp);
            addNode(temp);
            return;
        }
        node *temp=new node(key,value);
        mp[key]=temp;
        addNode(temp);
        if(mp.size()>capacity)
        {
            node* lru=tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */