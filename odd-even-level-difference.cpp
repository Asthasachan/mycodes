void getlev(Node* root,int& c,int& o,int& e){
    if(root==NULL){
        return;
    }
    c=c+1;
    if(c%2==0){
        e=e+root->data;
    }
    else{
        o=o+root->data;
    }
    getlev(root->left,c,o,e);
    getlev(root->right,c,o,e);
    c--;
    
    
}
int getLevelDiff(Node *root)
{
   //Your code here
   int c=0;
   int o=0;
   int e=0;
   getlev(root,c,o,e);
   return o-e;
   
}
//Execution Time:0.12 gfg
//https://practice.geeksforgeeks.org/problems/odd-even-level-difference/1/
