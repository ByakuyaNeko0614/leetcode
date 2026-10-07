class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int ans = 0;
        int leftMax = 0;
        int rightMax = 0;
        while(start < end){
            leftMax = max(leftMax, height[start]);
            rightMax = max(rightMax, height[end]);
            if(leftMax < rightMax){
                ans += leftMax - height[start];
                start++;
            } else {
                ans += rightMax - height[end];
                end--;
            }
        }
        return ans;
    }
};