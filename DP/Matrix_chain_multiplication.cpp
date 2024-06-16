// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int> (N, 0));
        
        for(int l = 1; l<N; l++) {
            for(int i = 1; i<=N-l; i++) {
                int j = i+l-1;
                if(i == j) dp[i][j] = 0;
                else {
                    dp[i][j] = INT_MAX;
                    for(int k = i; k<j; k++) {
                        int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                        dp[i][j] = min(dp[i][j], cost);
                    }
                }
            }
        }
        
        return dp[1][N-1];
    }
};