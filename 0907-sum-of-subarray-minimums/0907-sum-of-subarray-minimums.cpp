class Solution {
public:
   
    vector<int> PSEE(vector<int> arr){
      stack<int> st;
      vector<int> ans(arr.size());

      for(int i=0 ; i<arr.size() ; i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
          st.pop();
        }

       ans[i]=st.empty() ? -1:st.top();
       st.push(i);

      }
      return ans;
    }

    vector<int> NSE(vector<int> arr){
      stack<int> st;
      vector<int> ans(arr.size());

      for(int i=arr.size()-1 ; i>=0 ; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
          st.pop();
        }

       ans[i]=st.empty()?arr.size() : st.top();
          st.push(i);

      }
      return ans;
    }
    int sumSubarrayMins(vector<int>v){
      vector<int>Pse=PSEE(v);
      vector<int>Nse=NSE(v);
      const long long MOD=(int)1e9+7;
       int ans=0;
       for(int i=0 ; i<v.size() ; i++){
        int left=i-Pse[i];
        int right=Nse[i]-i;
        ans = (ans + 1LL * left * right * v[i]) % MOD;
       }
       return ans;
    }
};
