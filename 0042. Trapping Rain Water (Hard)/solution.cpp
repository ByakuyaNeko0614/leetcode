class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int ans = 0;
        int left = 0;
        int right = 0;
        while(start < end){
            left = max(left, height[start]);
            right = max(right, height[end]);
            if(left < right){
                ans += left - height[start];
                start++;
            } else {
                ans += right - height[end];
                end--;
            }
        }
        return ans;
    }
};