bool cmp(vector<int> &a, vector<int> &b)
{
    if(a[1]==b[1]) return a[0]<b[0];
    return a[1]<b[1];
}
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        if(k>n) return 0;
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<int>> arr;
        
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n-i; j++)
            {
                int x=j;
                int y=i+j;
                if(x==y) dp[x][y]=1;
                else if(y-x==1) dp[x][y] = s[x]==s[y]?1:0;
                else
                {
                    dp[x][y] = dp[x+1][y-1] && (s[x]==s[y]);
                }
                
                if(dp[x][y]==1 && (y-x+1==k || y-x+1==k+1) )
                {
                    arr.push_back({x,y});
                }
            }
        }
        sort(arr.begin(), arr.end(), cmp);
        int extra=0;
        int end=INT_MIN;
        for(auto i:arr)
        {
            if(end<i[0]) end=i[1];
            else extra++;
        }
        return arr.size()-extra;
    }
};