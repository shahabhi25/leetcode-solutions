class Solution {
public:
    
    int minInsertions(string s) 
    {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int len=0; len<n; len++)
        {
            for(int l=0;l<n-len; l++)
            {
                int r=l+len;
                if(len==0)
                {
                    dp[l][r]=1;
                }
                else if(len==1)
                {
                    if(s[l]==s[r])
                        dp[l][r]=2;
                    else dp[l][r]=1;
                }
                else
                {
                    if(s[l]==s[r])
                        dp[l][r]=2+dp[l+1][r-1];
                    else
                        dp[l][r]=max(dp[l+1][r], dp[l][r-1]);
                }
            }
        }
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return n-dp[0][n-1];
    }
};