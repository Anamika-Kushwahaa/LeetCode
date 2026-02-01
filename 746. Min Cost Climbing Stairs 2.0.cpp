class Solution {
public:
//recursion+memoization
    int solve1(vector<int>& cost,int n, vector<int>& dp){
        //base case 
        if(n==0) return cost[0];
        if(n==1) return cost[1];
        //for dp
        if(dp[n] != -1) return dp[n];

        dp[n] = cost[n]+min(solve1(cost,n-1,dp),solve1(cost,n-2,dp));
        return dp[n];
    }
//tabulation
    int solve2(vector<int>& cost,int n){
        vector<int> dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2 ; i<n ; i++){
            dp[i] = cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n+1,-1);
        // int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        // return ans;
        return solve2(cost,n);
    }
};
