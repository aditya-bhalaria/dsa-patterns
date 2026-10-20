class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      stack<int>st;
      unordered_map<int,int>mp;
      vector<int>v;
      
      for(int i=nums2.size()-1 ; i>=0 ; i--){
        while(!st.empty() && st.top() <= nums2[i]){
            st.pop();
        }
        if(st.empty()){
           st.push(nums2[i]);
           mp[nums2[i]]=-1;
        }
        else if(nums2[i] < st.top()){
            mp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        
      }
      for(int iter: nums1){
        v.push_back(mp[iter]);
      }
      return v;
    }
};