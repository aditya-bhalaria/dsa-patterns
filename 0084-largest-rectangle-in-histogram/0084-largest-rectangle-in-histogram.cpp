class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area=0;
        stack<int>st;
        for(int i=0 ; i<heights.size() ; i++){

          while(!st.empty() && heights[st.top()]>heights[i]){
            int element_indx=st.top();st.pop();
            int pse=st.empty() ? -1 : st.top(),nse=i;
            max_area=max(max_area , heights[element_indx]*(nse-pse-1));
          }
          
            st.push(i);
           
        }
        while(!st.empty()){
          int element_index=st.top();st.pop();
          int nse=heights.size(),pse=st.empty()?-1:st.top();
          max_area=max(max_area , heights[element_index]*(nse-pse-1));
        }
        return max_area;
    }
};
