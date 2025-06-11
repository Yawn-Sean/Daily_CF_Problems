#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red();
    ve<int> a(n), b(n), d(n);
    iota(all(d), 0);
    rep(i, 0, n) {
        cin >> a[i] >> b[i];
    }
    sort(all(d), [&](int i, int j) {
        return a[i] - b[i] > a[j] - b[j];
    });
    int64_t res = 0;
    rep(i, 0, n) {
        int pos = d[i];
        res += (int64_t)a[pos] * i + (int64_t)b[pos] * (n - i - 1);
    }
    cout << res << '\n';
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
https://codeforces.com/problemset/problem/1151/D
*/
