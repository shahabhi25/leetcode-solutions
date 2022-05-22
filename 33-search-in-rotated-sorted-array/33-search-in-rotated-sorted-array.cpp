class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int l=0;
        int r=n-1;
        
        int ans=-1;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(target==nums[mid])
            {
                ans=mid;
                break;
            }
            if(nums[l]<=nums[mid])
            {
                if(nums[l]<=target && target<nums[mid])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            else
            {
                if(nums[mid]<target && target<=nums[r])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        
        return ans;
        
    }
};