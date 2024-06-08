class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if (n<2) return false;
        vector<int> pre_sum(n+1);
        unordered_set<int> seen;
        int temp_sum;
        pre_sum[0]=0;
        // seen.insert(pre_sum[0]);
        temp_sum = pre_sum[0];
        for(int i=0; i<n; i++)
        {
            pre_sum[i+1] = (pre_sum[i] + nums[i])%k;
            if(seen.find(pre_sum[i+1])!=seen.end()) return true;
            seen.insert(temp_sum);
            temp_sum=pre_sum[i+1];
        }
        
        return false;
    }
};


// (si-sj)%6==0
    
//     35-