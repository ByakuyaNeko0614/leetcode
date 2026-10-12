class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        for(int i = 0; i < n;){
            int mod = nums[i]%k;
            int j = i;
            while(j<n && nums[j]%k==mod) j++;
            int length = j-i;
            for(int len = length; len >= 1; len--){
                if((len-1)*mod%k==0){
                    ans = max(len, ans);
                    break;
                }
            }
            i = j;
        }
        return ans;
    }
};