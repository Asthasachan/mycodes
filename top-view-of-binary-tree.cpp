//top-view-of-binary-tree
//Execution Time:0.02 gfg
//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
//level order + vertical order
void topv(struct Node *root,map<int,int>& m){
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        Node* a=q.front().first;
        int b=q.front().second;
        q.pop();
        if(!m[b]){
            m[b]=a->data;
        }
        if(a->left!=NULL){
            q.push({a->left,b-1});
        }
         if(a->right!=NULL){
            q.push({a->right,b+1});
        }
    }
}
vector<int> topView(struct Node *root)
{
    //Your code here
    map<int,int>m;
    vector<int>v;
    topv(root,m);
    for(auto i:m)
    {
        v.push_back(i.second);
    }
    return v;
}
