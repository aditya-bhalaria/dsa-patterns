class Solution {
public:
    int Lower_Bound(vector <int>&Lb,int target){
  int start=0,end=Lb.size()-1;
  int mid;
    int ans=Lb.size();
        while(start<=end){
        mid=start+((end-start)/2);
         if(Lb[mid]>=target){
          ans=mid;
          end=mid-1;
         }
         else{
        start=mid+1;
         }
        }
        return ans;
}
int Upper_Bound(vector<int>&Up,int target){
int mid2;
    int ans2=Up.size();
        int start2=0,end2=Up.size()-1;
        while(start2<=end2){
        mid2=start2+((end2-start2)/2);
         if(Up[mid2]>target){
          ans2=mid2;
          end2=mid2-1;
         }
         else{
        start2=mid2+1;
         }
        }
        return ans2;
}
    vector<int> searchRange(vector<int>& nums, int target) {
    int num1=Lower_Bound(nums,target);
    int num2=Upper_Bound(nums,target);
    if(num1==nums.size()|| nums[num1]!=target){
        return {-1,-1};
    }
    return {num1,num2-1};
    }
};