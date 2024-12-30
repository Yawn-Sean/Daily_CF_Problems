#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
    	cin >> p[i];
    }

    vector<long long> d1(2 * n + 1), d2(2 * n + 1);

    for (int i = 0; i < n; i ++) {
        int l = n + p[i] - 1 - i, r = 2 * n - 1 - i;
        d2[l] ++, d2[r+1] --;
        d1[l] -= l, d1[r+1] += l;
    }

    for (int i = 0; i < 2 * n; i ++)
        d2[i+1] += d2[i], d1[i+1] += d1[i];

    vector<ll> c(n);
    for (int i = 0; i < 2 * n; i ++)
        c[i % n] += 1ll * d2[i] * i + d1[i];

    long long mn = 1e18;
    int id = -1;
    for (int i = 0; i < n; ++i) {
        if (c[i] < mn) {
            mn = c[i];
            id = i;
        }
    }
    cout << mn * 2 << ' ' << id << '\n';

    return 0;
}
