class Solution {
    bool arrangement(int row,int col,vector<string>& board,int n){
        int originalrow=row;
        int originalcol=col;
        while(row>=0 && col>=0 ){
            if (board[row][col]=='Q')
            return false;
            row--;
            col--;
        }
        row=originalrow;
        col=originalcol;
        while(row>=0){
            if(board[row][col]=='Q')
            return false;
            row--;
        }
        row=originalrow;
        col=originalcol;
        while(row>=0 && col<n){
            if(board[row][col]=='Q')
            return false;
            row--;
            col++;
        }
        return true;

    }
    void solution(int row,vector<string>& board,vector<vector<string>>& ans,int n){
        if(row == n){
        ans.push_back(board);
        return;
        }
        for(int col=0;col<n;col++){
            if(arrangement(row,col,board,n)){
                board[row][col] =  'Q';
                solution(row+1,board,ans,n);
                board[row][col] =  '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solution(0,board,ans,n);
        return ans;
    }
};