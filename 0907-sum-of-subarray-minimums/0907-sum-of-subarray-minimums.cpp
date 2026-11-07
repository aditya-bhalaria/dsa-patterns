
const long long Mod=1e9+7;
class Solution {
public:

    vector<int> PSE(vector<int> v1){
        stack<int>st;
        vector<int>ans(v1.size());
        for(int i=0 ;i<v1.size() ; i++){
            while(!st.empty() && v1[st.top()]>=v1[i]){
                st.pop();
            }

            if(st.empty()){
                st.push(i);
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
                st.push(i);
            }
        }
        return ans;
    }
    vector<int> NSE(vector<int> v1){
        stack<int>st;
        vector<int>ans(v1.size());
        for(int i=v1.size()-1 ;i>=0 ; i--){
            while(!st.empty() && v1[st.top()]>v1[i]){
                st.pop();
            }

            if(st.empty()){
                st.push(i);
                ans[i]=v1.size();
            }
            else{
                ans[i]=st.top();
                st.push(i);
            }
        }
        return ans;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>pse=PSE(arr);
        vector<int>nse=NSE(arr);
        long long sum=0;

        for(int i=0 ; i<arr.size() ; i++){
             int left=i-pse[i];
             int right=nse[i]-i;
             long long elements=(left*right)%Mod;
             sum=(sum+elements*arr[i])%Mod;
             sum%=Mod;
        }
       return sum;
    }
};