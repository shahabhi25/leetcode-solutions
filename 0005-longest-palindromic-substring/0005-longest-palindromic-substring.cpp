class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 1;
        int ans_x{0};
        int ans_y{0};
        for(int i=0;i<n; i++)
        {
            for(int j=0; j<n-i; j++)
            {
                int x = j;
                int y = j+i;
                if(x==y) dp[x][y]=1;
                else if(y-x==1)
                {
                    if(s[x]==s[y])
                    {
                        dp[x][y]=1;
                        ans_x=x;
                        ans_y=y;
                        ans=max(ans, y-x+1);
                    }
                    else dp[x][y]=0;
                }
                else
                {
                    dp[x][y] = dp[x+1][y-1] && (s[x]==s[y]);
                    if(dp[x][y]==1)
                    {
                        if (y-x+1>ans)
                        {
                            ans_x=x;
                            ans_y=y;
                            ans=y-x+1;
                        }
                    }
                }
            }
        }
        return s.substr(ans_x, ans);
    }
};