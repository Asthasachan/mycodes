//https://leetcode.com/problems/n-queens/         backtrack
class Solution {
public:
    bool valid(vector<string> s,int r,int c){
        for(int i=r-1;i>=0;i--){
            if(s[i][c]=='Q'){
                return false;
            }
        }
        for(int i=r,j=c;i>=0 && j>=0;i--,j-- ){
            if(s[i][j]=='Q'){
                return false;
            }
        }
         for(int i=r,j=c;i>=0 && j<s[0].size();i--,j++ ){
            if(s[i][j]=='Q'){
                return false;
            }
        }
        return true;
        
    }
    void dfs(vector<string> s, vector<vector<string>>&res,int r){
        if(r==s.size()){
            res.push_back(s);
            return;
        }
        for(int i=0;i<s[0].size();i++){
            if(valid(s,r,i)){
                s[r][i]='Q';
                dfs(s,res,r+1);
                s[r][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>s(n,string(n,'.'));
        dfs(s,res,0);
        return res;
    }
};
