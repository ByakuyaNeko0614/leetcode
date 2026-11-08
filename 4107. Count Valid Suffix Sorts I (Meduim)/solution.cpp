class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int count1[100010]={0};
        int count2[100010]={0};
        int ans = 0;
        int first = -1;
        for(int i = 0; i < n; i++){
            if(nums[i]!=target[i]){
                if(first==-1) first=i;
                count1[nums[i]]++;
                count2[target[i]]++;
            }
        }
        for(int i = 0; i < 100010; i++){
            if(count1[i]!=count2[i]) return ans;
        }
        bool isValid = true;
        for(int i = n-1; i >=0; i--){
            if(i<n-1&&target[i]<target[i+1]){
                isValid=false;
                break;
            }
            if(isValid&&(first>=i||first==-1)) ans++;
        }
        return ans;
    }
};