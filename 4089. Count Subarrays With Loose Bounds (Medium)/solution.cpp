class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        int continuous = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]>=minK&&nums[i]<=maxK){
                ans++;
                if(continuous) ans+=continuous;
                continuous++;
            }else continuous = 0;
        }
        return ans;
    }
};