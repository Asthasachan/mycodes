class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=0;
        int min=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min){
                min=prices[i];
            }
            else{
                p=max(prices[i]-min,p);
            }
        }
        return p;
        
    }
};
/*
Runtime: 116 ms, faster than 42.11% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 93.3 MB, less than 19.01% of C++ online submissions for Best Time to Buy and Sell Stock.
*/
