//https://leetcode.com/problems/word-search/       dfs recursion backtrack
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int k){
        if(k==word.size()){
            return true;
        }
        if(i<0 || j<0 || i>board.size()-1 || j>board[0].size()-1 || board[i][j]!=word[k] ){
            return false;
        }
        k++;
        char l=board[i][j];
        board[i][j]='#';
         bool d1=dfs(board,word,i-1,j,k);
         bool d2=dfs(board,word,i+1,j,k);
         bool d3=dfs(board,word,i,j-1,k);
         bool d4=dfs(board,word,i,j+1,k);
        board[i][j]=l;
        return d1||d2||d3||d4;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
            
                if(board[i][j]==word[0]){
                  if(dfs(board,word,i,j,0)){
                      return true;
                      
                  }
                }
            } 
        }
        return false;
    }
};
