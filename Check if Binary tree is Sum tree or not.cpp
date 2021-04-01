//https://practice.geeksforgeeks.org/problems/sum-tree/1#
//Execution Time:0.04
class Solution
{
    public:
    void issum(Node* root,int& f){
        if(root==NULL){
            return;
        }
        issum(root->left,f);
        issum(root->right,f);
        if(root->right==NULL && root->left==NULL){
            return;
        }
        else if(root->right==NULL){
            if(root->data!=root->left->data){
                f=1;
            }
            else{
                root->data=root->left->data + root->data;
            }
        }
        else if(root->left==NULL){
            if(root->data!=root->right->data){
                f=1;
            }
            else{
                root->data=root->right->data + root->data;
            }
        }
        else{
            if(root->data !=(root->right->data+ root->left->data)){
                f=1;
            }
            else{
                 root->data=root->right->data+root->left->data + root->data;
            }
        }
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         if(root==NULL){
             return true;
         }
         int f=0;
         issum(root,f);
         if(f==0){
             return true;
         }
         return false;
    }
};
