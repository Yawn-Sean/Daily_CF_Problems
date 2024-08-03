#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef pair<int, int> pii;

int main() {
    int n; scanf("%d", &n);

    unordered_map<int, pii> mp;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        auto &p = mp[x];
        if (p.first == 0) p.first = i;
        p.second = i;
    }

    vector<pii> vec;
    for (auto &p : mp) vec.push_back(p.second);
    sort(vec.begin(), vec.end());

    int cnt = 0, R = 0;
    for (pii p : vec) {
        if (p.first > R) cnt++;
        R = max(R, p.second);
    }

    long long ans = 1;
    for (int i = 1; i < cnt; i++) ans = ans * 2 % MOD;
    printf("%lld\n", ans);
    return 0;
}
