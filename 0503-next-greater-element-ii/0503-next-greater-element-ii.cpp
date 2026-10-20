class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      int n=nums.size();
      stack<int>st;
      vector<int>ans(n);
      int Letsize=2*n-1;
      for(int i=Letsize ; i>=0 ; i--){
        while(!st.empty() && st.top() <= nums[i%n]){
          st.pop();
        }

        if(st.empty()){
          if(i<n){
            ans[i%n]=-1;
          }
          st.push(nums[i%n]);
        }
        else if(st.top() > nums[i%n]){
          if(i<n){
            ans[i%n]=st.top();
          } 
            st.push(nums[i%n]);
          
        }
        else st.push(nums[i%n]);
      }
         return ans;
    }
};