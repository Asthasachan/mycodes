class Solution {
public:
	void bfs(int V, vector<int> adj[],queue<int>&s,set<int>& seen,vector<int>& k){

    s.push(0);
    while(!s.empty()){
        int c=s.front();
        s.pop();
        if(seen.find(c)==seen.end()){
            seen.insert(c);
            k.push_back(c);
        }
        for(int i=0;i<adj[c].size();i++){
              if(seen.find(adj[c][i])==seen.end()){
            s.push(adj[c][i]);
        }
        }
    }
}
	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	      queue<int>s;
	    set<int>seen;
	    vector<int>k;
	    bfs(V,adj,s,seen,k);
	    return k;
	}



};
//Execution Time:0.13
