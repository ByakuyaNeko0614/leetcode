class Solution {
public:
    int minRotations(int n, string s) {
        int ans = 0;
        char start = '0';
        for (auto& i : s) {
            int dist = abs(i - start);
            ans += min(dist, 10 - dist);
            start = i;
        }
        int stock = ans;
        for (int i = 0; i < n; i++) {
            int old = abs(s[i] - (i == 0 ? '0' : s[i - 1]));
            int now = abs(s[n - 1] - (i == 0 ? '0' : s[i - 1]));
            old = min(old, 10 - old);
            now = min(now, 10 - now);
            ans = min(ans, stock - old + now);
        }

        return ans;
    }
};