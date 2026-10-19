class MinStack {
public:
int Min=INT_MAX;
stack<long long int>st;

    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            Min=value;
        }
         else if(value<Min){
            st.push(2LL*value-Min);
            Min=value;
         }
         else{
            st.push(value);
         }
    }
    
    void pop() {
        if(st.empty()){
            Min=INT_MAX;
            return;
        }
        if(st.top()<Min){
            Min=2LL*Min-st.top();
            st.pop();
        }
        else{
            st.pop();
        }
        if(st.empty()){
            Min=INT_MAX;
        }
    }
    
    int top() {
        
        if(st.top() < Min){
            return Min;
        }
        return st.top();
    }
    
    int getMin() {
        return Min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */