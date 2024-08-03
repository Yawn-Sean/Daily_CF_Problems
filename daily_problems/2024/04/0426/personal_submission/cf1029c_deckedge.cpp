#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pi pair<int, int>
#define all(x) (x).begin(), (x).end()

inline int red() {
    int x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = red(), i;
    multiset<int> a, b;
    vector<pi> c(n);
    for (i = 0; i < n; i++) {
        cin >> c[i].fi >> c[i].se;
        a.insert(c[i].fi);
        b.insert(c[i].se);
    }

    int res = 0;
    for (i = 0; i < n; i++) {
        a.erase(a.find(c[i].fi));
        b.erase(b.find(c[i].se));
        res = max(res, *b.begin() - *a.rbegin());
        a.insert(c[i].fi);
        b.insert(c[i].se);
    }

    cout << res << '\n';

    return 0;
}

