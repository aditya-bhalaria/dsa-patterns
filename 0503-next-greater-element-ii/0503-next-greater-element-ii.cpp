class Solution {
public:
    // Brute force can be checking the whole array in a circular manner the
    // complexity will be nearly n2

    // optimal:Asuume hypothetical array of size 2*n-1

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = 2 * nums.size() - 1;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int element = -1;
            for (int j = i + 1; j <= n; j++) {
                if ((nums[j % nums.size()] > nums[i])) {
                    element = nums[j % nums.size()];
                    break;
                }
            }
            ans.push_back(element);
        }
        return ans;
    }
};