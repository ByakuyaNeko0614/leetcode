class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        vector<int> re;
        vector<long long> pre(n+1, 0);
        for(int i = 0; i < n; i++) pre[i+1]=pre[i]+nums[i];
        for(int i = 0; i < n; i++){
            string s = to_string(nums[i]);
            sort(s.begin(), s.end(), greater<char>());
            int xx = stoi(s);
            re.push_back(xx-nums[i]);
            ans+=nums[i];
        }
        /*int x = sort(nums[i].begin(), nums[i].end(), greater<int>());//to string?*/
        sort(re.begin(), re.end(), greater<int>());
        /*vector<long long> pre2(n+1, 0);
        for(int i = 0; i < n; i++) pre2[i+1]=pre2[i]+re[i];*/
        /*long long ans = pre[n-k]+pre[k];
        cout << pre[n-k] <<" "<< pre[k];*/
        for(int i = 0; i < min(n, k); i++){
            ans+=re[i];
        }
        return ans;
    }
};