class Solution {
public:

    int MaxHistogram(vector<int>row){
      stack<int>st;
      int max_area=0;

      for(int i=0 ; i<row.size() ;i++){

        while(!st.empty() && row[st.top()]>row[i]){
          int element=st.top();st.pop();
          int nse=i;
          int pse=st.empty() ? -1 : st.top();
          max_area=max(max_area,row[element]*(nse-pse-1));
        }
        st.push(i);
    }
    while(!st.empty()){
      int ele=st.top(); st.pop();
      int nse=row.size();
      int pse=st.empty() ? -1 : st.top();
      max_area=max(max_area,row[ele]*(nse-pse-1));
    }
    return max_area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
      int rows = matrix.size();
      int cols = matrix[0].size();
      stack<int>st;
      int Area=0;
        vector<vector<int>>Prefix(rows,vector<int>(cols,0));

        for(int i=0 ; i<cols ; i++){
          for(int j=0 ; j<rows ;j++){
            if(j==0){
              Prefix[j][i]=matrix[j][i]-'0';
            }
            else{
              if(matrix[j][i]=='1'){
                Prefix[j][i]=1+(Prefix[j-1][i]);
              }
              else{
                Prefix[j][i]=0;
              }
            }
          }
        }
        for(int i=0 ; i<rows ; i++){
          Area=max(Area,MaxHistogram(Prefix[i]));
        }
   return Area;

    }
};