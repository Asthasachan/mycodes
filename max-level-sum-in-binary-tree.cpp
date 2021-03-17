void maxlev(Node* root,int& c,vector<int>& h){
    if(root==NULL){
        return;
    }
    c=c+1;
    if(h.size()<c){
        h.push_back(root->data);
    }
    else{
        h[c-1]=h[c-1]+root->data;
    }
    maxlev(root->left,c,h);
    maxlev(root->right,c,h);
    c--;
    
}
int maxLevelSum(Node* root) {
    // Your code here
    int c=0;
    vector<int>k;
    maxlev(root,c,k);
    int h=INT_MIN;
    for(int i=0;i<k.size();i++){
        if(k[i]>h){
            h=k[i];
        }
    }
    return h;
}
//Execution Time:0.38 gfg
//can also use concept of queue
