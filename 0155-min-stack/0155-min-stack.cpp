class MinStack {
public:
stack<long long >st;
long long mini=INT_MAX;
long long prev_min;

    MinStack() {
        
    }
    
    void push(long long  value) {
        if(st.empty()){
            mini=value;
            prev_min=value;
            st.push(value);
        }

        else if(!st.empty() && mini>value){
            st.push(2*value-mini);
            mini=value;
        }
        else{
            st.push(value);
        }
        
    }
    
    void pop() {
    //    if(st.empty()){
    //     return -1;
    //    }
       
       if(st.top() < mini){
          mini=2*mini-st.top();
       }
       st.pop();
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
         else if(!st.empty() && st.top() < mini){
             return mini;  
        }
        else{
            return st.top();
        }
    }
    
    int getMin() {
        // if(st.empty()) return -1;  
        return mini;
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