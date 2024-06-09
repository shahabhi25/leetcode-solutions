class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n-i; j++)
            {
                int x=j;
                int y=i+j;
                if(x==y) dp[x][y]=1;
                else if(y-x==1)
                {
                    dp[x][y] = s[x]==s[y]?2:1;
                }
                else
                {
                    int temp = s[x]==s[y] ? dp[x+1][y-1]+2 : dp[x+1][y-1];
                    dp[x][y] = max({temp, dp[x+1][y], dp[x][y-1]});
                }
            }
        }
        return dp[0][n-1];
    }
};