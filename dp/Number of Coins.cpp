//https://practice.geeksforgeeks.org/problems/number-of-coins1824/1# 0.05
int coin(int coins[], int M, int V,vector<vector<int>>&dp){
	     if(V==0){
	        return 0;
	    }
	    if(M<=0 || V<0){
	        return INT_MAX-1000001;
	    }
	    if(dp[M][V]!=-1){
	        return dp[M][V];
	    }
	  return dp[M][V]=min(1+coin(coins,M,V-coins[M-1],dp),coin(coins,M-1,V,dp));
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	    int k=coin(coins,M,V,dp);
	    if(k>=INT_MAX-1000001){
	        return -1;
	    }
	    else{
	        return k;
	    }
	   
	} 
