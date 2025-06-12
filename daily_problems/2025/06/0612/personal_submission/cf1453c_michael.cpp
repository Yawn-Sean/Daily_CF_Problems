#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define eb emplace_back
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

const int INF = INT_MAX / 2;
int t;

void solve() {
    int n; cin >> n;
    vector<vector<int>> d(n + 1, vector<int>(n + 1));
    vector<int> mini(10, INT_MAX), maxi(10, -INT_MAX), minj(10, INT_MAX), maxj(10, -INT_MAX);
    for (int i = 1; i <= n; i ++ ) {
        string tmp; cin >> tmp;
        for (int j = 1; j <= n; j ++ ) {
            int v = tmp[j - 1] - '0';
            d[i][j] = v;
            mini[v] = min(mini[v], i), maxi[v] = max(maxi[v], i);
            minj[v] = min(minj[v], j), maxj[v] = max(maxj[v], j);
        }
    }

    vector<int> res(10, 0);
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            int v = d[i][j], base, height;
            // case1: horizontal base
            base = max(j - 1, n - j), height = max(i - mini[v], maxi[v] - i);
            res[v] = max(res[v], base * height);
            // case2: vertical base
            base = max(i - 1, n - i), height = max(j - minj[v], maxj[v] - j);
            res[v] = max(res[v], base * height);
        }
    }

    for (auto r : res) cout << r << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t -- ) solve();
    return 0;
}
