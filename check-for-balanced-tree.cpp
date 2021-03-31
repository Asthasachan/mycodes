//https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1#
//Execution Time:0.45 gfg
int balance(Node* root,int& f){
    if(root==NULL){
        return 0;
    }
    int l=1+balance(root->left,f);
    int r=1+balance(root->right,f);
    if(l-r<-1 || l-r>1){
        f=1;
    }
    return max(l,r);
}
bool isBalanced(Node *root)
{
    //  Your Code here
    int f=0;
    balance(root,f);
    if(f==0){
        return true;
    }
    return false;
}
