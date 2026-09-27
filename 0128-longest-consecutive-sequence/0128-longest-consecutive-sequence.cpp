class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_freq=0;
        unordered_set<int>st;
        for(int val: nums){
            st.insert(val);
        }
        for(int cnt: st){
            int num=cnt;
            int temp_freq=0;
            if(st.find(num-1)!=st.end()){
                continue;
            }
            while(st.find(num)!=st.end()){
                temp_freq++;
                num++;
            }
            max_freq=max(max_freq,temp_freq);
        }
        return max_freq;
    }
};