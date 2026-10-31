class Solution {
public:
    int trap(vector<int>& h) {
        int left=0 ,  right=h.size()-1;
        int total=0;
        int leftMax=0,rightMax=0;

        while(left<right){
            if(h[left]<=h[right]){
                if(h[left]>=leftMax){
                    leftMax=h[left];
                }
                else{
                    total+=(leftMax-h[left]);
                }
                left++;
            }
            else{
                if(h[right]>=rightMax){
                    rightMax=h[right];
                }
                else{
                    total+=(rightMax-h[right]);
                }
                right--;
            }
            
        }
            return total;
    }
};