class Solution
{
    public:
    void rightv(Node *root,int& c,int& k,vector<int>& s){
        if(root==NULL){
            return;
        }
        c=c+1;
        if(c>k){
            k=c;
            s.push_back(root->data);
        }
        rightv(root->right,c,k,s);
        rightv(root->left,c,k,s);
        c--;
        
    }
    vector<int> rightView(Node *root)
    {
       // Your Code here
       int c=0;
       int k=INT_MIN;
       vector<int>s;
       rightv(root,c,k,s);
       return s;
    }
};
//Execution Time:0.01 gfg
