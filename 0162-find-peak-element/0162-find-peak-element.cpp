class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int start=1,end=nums.size()-2,mid,ans;
        if(nums[start-1]>nums[start]){
            return start-1;
        }
        if(nums[end+1]>nums[end]){
            return end+1;
        }
        while(start<=end){
            mid=start+((end-start)/2);
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]<=nums[mid+1]){
                ans=mid+1;
                start=mid+1;
            }
            else{
                ans=mid;
                end=mid;
            }
        }
        return -1;
    }
};