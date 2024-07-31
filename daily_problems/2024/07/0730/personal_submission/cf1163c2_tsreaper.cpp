#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef pair<int, int> pii;

int n, X[MAXN + 10], Y[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &X[i], &Y[i]);
    
    set<array<int, 4>> st;
    for (int i = 1; i <= n; i++) {
        map<pii, pii> mp;
        for (int j = 1; j <= n; j++) if (i != j) {
            int dx = X[i] - X[j], dy = Y[i] - Y[j];
            bool neg = (dx * dy < 0);
            dx = abs(dx); dy = abs(dy);
            int g = gcd(dx, dy);
            dx /= g; dy /= g;
            pii p = (neg ? pii(-dx, dy) : pii(dx, dy));
            if (mp.count(p)) mp[p] = max({mp[p], {X[i], Y[i]}, {X[j], Y[j]}});
            else mp[p] = max(pii(X[i], Y[i]), pii(X[j], Y[j]));
        }
        for (auto &p : mp) st.insert({p.first.first, p.first.second, p.second.first, p.second.second});
    }

    int tot = st.size();
    long long ans = 1LL * tot * (tot - 1) / 2;
    map<pii, int> mp;
    for (auto &arr : st) mp[{arr[0], arr[1]}]++;
    for (auto &p : mp) ans -= 1LL * p.second * (p.second - 1) / 2;
    printf("%lld\n", ans);
    return 0;
}
