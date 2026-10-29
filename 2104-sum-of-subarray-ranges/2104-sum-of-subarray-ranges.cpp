class Solution {
public:
    vector<int> PGE(vector<int>arr){
      stack<int>st;
      vector<int>ans(arr.size());

      for(int i=0 ; i< arr.size() ; i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
          st.pop();
        }

        ans[i]=st.empty() ? -1:st.top();
        st.push(i);
      }
      return ans;
    }

    vector<int> NGE(vector<int> arr){
      stack<int> st;
      vector<int> ans(arr.size());

      for(int i=arr.size()-1 ; i>=0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]){
          st.pop();
        }
        ans[i]=st.empty() ? arr.size() : st.top();
        st.push(i);
      }
      return ans;
}

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
    long long subArrayRanges(vector<int>& nums) {
      const long long MOD=(int)1e9+7;
        vector<int>Pge=PGE(nums);
        vector<int>Nge=NGE(nums);
        vector<int>Pse=PSEE(nums);
        vector<int>Nse=NSE(nums);
        long long t1=0,t2=0;
        for(int i=0 ; i<nums.size() ; i++){
          int l1=i-Pse[i];
          int r1=Nse[i]-i;
          t1=(t1+1LL*l1*r1*nums[i]);
          int l2=i-Pge[i];
          int r2=Nge[i]-i;
          t2=(t2+1LL*l2*r2*nums[i]);
        }
        return (t2-t1);
    }
};