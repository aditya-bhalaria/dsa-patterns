class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxCandy=*max_element(candies.begin(),candies.end());
        int iter=0;

        int i=0;
        while(i<candies.size()){
            iter=(extraCandies+candies[i]);
            if(iter >= maxCandy){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
            i++;
        }
        return ans;
    }
};