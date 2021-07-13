//https://leetcode.com/problems/combination-sum/    do with dp also
class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>> &g,int n,vector<int>c){
        if(target==0){
            g.push_back(c);
            return;
        }
        if(target<0 || n<0){
            return;
        }
        if(candidates[n]<=target){
            c.push_back(candidates[n]);
            solve(candidates,target-candidates[n],g,n,c);
            c.pop_back();
        }
        solve(candidates,target,g,n-1,c);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>g;
        int n=candidates.size();
        vector<int>c;
        solve(candidates,target,g,n-1,c);
        return g;
    }
};
