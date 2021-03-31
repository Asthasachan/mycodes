//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
//Execution Time:0.15

void boul(Node* root,vector<int>& a){
    if(root==NULL){
        return ;
    }
    if(root->left){
            a.push_back(root->data);
            boul(root->left,a);
    }
    else if(root->right){
            a.push_back(root->data);
            boul(root->right,a);
    }
}
void boulea(Node* root,vector<int>& a){
    if(root==NULL){
        return ;
    }
     boulea(root->left,a);
    if(root->left==NULL && root->right==NULL){
            a.push_back(root->data);
    }
   
    boulea(root->right,a);
    
}
void bour(Node* root,vector<int>& a){
    if(root==NULL){
        return ;
    }
    if(root->right){
    bour(root->right,a);
     a.push_back(root->data);
    }
    else if(root->left){

        bour(root->left,a);
        a.push_back(root->data);

    }
}  

vector <int> printBoundary(Node *root)
{
     //Your code here
     vector<int>a;
     a.push_back(root->data);
     boul(root->left,a);
     boulea(root,a);
     bour(root->right,a);
     return a;
}
