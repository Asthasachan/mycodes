//https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
//Execution Time:0.13 gfg
vector <int> zigZagTraversal(Node* root)
{
	// Code here
	vector<int>a;
	if(root==NULL){
	    return a;
	}
	queue<Node*>q;
	q.push(root);
	int f=1;
	while(!q.empty()){
	    int s=q.size();
	    vector<int>b;
	    while(s--){
	        Node* t=q.front();
	        b.push_back(t->data);
	        q.pop();
	        if(t->left!=NULL){
	            q.push(t->left);
	        }
	        if(t->right!=NULL){
	            q.push(t->right);
	        }
	    }
	    if(f%2==0){
	        reverse(b.begin(),b.end());
	    }
	    for(int i=0;i<b.size();i++){
	        a.push_back(b[i]);
	    }
	    f++;
	}
	return a;
}
