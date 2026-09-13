class Solution {
public:
    void solveNqueen(int col,vector<string>&board,vector<int>&UD,vector<int>&LD,vector<int>&LR,int n,
    vector<vector<string>>&ans){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0 ; row<n ; row++){
            if(LR[row]==0 && UD[(n-1)+(col-row)]==0 && LD[row+col]==0){
                board[row][col]='Q';
                LR[row]=1;
                LD[row+col]=1;
                UD[(n-1)+(col-row)]=1;
                solveNqueen(col+1,board,UD,LD,LR,n,ans);
                board[row][col]='.';
                LR[row]=0;
                LD[row+col]=0;
                UD[(n-1)+(col-row)]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0 ; i<n ; i++){
            board[i]=s;
        }

        vector<int>UpperD(2*n-1,0),LowerD(2*n-1,0),LeftRow(n,0);
        solveNqueen(0,board,UpperD,LowerD,LeftRow,n,ans);
        return ans;
    }
};