//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1# execution=0.56
void backtrack(vector<vector<int>> m,int n,int l,int r,string s,vector<string>&res,vector<vector<int>>vis){
       if(l<0 || l>=n || r<0 || r>=n|| vis[l][r]==1 || m[l][r]==0){
           return;
       }
         // cout<<l<<"l "<<r<<"r "<<endl;
        if(l==n-1 && r==n-1){
            res.push_back(s);
            return;
        }
        vis[l][r]=1;
     
       // s=s+"U";
        backtrack(m,n,l-1,r,s+"U",res,vis);
       // s=s.substr(0,s.length()-1)+"D";
        backtrack(m,n,l+1,r,s+"D",res,vis);
        // s=s.substr(0,s.length()-1)+"L";
        backtrack(m,n,l,r-1,s+"L",res,vis);
        // s=s.substr(0,s.length()-1)+"R";
        backtrack(m,n,l,r+1,s+"R",res,vis);
        // s=s.substr(0,s.length()-1);
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>res;
        string s="";
        int l=0,r=0;
        vector<vector<int>>vis(n,vector<int>(n,0));
        backtrack(m,n,l,r,s,res,vis);
        sort(res.begin(),res.end());
        return res;
    }
