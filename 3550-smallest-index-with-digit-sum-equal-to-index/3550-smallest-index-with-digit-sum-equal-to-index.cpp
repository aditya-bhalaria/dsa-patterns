class Solution {
public:
    int digitBreak(int n) {
        int sum = 0;
        int temp = n;
        while (temp != 0) {
            sum = sum + (temp % 10);
            temp /= 10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        

        for (int i = 0; i < nums.size(); i++) {
            if (digitBreak(nums[i]) == i) {
                return i;
            }
        }
        return -1;
    }
};