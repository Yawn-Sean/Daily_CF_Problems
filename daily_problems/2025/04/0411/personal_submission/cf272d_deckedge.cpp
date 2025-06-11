#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
i64 quick(i64 a, i64 b, i64 mod) {
    i64 res = 1;
    a %= mod;
    while (b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n = read();
    vector<int> a(n), b(n);
    generate(all(a), read);
    generate(all(b), read);
    int m = read();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            cnt++;
        }
    }
    vector<pi> c;
    for (int i = 0; i < n; i++) {
        c.emplace_back(a[i], i);
        c.emplace_back(b[i], i);
    }
    sort(all(c));
    int len = c.size();
    vector<i64> s(len + 1, 1), e(len + 1, 0);

    for (int i = 1; i <= len; i++) {
        int cur = i, num = 0;
        while (!(cur & 1)) {
            num++;
            cur >>= 1;
        }
        e[i] = e[i - 1] + num;
        s[i] = (s[i - 1] * cur) % m;
    }
    i64 odd = 1;
    int two = 0, i = 0;
    while (i < len) {
        int j = i;
        while (j < len && c[j].fi == c[i].fi) {
            j++;
        }
        int k = j - i;
        odd = (odd * s[k]) % m;
        two += e[k];
        i = j;
    }
    two -= cnt;
    if (two < 0) {
        cout << "0\n";
        return ;
    }
    i64 res = (quick(2, two, m) * odd) % m;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}