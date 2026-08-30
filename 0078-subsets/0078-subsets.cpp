class Solution {
public:
    void subsetsI(int i, vector<vector<int>> &ans, vector<int> &nums, 
                  int n, vector<int> &ds) {
        
        if(i >= n) {
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        subsetsI(i+1, ans, nums, n, ds);
        ds.pop_back();

        subsetsI(i+1, ans, nums, n, ds);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();

        subsetsI(0, ans, nums, n, ds);

        return ans;
    }
};