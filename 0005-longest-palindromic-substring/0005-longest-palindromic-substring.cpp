class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0) return "";
        vector<vector<int>> dp(n, vector<int>(n));
        string ans="";
        ans+=s[0];
        int largest_palindrome=1;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n-i; j++)
            {
                int x=j;
                int y=j+i;
                if(x==y) dp[x][y]=1;
                else if(y-x==1) 
                {
                    dp[x][y] = (s[x]==s[y])?1:0;
                }
                else
                {
                    dp[x][y] = dp[x+1][y-1] && (s[x]==s[y]);
                }
                if(dp[x][y]==1 && (y-x+1)>largest_palindrome)
                {
                    largest_palindrome = (y-x+1);
                    ans = s.substr(x, largest_palindrome);
                }
            }
        }
        return ans;
    }
};
