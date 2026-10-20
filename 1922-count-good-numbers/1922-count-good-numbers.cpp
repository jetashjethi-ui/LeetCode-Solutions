class Solution {
public:
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long mod = 1e9 + 7;
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;
        
        long long ans1 = power(5, evenCount, mod);
        long long ans2 = power(4, oddCount, mod);
        
        return (ans1 * ans2) % mod;
    }
};