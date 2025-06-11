#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int D, n, m; scanf("%d%d%d", &D, &n, &m);

    vector<pii> vec;
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        vec.push_back({x, y});
    }
    vec.push_back({0, 0});
    vec.push_back({D, 0});
    sort(vec.begin(), vec.end());

    long long ans = 0;
    int now = n, tot = 0;
    multiset<pii> st;
    for (int i = 1; i < vec.size(); i++) {
        now -= vec[i].first - vec[i - 1].first;
        while (now < 0) {
            if (st.empty()) { printf("-1\n"); return 0; }
            pii p = *st.begin(); st.erase(st.begin());
            int t = min(-now, p.second);
            ans += 1LL * t * p.first;
            now += t; p.second -= t; tot -= t;
            if (p.second > 0) st.insert(p);
        }
        int v = 0;
        while (!st.empty()) {
            pii p = *prev(st.end());
            if (p.first < vec[i].second) break;
            v += p.second;
            st.erase(prev(st.end()));
        }
        v += (n - now) - tot;
        if (v > 0) st.insert({vec[i].second, v});
        assert(tot <= n - now);
        tot = n - now;
    }
    printf("%lld\n", ans);
    return 0;
}
