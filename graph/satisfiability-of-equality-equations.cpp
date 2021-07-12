//https://leetcode.com/problems/satisfiability-of-equality-equations/    92% fast
class Solution {
public:
    int find(vector<int> &uf, int i){
        if(uf[i]==-1 || uf[i]==i){
            return i;
        }
       return  find(uf,uf[i]);
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int>uf(26,-1);
        for(auto s:equations){
            if(s[1]=='='){
                uf[(find(uf,s[0]-'a'))]=find(uf,s[3]-'a');
            }
        }
        for(auto s:equations){
            if(s[1]=='!' && find(uf,s[0]-'a')==find(uf,s[3]-'a'))
            {
                return false;
            }
        }
        return true;
    }
    /*
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>>g(26);
        for(auto i:equations){
            if(i[1]=='='){
                g[i[0]-'a'].push_back((int)(i[3]-'a'));
                   g[i[3]-'a'].push_back((int)(i[0]-'a'));
            }
        }
        vector<int>color(26,0);
        stack<int>s;
        int t=0;
        for(int i=0;i<26;i++){
            if(color[i]==0){
                t++;
                s.push(i);
                while(!s.empty()){
                    int k=s.top();s.pop();
                    for(int nei:g[k])
                    {
                        if(color[nei]==0){
                            color[nei]=t;
                            s.push(nei);
                        }
                    }
                }
            }
        }
        for(auto i:equations){
            if(i[1]=='!'){
                int a=i[0]-'a';
                int b=i[3]-'a';
                if(a==b || (color[a]!=0 && color[a]==color[b])){
                    return false;
                }
            }
        }
        return true;
    }
    */
