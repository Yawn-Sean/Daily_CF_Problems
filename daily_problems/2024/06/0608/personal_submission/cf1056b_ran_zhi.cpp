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
    int n, m; cin >> n >> m;
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        int c1 = (n + m - i) / m;
        for (int j = 1; j <= m; j++) {
            int c2 = (n + m - j) / m;
            if ((i * i + j * j) % m == 0) ans += (ll)c1 * c2;
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
