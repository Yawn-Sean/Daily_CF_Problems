#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

void solve() { 
    int l, r, x, y; cin >> l >> r >> x >> y;
    if (y % x != 0) return (void)(cout << 0 << endl);
    y /= x;
    int ans = 0;
    for (int a = 1; a <= y / a; a++) {
        if (y % a != 0) continue;
        int b = y / a;
        if (__gcd(a, b) == 1 && a * x >= l && a * x <= r && b * x >= l && b * x <= r) {
            ans += 1;
            if (a != b) ans += 1;
        }
    }
    cout << ans << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
