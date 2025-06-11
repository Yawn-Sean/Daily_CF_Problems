#include <bits/stdc++.h>
#define MAXM ((int) 1e6)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, m;
long long ans;

int bCnt;
vector<int> bel[MAXM + 10];
long long fac[MAXM + 10];

int main() {
    scanf("%d%d", &n, &m);
    fac[0] = 1;
    for (int i = 1; i <= m; i++) fac[i] = fac[i - 1] * i % MOD;

    for (int i = 1; i <= n; i++) {
        int t; scanf("%d", &t);
        unordered_map<int, int> cnt;
        while (t--) {
            int x; scanf("%d", &x);
            cnt[x]++;
        }
        unordered_map<int, vector<int>> mp;
        for (auto &p : cnt) mp[p.second].push_back(p.first);
        for (auto &p : mp) {
            bCnt++;
            for (int x : p.second) bel[x].push_back(bCnt);
        }
    }

    map<vector<int>, int> mp;
    for (int i = 1; i <= m; i++) mp[bel[i]]++;
    ans = 1;
    for (auto &p : mp) ans = ans * fac[p.second] % MOD;
    printf("%lld\n", ans);
    return 0;
}
