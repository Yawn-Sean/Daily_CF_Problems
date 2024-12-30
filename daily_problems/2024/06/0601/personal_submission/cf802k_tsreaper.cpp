#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

struct Magic {
    int K;
    long long sm;
    multiset<long long> ms1, ms2;

    Magic(int K): K(K), sm(0) {}

    void adjust() {
        while (ms2.size() < K && !ms1.empty()) {
            auto it = prev(ms1.end());
            sm += *it;
            ms2.insert(*it);
            ms1.erase(it);
        }
        while (ms2.size() > K) {
            auto it = ms2.begin();
            sm -= *it;
            ms1.insert(*it);
            ms2.erase(it);
        }
    }

    void insert(long long x) {
        if (!ms1.empty() && x <= *prev(ms1.end())) ms1.insert(x);
        else ms2.insert(x), sm += x;
        adjust();
    }

    void erase(long long x) {
        auto it = ms1.find(x);
        if (it != ms1.end()) ms1.erase(it);
        else ms2.erase(ms2.find(x)), sm -= x;
        adjust();
    }
};

int n, K;

vector<int> e[MAXN + 10], v[MAXN + 10];
long long f[MAXN + 10][2];

void dp(int sn, int fa) {
    Magic magic(K - 1);

    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (fn == fa) continue;
        dp(fn, sn);
        magic.insert(f[fn][0] + v[sn][i]);
    }
    f[sn][0] = magic.sm;

    f[sn][1] = f[sn][0];
    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (fn == fa) continue;
        long long val = f[fn][0] + v[sn][i];
        magic.erase(val);
        f[sn][1] = max(f[sn][1], magic.sm + f[fn][1] + v[sn][i]);
        magic.insert(val);
    }
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i < n; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); v[x].push_back(z);
        e[y].push_back(x); v[y].push_back(z);
    }
    dp(0, -1);
    printf("%lld\n", f[0][1]);
    return 0;
}
