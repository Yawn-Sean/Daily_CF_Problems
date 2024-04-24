#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define INF ((ll) 1e18)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int n;
ll X[MAXN], Y[MAXN];

ll cross(ll x, ll y, array<ll, 4> line) {
    ll x1 = line[1] - line[0], y1 = line[3] - line[2];
    ll x2 = x - line[0], y2 = y - line[2];
    return x1 * y2 - x2 * y1;
}

int main() {
    scanf("%d", &n);
    ll mn = INF, mx = -INF;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &X[i], &Y[i]);
        mn = min(mn, X[i]);
        mx = max(mx, X[i]);
    }

    vector<array<ll, 4>> vec1, vec2;
    for (int i = 0; i < n; i++) {
        pll p = pll(X[i], Y[i]);
        pll q = pll(X[(i + 1) % n], Y[(i + 1) % n]);
        if (p < q) vec1.push_back({p.first, q.first, p.second, q.second});
        else vec2.push_back({q.first, p.first, q.second, p.second});
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    int m; scanf("%d", &m);
    while (m--) {
        ll x, y; scanf("%lld%lld", &x, &y);
        if (x <= mn || x >= mx) { printf("NO\n"); return 0; }
        auto it1 = upper_bound(vec1.begin(), vec1.end(), array<ll, 4>({x, INF, INF, INF}));
        auto it2 = upper_bound(vec2.begin(), vec2.end(), array<ll, 4>({x, INF, INF, INF}));
        ll c1 = cross(x, y, *prev(it1)), c2 = cross(x, y, *prev(it2));
        if (c1 <= 0 && c2 <= 0) { printf("NO\n"); return 0; }
        if (c1 >= 0 && c2 >= 0) { printf("NO\n"); return 0; }
    }
    printf("YES\n");
    return 0;
}
