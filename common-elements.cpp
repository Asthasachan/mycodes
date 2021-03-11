class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            
            vector<int>p;
          int i=0,j=0,k=0;
          while(i<n1 && j<n2 && k<n3){
              if(A[i]==B[j] && B[j]==C[k]){
                  if(p.size()>=1){
                       if(A[i]==p.back()){
                           i++;
                           j++;
                           k++;
                      continue;
                  }
                  }
                  p.push_back(A[i]);
                  i++;
                  j++;
                  k++;
                 
              }
              else if(A[i]<B[j]){
                  i++;
              }
              else if(B[j]<C[k]){
                  j++;
              }
              else{
                  k++;
              }
          }
            return p;
        }

};
//Execution Time:0.24
//https://practice.geeksforgeeks.org/problems/common-elements1132/1#
