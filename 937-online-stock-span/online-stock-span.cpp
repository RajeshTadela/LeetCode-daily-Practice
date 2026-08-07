class StockSpanner {
public:
    stack<int> prices;
    stack<int>spans;
    StockSpanner() {
    }
    
    int next(int price) {
        int s=1;
        while(!prices.empty() && prices.top()<=price){
            s=s+spans.top();
            prices.pop();
            spans.pop();
        }
        prices.push(price);
        spans.push(s);
        return s;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */