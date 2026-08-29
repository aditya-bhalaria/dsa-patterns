class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int  i=0;
        int j=2*nums.size();
        int it=0;
        vector<int> ans;
        while(it<j){
          ans.push_back(nums[i]);
          i++;
          it++;

          if(i==nums.size()) i=0;
        }
        return ans;
    }
};