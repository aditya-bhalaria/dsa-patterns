class Solution {
public:
    void finalans(int i , vector <int> &v,int t, vector <int> ds,int n,vector<vector<int>> &store){
       if(i==n){
        if(t == 0){
            store.push_back(ds);
        }
        return;
       }

       if(v[i] <= t){
         ds.push_back(v[i]);
         finalans(i,v,t-v[i],ds,n,store);
         ds.pop_back();
       }
         finalans(i+1,v,t,ds,n,store);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <int> vect;
        vector <vector<int>> V;
        finalans(0,candidates , target , vect , candidates.size(),V);
        return V;
    }
};