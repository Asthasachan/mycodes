//rod cutting https://practice.geeksforgeeks.org/problems/cutted-segments1642/1# 0.03
int rod(int n, int x, int y, int z,vector<int>&dp ){
        if(n==0){
            return 0;
        }
        if(n<0){
            return INT_MIN;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int x1=rod(n-x,x,y,z,dp)+1;
        int y1=rod(n-y,x,y,z,dp)+1;
        int z1=rod(n-z,x,y,z,dp)+1;
     return dp[n]=max(x1,max(y1,z1));
    
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1,-1);
      int k= rod( n, x,y, z,dp);
      if(k<0){
          return 0;
      }
      return k;
     /*   if(n<=0){
            return 0;
        }
        return 1+max(maximizeTheCuts(n-x,x,y,z),max(maximizeTheCuts(n-y,x,y,z)
        ,maximizeTheCuts(n-z,x,y,z)));  */
    }
