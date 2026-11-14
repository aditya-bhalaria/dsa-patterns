class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       vector<int>Arr(nums.size());
       int p1=0,p2=nums.size()-1;

       int i=Arr.size()-1;
       while(p1<=p2){
         if(abs(nums[p1])<=abs(nums[p2])){
             Arr[i]=nums[p2]*nums[p2];
             p2--;
             i--;
         }
         else{
            Arr[i]=nums[p1]*nums[p1];
            p1++;
            i--;
         }
       }
       return Arr;
    }
};