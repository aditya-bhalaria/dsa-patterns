class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        int LetIndex=2*n;
        vector<int>ans(nums.size());

        stack<int>st;
        for(int i=LetIndex-1 ; i>=0 ; i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
          
        if(st.empty()){
            if(i>=n){
                st.push(nums[i%n]);
            }
            else{
                st.push(nums[i]);
                ans[i]=-1;
            }
        }
        else if(!st.empty() && st.top()>nums[i%n]){
            if(i>=n) st.push(nums[i%n]);
            else{
                ans[i]=st.top();
                st.push(nums[i]);
            }
        }
        }
        return ans;
    }
};