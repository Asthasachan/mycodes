//Execution Time:0.01
//https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1#

unordered_map<string,int> m;
string sol(Node* root){
    if(root==NULL){
        return "$";
    }
    string s="";
    if(root->left==NULL && root->right==NULL){
        s=to_string(root->data);
        return s;
    }
    s=s+ to_string(root->data);
    s=s+sol(root->left);
    s=s+sol(root->right);
    m[s]++;
    return s;
}
bool dupSub(Node *root)
{
     //your code here
     m.clear();
     sol(root);
     for(auto x:m){
         if(x.second>=2){
             return true;
         }
     }
    return false; 
}
