class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax=0;
        int rightMax=0,total=0;


        int left=0,right=height.size()-1;
        while(left<right){
          if(height[left]<height[right]){
            if(height[left]>=leftMax){
              leftMax=height[left];
            }
            else{
              total+=(leftMax-height[left]);
            }
            left++;
          }

          else{
            if(height[right]>=rightMax){
              rightMax=height[right];
            }
            else{
              total+=(rightMax-height[right]);
            }
            right--;
          }
        }
        return total;
    }
};