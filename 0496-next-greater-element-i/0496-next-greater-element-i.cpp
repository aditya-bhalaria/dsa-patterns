class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans;
        unordered_map<int, int> mp;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }
            if (st.empty()) {
                mp[nums2[i]] = -1;
                st.push(nums2[i]);
            } else if (!st.empty() && nums2[i] < st.top()) {
                mp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
            // else{
            //     st.push(nums2[i])
            // }
        }
        for (int iter : nums1) {
            ans.push_back(mp[iter]);
        }
        return ans;
    }
};