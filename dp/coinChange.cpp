//https://practice.geeksforgeeks.org/problems/coin-change2448/1#  0.03

long long int rod( int S[], int n, int tot ,vector<vector<long long int>>&dp){
        if(tot==0){
            return 1;
        }
        if(n==0 || tot<0){
            return 0;
        }
        if(dp[n][tot]!=-1){
            return dp[n][tot];
        }
        if(S[n-1]<=tot){
            return dp[n][tot]= rod(S,n,tot-S[n-1],dp)+rod(S,n-1,tot,dp);
        }
        else{
            return dp[n][tot]=rod(S,n-1,tot,dp);
        }
  }
    long long int count( int S[], int n, int tot )
    {    vector<vector<long long int>>dp(n+1,vector<long long int>(tot+1,-1));
        
       return rod(S,n,tot,dp);
        //code here.
    }
