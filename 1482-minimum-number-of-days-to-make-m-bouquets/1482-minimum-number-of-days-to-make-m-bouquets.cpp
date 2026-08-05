class Solution {
public:
    int iS_Possible(vector<int> &v,int days,int flowers){
        int total_count=0;
        int count=0;
        for(int i=0;i<v.size();i++){
         if(days>=v[i]){
            count++;
            if(count==flowers){
                total_count++;
                count=0;
            }
         }
         else{
            count=0;
         }
        }
        return total_count;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int start=*min_element(nums.begin(),nums.end());
        int end=*max_element(nums.begin(),nums.end());
        if((long long)m*k>nums.size()){
            return -1;
        }
        int ans,mid;
        while(start<=end){
            mid=start+((end-start)/2);
            ans=iS_Possible(nums,mid,k);
            if(ans>=m){
                end=mid-1;
            }
            else{
                start=mid+1;
            }

        }
      return start;
    }
};