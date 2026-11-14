class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1=0,p2=height.size()-1;
        int ans=0;
        while(p1<p2){
            if(height[p1]<=height[p2]){
                ans=max(ans,height[p1]*(p2-p1));
                p1++;
            }
            else{
                ans=max(ans,height[p2]*(p2-p1));
                p2--;
            }
        }
        return ans;
    }
};