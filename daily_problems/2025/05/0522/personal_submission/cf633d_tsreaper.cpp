#include <bits/stdc++.h>
#define MAXN 1000
#define MAXA ((int) 1e9)
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

int n, ans, A[MAXN + 5];

int zero;
unordered_map<int, int, custom_hash> cnt;

int gao(long long x, long long y) {
    if (x == 0 && y == 0) return zero;

    vector<long long> vec = {x, y};
    for (long long z = x + y; z <= MAXA && z >= -MAXA; x = y, y = z, z = x + y) vec.push_back(z);
    int ret = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (cnt.count(vec[i]) == 0 || cnt[vec[i]] == 0) break;
        cnt[vec[i]]--;
        ret++;
    }
    for (int i = 0; i < ret; i++) cnt[vec[i]]++;
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if (A[i] == 0) zero++;
        cnt[A[i]]++;
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        if (i != j) ans = max(ans, gao(A[i], A[j]));
    printf("%d\n", ans);
    return 0;
}
