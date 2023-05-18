class Solution {
public: 
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int MOD = 1e9 + 7;     
        int N = group.size();   
        
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(n+1, vector<int>(minProfit+1)));
         
        dp[0][0][0] = 1;  
        
        for (int i = 1; i <= N; i++) {
            int g = group[i-1];
            int p = profit[i-1];
            
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= minProfit; k++) {
                    // Don't use the i-th crime
                    dp[i][j][k] = dp[i-1][j][k];
                    
                    // Use the i-th crime
                    if (j >= g) {
                        dp[i][j][k] += dp[i-1][j-g][max(0, k-p)];
                    }
                    
                    dp[i][j][k] %= MOD;
                }
            }
        }
        
        int ans = 0;
        for (int j = 0; j <= n; j++) {
            ans += dp[N][j][minProfit];
            ans %= MOD;
        }
        
        return ans;
    }
};
