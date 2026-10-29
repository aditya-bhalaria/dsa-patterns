class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int i = 1;
        for (int iter : nums) {
            if (n % i == 0) {
                ans += (iter * iter);
            }
            i++;
        }
        return ans;
    }
};