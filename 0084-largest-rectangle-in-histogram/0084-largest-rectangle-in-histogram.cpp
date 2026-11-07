class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        long long area=0;
        int nse;
        int pse;

        stack<int>st;
        for(int i=0 ; i<heights.size() ; i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element=st.top();st.pop();
                pse=st.empty() ? -1 : st.top();
                nse=i;
                area=max(area,1LL*heights[element]*(nse-pse-1));
            }

            st.push(i);
        }
        nse=heights.size();
        while(!st.empty()){
            int element=st.top();st.pop();
            pse=st.empty() ? -1 : st.top();
            area=max(area,1LL*heights[element]*(nse-pse-1));
        }
        return area;
    }
};