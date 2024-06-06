class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int, int>> new_nums(n);
        
        for(int i=0; i<n; i++)
        {
            new_nums[i] = make_pair(nums[i], i);
        }
        sort(new_nums.begin(), new_nums.end());
        
        int i=0;
        int j=n-1;
        int ans_1;
        int ans_2;
        while(i<j)
        {
            if(new_nums[i].first+new_nums[j].first==target)
            {
                ans_1=new_nums[i].second;
                ans_2=new_nums[j].second;
            }
            if(new_nums[i].first+new_nums[j].first<target)
                i++;
            // if(new_nums[i].first+new_nums[j].first>target)
            else
                j--;
        }
        return {ans_1, ans_2};
    }
};