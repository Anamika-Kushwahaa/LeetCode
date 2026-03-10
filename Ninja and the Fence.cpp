#include <bits/stdc++.h> 
#define MOD 1000000007

int add(int a,int b){
    return (a%MOD+b%MOD)%MOD;
}

int mul(int a , int b){
    return (a%MOD *1LL *b%MOD)%MOD;    //1LL range adjust krne ke liye h
}

//memoization method ---- approach 1
int solveMem(int n,int k, vector<int> &dp){
    if(n==1) return k;
    if(n==2) return add(k,mul(k,k-1));
    if(dp[n] != -1) return dp[n];

    dp[n]=add(mul(solveMem(n-2,k,dp),k-1),mul(solveMem(n-1,k,dp),k-1));
    return dp[n];
}

//tabulation method -----approach 2
int solveTab(int n, int k){
    vector<int> dp(n+1,0);
    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));

    for(int i=3 ; i<=n ; i++){
        dp[i] = add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }
    return dp[n];
}

int numberOfWays(int n, int k) {
    //for memoization function call
    // vector<int> dp(n+1,-1);
    // return solveMem(n,k,dp);

    //for tabulation function call
    return solveTab(n,k);
}
