class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int c=1;
        while(!s.empty() and s.top()<=price)
        {
            c+=ans[s.top()];
            s.pop();
        }
        s.push(price);
        ans[price]=c;
        return c;
    }
    
    stack<int> s;
    unordered_map<int, int> ans;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */