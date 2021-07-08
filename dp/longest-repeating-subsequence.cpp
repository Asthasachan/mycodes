//https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1    0.20
	/*int lrs(string str,int i,int j,vector<vector<int>>dp){
	    if(i==0||j==0){
	        return 0;
	    }
	    if(dp[i][j]!=-1){
	        return dp[i][j];
	    }
	    if(str[i-1]==str[j-1] && i!=j){
	        return dp[i][j]= 1+lrs(str,i-1,j-1,dp);
	    }
	    return dp[i][j]=max(lrs(str,i-1,j,dp),lrs(str,i,j-1,dp));
	}*/
		int LongestRepeatingSubsequence(string str){
		    // Code here
		   
		    int n=str.size();
		    // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
		    int dp[n+1][n+1];
		    for(int i=0;i<=n;i++){
		        for(int j=0;j<=n;j++){
		            if(i==0|| j==0){
		                dp[i][j]= 0;
		            }
		            else if(str[i-1]==str[j-1] && i!=j){
		                dp[i][j]=1+dp[i-1][j-1];
		            }
		            else{
		                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		  //  return lrs(str,n,n,dp);
		  return dp[n][n];
			/*to print lrs
			
	string res="";
    int i = n, j = n;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] == dp[i-1][j-1] + 1)
        {
           res = res + str[i-1];
           i--;
           j--;
        }
        else if (dp[i][j] == dp[i-1][j])
            i--;
        else
            j--;
    }
    reverse(res.begin(), res.end())
    return res;
			*/
		}

