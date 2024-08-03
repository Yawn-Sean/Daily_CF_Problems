#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <functional>
#include <cmath>
#include <cstring>
#include <cassert>
#include <climits>

using namespace std;
using i64 = long long;
#define IOS std::ios::sync_with_stdio(false);std::cin.tie(nullptr);

const int maxn = 1E5 + 5;
int f[maxn];
map<int, int> stable;
int g[maxn], h[maxn], cnt;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> f[i];
    for (int i = 1; i <= n; i++) {
        if (f[f[i]] == f[i]) {
            if (stable.count(f[i])) continue;
            else stable[f[i]] = ++cnt;
        }
        else {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++) g[i] = stable[f[i]];
    for (auto [k, v] : stable) h[v] = k;
    cout << cnt << '\n';
    for (int i = 1; i <= n; i++) cout << g[i] << (i == n ? '\n' : ' ');
    for (int i = 1; i <= cnt; i++) cout << h[i] << (i == cnt ? '\n' : ' ');
}

int main() {
    IOS;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}