class Solution {
public:
void dfs(int V, vector<int> adj[],stack<int>&s,set<int>& seen,vector<int>& k){

    s.push(0);
    while(!s.empty()){
        int c=s.top();
        s.pop();
        if(seen.find(c)==seen.end()){
            seen.insert(c);
            k.push_back(c);
        }
        for(int i=adj[c].size()-1;i>=0;i--){
              if(seen.find(adj[c][i])==seen.end()){
            s.push(adj[c][i]);
        }
        }
    }
}
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	    stack<int>s;
	    set<int>seen;
	    vector<int>k;
	    dfs(V,adj,s,seen,k);
	    return k;
	}
};

/*
Correct Answer.Correct Answer
Execution Time:0.01 gfg
*/
