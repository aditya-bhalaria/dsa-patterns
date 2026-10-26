class Solution {
public:
    int trap(vector<int>& height) {
      int n=height.size();
      int array_max=INT_MIN;
        vector<int>PrefixMax;
        vector<int>PostfixMax(n);

        for(int i=0 ; i<n ; i++){
           array_max=max(height[i],array_max);
           PrefixMax.push_back(array_max);
        }

          array_max=INT_MIN;
        for(int i=n-1 ; i>=0 ; i--){
           array_max=max(height[i],array_max);
           PostfixMax[i]=array_max;
        }
        int ans=0;
        int j=0;
        while(j<n){
          ans+=(min(PrefixMax[j],PostfixMax[j])-height[j]);
          j++;
        }
        return ans;
    }
};