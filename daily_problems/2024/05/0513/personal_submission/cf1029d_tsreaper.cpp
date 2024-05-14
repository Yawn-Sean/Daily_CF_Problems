#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n, K, A[MAXN + 10];
long long ans;

unordered_map<int, int, custom_hash> mp[15];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        int len = 0;
        for (int x = A[i]; x; x /= 10) len++;
        mp[len][A[i] % K]++;

        long long h = A[i] % K;
        for (int i = 1; i <= len; i++) h = h * 10 % K;
        h = (h + A[i]) % K;
        if (h == 0) ans--;
    }

    for (int i = 1; i <= n; i++) {
        long long h = A[i] % K;
        for (int len = 1; len <= 10; len++) {
            h = h * 10 % K;
            long long x = (K - h) % K;
            if (mp[len].count(x)) ans += mp[len][x];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
