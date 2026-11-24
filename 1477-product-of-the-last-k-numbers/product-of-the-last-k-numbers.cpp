class ProductOfNumbers {
public:
    vector<int>vec;
    ProductOfNumbers() {
        vec.clear();
        return;
        
    }
    
    void add(int num){
        vec.push_back(num);
        return;
    }
    
    int getProduct(int k)
    {
        int n=vec.size();
        int ans=1;
        for(int i=0;i<k;i++)
        {
            ans*=vec[n-i-1];
        }
        return ans;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */