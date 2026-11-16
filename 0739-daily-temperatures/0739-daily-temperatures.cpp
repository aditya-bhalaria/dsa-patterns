class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums2) {
           stack<int>st;  //Monotonic Stack for storing the element in the order wise 6 , 4 , 3..
      
      vector<int>v(nums2.size()); //to store the answer
      
      for(int i=nums2.size()-1 ; i>=0 ; i--){
        while(!st.empty() && nums2[st.top()] <= nums2[i]){ 
            st.pop();  //pop if stack element is disrupting the monotonic order
        }
        if(st.empty()){
           st.push(i);
           v[i]=0; //if stack is empty or the last element then next greater will be -1
        }
        else if(nums2[i] < nums2[st.top()]){
              //if the top element is next greater element of nums2[i] then map it mp[nums2[i]]=st.top()
            v[i]=st.top()-i;     //push the element in the stack
            st.push(i); 
        }
        
      }
      return v;  /// return the answer
    }
};