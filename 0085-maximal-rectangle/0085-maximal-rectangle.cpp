class Solution {
public:

    int LargestHistogram(vector<int>arr){
        int area=0;
        int nse=0,pse=0;
        int elmnt_indx;
        stack<int>st;
        for(int i=0 ; i<arr.size() ; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                elmnt_indx=st.top();st.pop();
                nse=i; pse=st.empty() ? -1 : st.top();
                area=max(area,arr[elmnt_indx]*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            elmnt_indx=st.top();st.pop();
            nse=arr.size();
            pse=st.empty() ? -1 : st.top();
        area=max(area,arr[elmnt_indx]*(nse-pse-1));
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        vector<vector<int>>Prefix(matrix.size(),vector<int>(matrix[0].size(),0));

        for(int col=0 ; col<matrix[0].size() ; col++){
            for(int row=0 ; row<matrix.size() ; row++){
                if(row==0){
                    Prefix[row][col]=matrix[row][col]-'0';
                }
                else{
                    if(matrix[row][col]=='1'){
                        Prefix[row][col]=1+Prefix[row-1][col];
                    }
                    else{
                        Prefix[row][col]=0;
                    }
                }
            }
        }
        for(int i=0 ; i<Prefix.size() ; i++){
            ans=max(ans,LargestHistogram(Prefix[i]));
        }
        return ans;

    }
};