#include <iostream>
#include <vector>
#include <algorithm>

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, 998244353 - 2);
}


void main_func() {
    long long n, p, q;
    std::cin >> n >> p >> q;
    long long mod = 998244353;
    
    long long q_inv = modInverse(q);
    long long prob = (p * q_inv) % mod;
    
    long long dp = 1;
    long long val = prob;
    long long cur = 1;
    
    for (int i = 2; i <= n; ++i) {
        dp = (dp * cur) % mod;
        val = (val * prob) % mod;
        long long one_minus_prob = (1 - prob + mod) % mod;
        cur = ((cur * one_minus_prob) % mod + val) % mod;
    }
    
    std::cout << dp << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    main_func();
    return 0;
}
