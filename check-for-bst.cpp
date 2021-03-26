class Solution
{
    public:
    void inord(Node* root,vector<int>& a){
        if(root==NULL){
            return;
        }
        inord(root->left,a);
        a.push_back(root->data);
        inord(root->right,a);
    }
    bool isBST(Node* root) 
    {
        // Your code here
       vector<int>a;
       inord(root,a);
       for(int i=1;i<a.size();i++){
           if(a[i]<=a[i-1]){
               return false;
           }
       }
       return true;
    }
};
