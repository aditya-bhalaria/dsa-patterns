class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(int val: nums){
            st.insert(val);
        }

        int mul=k;
        int i=0;
        while(i<nums.size()){
            if(st.find(mul)==st.end()){
                break;
            }
            else{
                mul+=k;
            }
        }
        return mul;
    }
};