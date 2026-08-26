class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
    unordered_map<int,int>mpp;
    vector<int>v;
    int first,second;
    for(int val=0;val<nums.size();val++){
        first=nums[val];
        second=target-first;
        if(mpp.find(second)!=mpp.end()){
            v.push_back(mpp[second]);
            v.push_back(val);
        }
        else{
            mpp[first]=val;
        }
    }
    return v;

    }
};