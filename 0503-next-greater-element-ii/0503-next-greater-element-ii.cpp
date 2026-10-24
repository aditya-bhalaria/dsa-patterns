class Solution {
public:
    // Brute force can be checking the whole array in a circular manner the
    // complexity will be nearly n2

    // optimal:Asuume hypothetical array of size 2*n-1

    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        stack<int> st;
        vector<int> ans(nums.size());
        long long Ms = 2 * size-1;
        for (int i = Ms ; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i%size]) {
                st.pop();
            }

            if (st.empty()) {
                if (i < size) {
                    st.push(nums[i]);
                    ans[i] = -1;
                } else {
                    st.push(nums[i%size]);
                }
            } else if (!st.empty() && st.top() > nums[i%size]) {
                if (i < size) {
                    ans[i] = st.top();
                    st.push(nums[i]);
                } else {
                    st.push(nums[i%size]);
                }
            }
        }
        return ans;
    }
};