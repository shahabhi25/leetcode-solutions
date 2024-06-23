class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int ans=nums[0]>limit?1:0;
        map<int, int> mp;
        
        int l=0;
        int r=0;
        while(r<n)
        {
            mp[nums[r]]++;
            while(l<r && mp.rbegin()->first-mp.begin()->first > limit) 
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};