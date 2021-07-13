//https://leetcode.com/problems/letter-combinations-of-a-phone-number/ 100%     recursion soln we dont have to define an explicit stack or DS
class Solution {
public:
    string d[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string digits,int i,int n,vector<string>&s,string c=""){
        if(i==n){
            s.push_back(c);
            return;
        }
        solve(digits,i+1,n,s,c+d[digits[i]-'2'][0]);
        solve(digits,i+1,n,s,c+d[digits[i]-'2'][1]);
        solve(digits,i+1,n,s,c+d[digits[i]-'2'][2]);
        if(digits[i]=='7'||digits[i]=='9'){
        solve(digits,i+1,n,s,c+d[digits[i]-'2'][3]);
            }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        vector<string>s;
        int n=digits.size();
        solve(digits,0,n,s);
        return s;
    }
};
