void lca(Node *root, int n1, int n2,int& k,int & f){ 
    if(root==NULL){
    return;
        }
       if((root->data >n1 && root->data <n2) 
       || (root->data >n2 && root->data <n1)){
           if(f==0){
          k=root->data;
          f=1;
           }
      
       }
       if(root->data>n1 && root->data>n2){
           lca(root->left,n1,n2,k,f);
       }
       if(root->data<n1 && root->data<n2){
             lca(root->right,n1,n2,k,f);
       }
       if(root->data == n1){
            if(f==0){
          k=root->data;
          f=1;
          
           }
       
       }
       if(root->data == n2){
          if(f==0){
          k=root->data;
          f=1;
           }
           
       }
   }
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   int k;
   int f=0;
   lca(root,n1,n2,k,f);
   Node *h=new Node(k);
   return h;
  
} 
//Execution Time:0.21 gfg
