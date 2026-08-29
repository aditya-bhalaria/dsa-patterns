class Solution {
public:
    void CombinationII(vector <int> &C,vector<vector<int>> &store,vector<int> &ds,int i,int t){
        if(t==0){
          store.push_back(ds);
          return;
        }

        for(int ind=i ; ind < C.size(); ind++){
            if(ind > i && C[ind]==C[ind-1]) continue;
            if(C[ind] > t) break;
            ds.push_back(C[ind]);
            CombinationII(C,store,ds,ind+1,t-C[ind]);
            ds.pop_back();
        }
      
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> d;
        vector<vector<int>> v;
        CombinationII(candidates,v,d,0,target);
        return v;
    }
};