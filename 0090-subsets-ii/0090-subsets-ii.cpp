
class Solution {
public:
    void SubsetII(int i , vector <int> &original , vector<vector<int>> &ans , vector <int> &ds , int n){
        
            ans.push_back(ds);
            
        
        for(int ind=i ; ind < original.size() ; ind++){
            if(ind > i && original[ind] == original[ind-1]) continue;
            ds.push_back(original[ind]);
            SubsetII(ind+1,original,ans,ds,n);
            ds.pop_back();
            // SubsetII(ind+1,original,ans,ds,n);
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <int> a;
        vector<vector<int>>  s;
        sort(nums.begin(),nums.end());
        SubsetII(0,nums,s,a,nums.size());
        return s;
    }
};