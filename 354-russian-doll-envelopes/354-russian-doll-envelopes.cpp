bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
}
class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& a) 
    {
        int n=a.size();
        sort(a.begin(), a.end(), cmp);
        
        int INF=1e9;
        vector<int> d(n+1, INF);
        d[0]=-INF;
        
        for(int i=0; i<n; i++)
        {
            int j=upper_bound(d.begin(), d.end(), a[i][1])-d.begin();
            
            if(d[j-1]<a[i][1] && d[j]>a[i][1])
            {
                d[j]=a[i][1];
            }
        }
        
        int ans=1;
        for(int i=1; i<=n; i++)
        {
            if(d[i]<INF) ans=i;
        }
        return ans;
    }
};