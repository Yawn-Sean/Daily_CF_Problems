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

bool check(int &x, int &y, int &diff) {
    int a = x - 1;
    int b = x + 1;
    int c = x + diff;
    int d = x - diff;
    if (x % diff == 0) b = -1;
    if (x >= 1 && x <= diff) d = -1;
    if (x % diff == 1) a = -1;
    return a == y || b == y || c == y || d == y;
}

void solve() { 
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int diff = 1;
    for (int i = 1; i < n; i++) diff = max(diff, abs(arr[i] - arr[i - 1]));
    for (int i = 1; i < n; i++) {
        if (check(arr[i - 1], arr[i], diff)) continue;
        return (void)(cout << "NO" << endl);
    }
    cout << "YES" << endl;
    cout << (int)1e9 << " " << diff << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
