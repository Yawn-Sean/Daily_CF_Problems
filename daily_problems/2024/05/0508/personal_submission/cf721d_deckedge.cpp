#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
using pi = pair<int64_t, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), k = red(), x = red(), pos;
    int64_t mn = 2e9;
    vector<int64_t> a(n);
    priority_queue<pi, vector<pi>, greater<pi>> q;
    generate(all(a), red);
    bool ok = false;
    rep(i, 0, n) {
        if (a[i] < 0) {
            ok ^= true;
        }
        if (abs(a[i]) < mn) {
            mn = abs(a[i]);
            pos = i;
        }
    }
    if (!ok) {
        if (a[pos] >= 0) {
            while (a[pos] >= 0 && k) {
                a[pos] -= x;
                k--;
            } 
        } else {
            while (a[pos] < 0 && k) {
                a[pos] += x;
                k--;
            }
        }
    }
    rep(i, 0, n) {
        q.emplace(abs(a[i]), i);
    }
    while (k--) {
        auto t = q.top();
        q.pop();
        int idx = t.se;
        if (a[idx] >= 0) {
            a[idx] += x;
        } else {
            a[idx] -= x;
        }
        q.emplace(abs(a[idx]), idx);
    }
    rep(i, 0, n) {
        cout << a[i] << " \n"[i == n - 1];
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

/*
https://codeforces.com/problemset/problem/1102/E
*/
