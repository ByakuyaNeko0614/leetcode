class Solution {
public:
    int minRotations(int n, string s) {
        int ans = 0,sum = 0;
        s = '0' + s;
        n++;
        for(int i = 1; i < n; i++){
            sum += min(abs(s[i] - '0' - (s[i-1]-'0')), 10 - abs(s[i]- '0' -(s[i-1] - '0')));
        }
        ans = sum;
        for(int i = n-2; i > 0; i--){
            int a = min(ans, sum - min(abs(s[i] - '0' - (s[i-1] - '0')), 10 - abs(s[i] - '0' - (s[i-1] - '0')));
            int b = min(abs(s[n-1] - '0' - (s[i-1] - '0')), 10 - abs(s[n-1] - '0' - (s[i-1] - '0'))));
            ans = a + b;
        }
        return ans;
    }
};