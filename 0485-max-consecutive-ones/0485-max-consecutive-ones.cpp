class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        for(int i=1; i<n; i++)
        {
            if(nums[i]==1) nums[i] = nums[i]+nums[i-1];
            
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};