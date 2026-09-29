class Solution {
public:
bool existin(vector<vector<char>>&board,string word ,int row,int col,int matched,vector<vector<bool>>&vis){
    int m = board.size();
    int n = board[0].size();
    if(row<0 || row>=m || col<0 || col>=n){
        return false;
    }
    if(vis[row][col]){
        return false;
    }
    if(board[row][col]!=word[matched]){
        return false;
    }
    if(matched==word.size()-1){
        return true;
    }

    vis[row][col] = true;
    
    bool found = existin(board,word,row+1,col,matched+1,vis) ||
    existin(board,word,row,col+1, matched+1,vis) ||
    existin(board,word,row-1,col,matched+1,vis) ||
    existin(board,word,row,col-1,matched+1,vis);
    vis[row][col] = false;
    
    return found;
}

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(existin(board,word,i,j,0,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
