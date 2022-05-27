class Solution {
public:
    void solve(vector<int> t, vector<int> used, vector<vector<int>> &ans, vector<int> nums)
    {
        int n=nums.size();
        if(t.size()==n)
        {
            ans.push_back(t);
            return;
        }
        for(int i=0; i<n; i++)
        {
            if(!used[i])
            {
                used[i]=1;
                t.push_back(nums[i]);
                solve(t, used, ans, nums);
                t.pop_back();
                used[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> ans;        
        vector<int> used(n, 0);
        
        vector<int> t;
        
        solve(t, used, ans, nums);
        return ans;
        
    }
};