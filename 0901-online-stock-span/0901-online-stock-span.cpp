class StockSpanner {
public:
    stack<int> st;
    int day = 0;
    vector<int> prices;

    int next(int price) {
        prices.push_back(price);
        int pge = 0;

        while (!st.empty() && prices[day] >= prices[st.top()]) {
            st.pop();
        }

        int css=day-(st.empty() ? -1 : st.top());
        st.push(day);
        day++;
        return css;

        // if (st.empty()) {
        //     st.push(day);
        //     pge = -1;
        //     int current_stock_span = day - pge;
        //     day++;
        //     return current_stock_span;
        // }

        // else  {
        //     pge = st.top();
        //     int current_stock_span = day;
        //     st.push(day);
        //     day++;
        //     return current_stock_span - pge;
        // }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */