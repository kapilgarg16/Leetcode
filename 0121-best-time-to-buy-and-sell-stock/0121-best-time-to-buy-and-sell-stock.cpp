class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)
            return 0;
        int maxi = 0;
        
        int max_pro = prices[n-1];
        
        for(int i = n-2 ; i >= 0 ; i--){
            int diff = max_pro - prices[i];
            maxi = max(maxi, diff);
            max_pro = max(max_pro, prices[i]);
        }
        
        return maxi;
    }
};