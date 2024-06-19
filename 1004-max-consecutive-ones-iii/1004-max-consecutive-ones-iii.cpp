class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int ans=0;
        int current=0;
        while(r<n)
        {
            current+= nums[r]==0?1:0;
            while(l<=r && current>k)
            {
                current -= nums[l]==0?1:0;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};