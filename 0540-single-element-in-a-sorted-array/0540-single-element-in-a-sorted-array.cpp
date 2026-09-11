class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=1,end=nums.size()-2,mid,ans=-1;
        if(nums.size()==1){
            return nums[0];
        }
        if(nums[start-1]!=nums[start]){
            return nums[start-1];
        }
        if(nums[end+1]!=nums[end]){
            return nums[end+1];
        }
        while(start<=end){
            mid=start+((end-start)/2);
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            else{
                if(nums[mid]==nums[mid+1]){
                    end=mid-1;
                }
                else{
                     start=mid+1;
                }
            }
        }
        return nums[start];
    }
};