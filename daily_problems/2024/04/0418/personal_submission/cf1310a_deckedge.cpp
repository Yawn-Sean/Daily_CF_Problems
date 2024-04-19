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

    int n = red(), i, j;
    vector<pi> a(n);
    for (i = 0; i < n; ++i) {
        cin >> a[i].fi;
    }
    for (i = 0; i < n; ++i) {
        cin >> a[i].se;
    }
    sort(a.begin(), a.end());
    int64_t res = 0, s = a[0].se;
    priority_queue<int64_t> q;
    q.emplace(a[0].se);
    for (i = 1; i < n; ++i) {
        if (a[i].fi != a[i - 1].fi) {
            for (j = a[i - 1].fi; j < a[i].fi && !q.empty(); j++) {
                s -= q.top();
                q.pop();
                res += s;
            }
        }
        s += a[i].se;
        q.emplace(a[i].se);

    }
    while (!q.empty()) {
        s -= q.top();
        q.pop();
        res += s;
    }

    cout << res << '\n';
    return 0;
}

/*
https://codeforces.com/problemset/problem/1310/A
*/