class Solution {
public:
    int factorial(int n)
    {
        if(n==1) return 1;
        return n*factorial(n-1);
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix_sum(n+1);
        prefix_sum[0]=0;
        unordered_map<int, int> mp;
        int ans = 0;
        mp[prefix_sum[0]]++;
        for(int i=0; i<n; i++)
        {
            prefix_sum[i+1] = ((prefix_sum[i]+nums[i])%k +k)%k;
            mp[prefix_sum[i+1]]++;
        }
        
        for(auto i:mp)
        {
            int m=i.second;
            if(m>1)
            {
                ans += (m*(m-1))/2;
            }
        }
        return ans;
    }
};