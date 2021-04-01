//Execution Time:0.23
//https://practice.geeksforgeeks.org/problems/construct-tree-1/1
int ind=0;
unordered_map<int,int>m;
Node* sol(int in[],int pre[], int lb,int ub){
    if(lb>ub){
        return NULL;
    }
    Node* r=new Node(pre[ind++]);
    if(lb==ub){
        return r;
    }
    int mid=m[r->data];
    r->left=sol(in,pre,lb,mid-1);
    r->right=sol(in,pre,mid+1,ub);
    return r;
}
Node* buildTree(int in[],int pre[], int n)
{
//add code here.
ind=0;
m.clear();
for(int i=0;i<n;i++){
    m[in[i]]=i;
}
Node* root=sol(in,pre,0,n-1);
return root;
}
