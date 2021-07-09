//https://leetcode.com/problems/keys-and-rooms/
 void dfs(vector<vector<int>>& rooms,vector<int>& vis,int &c,int cur=0){
        vis[cur]=1;
      /*  for(auto i:rooms[cur]){
            if(!vis[i]){
                c++;
                dfs(rooms,vis,c,i);
            }
        }
        */
   /*     stack<int>s;
        s.push(cur);
        while(!s.empty()){
            int k=s.top();s.pop();
            for(auto i:rooms[k]){
                if(!vis[i]){
                    vis[i]=1;
                    s.push(i);
                    c++;
                }
            }
        }
        */
       queue<int>q;
        q.push(cur);
        
    while(!q.empty()){
        int k=q.front();
        q.pop();
        for(int i:rooms[k]){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
                c++;
            }
        }
    }
    
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>vis(rooms.size(),0);
        int c=1;
        dfs(rooms,vis,c);
        if(c==rooms.size()){
            return true;
        }
        return false;
    }
