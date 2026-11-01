class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            map<int, int>mp;
            vector<int> st;
            for(int j = i; j < n; j++){
                if(!mp.count(nums[j])){
                    st.push_back(nums[j]);
                }
                mp[nums[j]]++;
            bool valid = true;
            for(int j = 0; j < st.size(); j++){
                if(mp[st[j]]!=j+1){
                    valid = false;
                    break;
                }
            }
            if(valid) ans++;
        }}
        return ans;
    }
};