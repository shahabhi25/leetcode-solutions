class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int days)
    {
        int temp=0;
        int n=bloomDay.size();
        for(int i=0; i<n; i++)
        {
            if(bloomDay[i]<=days) temp++;
            else temp=0;
            
            if(temp==k) 
            {
                m--;
                temp=0;
            }
        }
        return m<=0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=0;
        int r=1e9;
        int ans=1e9 +1; 
        
        while(l<=r)
        {
            // cout<<l<<" "<<r<<"\n";
            int mid = l + (r-l)/2;
            if(canMake(bloomDay, m, k, mid))
            {
                ans = min(ans, mid);
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        if(ans== 1e9+1) return -1;
        return ans;
    }
};