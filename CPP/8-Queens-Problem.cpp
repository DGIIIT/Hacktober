class Solution {
public:
    vector<vector<string>> ans;
   
    void placeQueens(vector<string> board,int curr,int n,set<int> diagonalLeft,set<int> diagonalRight,set<int> vertical){
        
        if(curr==n){
            
            ans.push_back(board);
            return ;
        }
        for(int col=0;col<n;col++){
            
            if(diagonalLeft.find(curr-col)==diagonalLeft.end() && diagonalRight.find(curr+col)==diagonalRight.end() && vertical.find(col)==vertical.end()){
                board[curr][col]='Q';
                diagonalLeft.insert(curr-col);
                diagonalRight.insert(curr+col);
                vertical.insert(col);
                placeQueens(board,curr+1,n,diagonalLeft,diagonalRight,vertical);
                diagonalLeft.erase(curr-col);
                diagonalRight.erase(curr+col);
                vertical.erase(col);
                board[curr][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board;
        for(int i=0;i<n;i++){
            string str="";
            for(int j=0;j<n;j++){
                str+=".";
            }
            board.push_back(str);
        }
        set<int> diagonalLeft;
        set<int> diagonalRight;
        set<int> vertical;
        placeQueens(board,0,n,diagonalLeft,diagonalRight,vertical);
        return ans;
    }
};
