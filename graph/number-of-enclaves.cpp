//https://leetcode.com/problems/number-of-enclaves/submissions/
class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j){
      
        if(i>grid.size()-1 || j>grid[0].size()-1 || j<0 || i<0 || grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
         dfs(grid,i-1,j);
         dfs(grid,i+1,j);
        dfs(grid,i,j-1);
       dfs(grid,i,j+1);
       
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int res=0;
       /* for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && (i==0|| j==0||i==grid.size()-1|| j==grid[0].size()-1)){
                   dfs(grid,i,j);
                }
            }
        }*/
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==1){
                 dfs(grid,i,0);
            }
            if(grid[i][grid[0].size()-1]==1){
                dfs(grid,i,grid[0].size()-1);
            }
        }
         for(int i=0;i<grid[0].size();i++){
            if(grid[0][i]==1){
                 dfs(grid,0,i);
            }
            if(grid[grid.size()-1][i]==1){
                dfs(grid,grid.size()-1,i);
            }
        }
        for(int i=1;i<grid.size()-1;i++){
            for(int j=1;j<grid[0].size()-1;j++){
                if(grid[i][j]==1){
                    res++;
                }
            }
        }
        return res;
    }
};
