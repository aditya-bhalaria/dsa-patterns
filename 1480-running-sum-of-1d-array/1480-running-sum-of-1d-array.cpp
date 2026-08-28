class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<int> ans;
        int running_sum=0;
        int i=0;
        while(i<nums.size()){
           running_sum+=nums[i];
           int store = sum-(sum-running_sum);
           ans.push_back(store);
           i++;
        }
     return ans;
    }
};