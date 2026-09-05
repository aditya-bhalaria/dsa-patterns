class Solution {
public:
    void solve(int col , vector<int> &Lr , vector<vector<string>> &ans ,vector<string> &board , vector<int> &Ud , vector<int>Ld , int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
      for(int row=0 ; row<n ; row++){
        if(Lr[row] == 0 && Ld[row+col]==0 && Ud[(n-1) + (col-row)]==0){
            board[row][col]='Q';
            Lr[row]=1;
            Ld[row+col]=1;
            Ud[(n-1) + (col-row)]=1;
            solve(col+1 , Lr , ans , board , Ud , Ld , n);
            board[row][col]='.';
            Lr[row]=0;
            Ld[row+col]=0;
            Ud[(n-1) + (col-row)]=0;
        }
      }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0 ; i<n ; i++){
            board[i]=s;
        }
        vector<int> leftRow(n,0) , UpperD(2*n-1 , 0) , LowerD(2*n-1 , 0);
        solve(0,leftRow,ans,board,UpperD,LowerD,n);
        return ans;

    }
};