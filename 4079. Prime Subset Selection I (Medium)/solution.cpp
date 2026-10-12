class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        if (n < 2 || s < 2)
            return {};
        vector<bool> prime(n + 1, true);
        prime[0] = false, prime[1] = false;
        for (int i = 2; i*i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j+=i) {
                    prime[j] = false;
                }
            }
        }
        vector<int> ans;
        int sum = 0;
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                if (sum + i > s)
                    break;
                sum += i;
                ans.push_back(i);
            }
        }
        return ans;
    }
};