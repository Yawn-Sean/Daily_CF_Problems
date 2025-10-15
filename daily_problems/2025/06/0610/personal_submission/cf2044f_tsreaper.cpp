#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXX ((int) 2e5)
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

int n, m, q, A[MAXN + 5], B[MAXN + 5];

vector<int> fac[MAXX + 5];
unordered_set<long long, custom_hash> sta, stb;

bool check(int x) {
    for (int y : fac[abs(x)]) for (int k = -1; k <= 1; k += 2)
        if (sta.count(y * k) && stb.count(x / (y * k))) return true;
    return false;
}

int main() {
    for (int i = 1; i <= MAXX; i++) for (int j = i; j <= MAXX; j += i) fac[j].push_back(i);

    scanf("%d%d%d", &n, &m, &q);
    long long sa = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), sa += A[i];
    for (int i = 1; i <= n; i++) sta.insert(sa - A[i]);
    long long sb = 0;
    for (int i = 1; i <= m; i++) scanf("%d", &B[i]), sb += B[i];
    for (int i = 1; i <= m; i++) stb.insert(sb - B[i]);

    unordered_map<int, bool, custom_hash> ans;
    while (q--) {
        int x; scanf("%d", &x);
        if (ans.count(x) == 0) {
            if (x == 0) ans[0] = sta.count(0) || stb.count(0);
            else ans[x] = check(x);
        }
        if (ans[x]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
