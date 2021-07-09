//https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1#     0.0
/*int lps(string str,int i,int j,vector<vector<int>>&dp){
        if(i==j){
            return 1;
        }
        if(str[i]==str[j] && i+1==j){
            return 2;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(str[i]==str[j]){
            return dp[i][j]= 2+lps(str,i+1,j-1,dp);
        }
        else{
            return dp[i][j]=max(lps(str,i+1,j,dp),lps(str,i,j-1,dp));
        }
    }*/
    int countMin(string str){
    //complete the function here
    int n=str.size();
    vector<vector<int>>dp(n,vector<int>(n));
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
     for (int cl=2; cl<=n; cl++)
    {
        for (int i=0; i<n-cl+1; i++)
        {
            int j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               dp[i][j] = 2;
            else if (str[i] == str[j])
               dp[i][j] = dp[i+1][j-1] + 2;
            else
               dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
        }
    }
 
    return n-dp[0][n-1];
   // return n-lps(str,0,n-1,dp);
    
    }
