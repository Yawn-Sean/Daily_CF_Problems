#include <algorithm>
#include <bit>
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <stack>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <numbers>
#include <cmath>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int N = 1e5;
const int MOD = 1e9 + 7;

ll query(int l, int r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    ll x; cin >> x;
    if (x == -1) exit(0);
    return x;
}

void report(ll m) {
    cout << "! " << m << '\n';
    cout.flush();
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector lists(n, vector<int>(m));
    for (auto& x : lists) for (auto& y : x) cin >> y;
    if (n % 2 == 0) {
        vector<int> visited(n * m / 2 + 1);
        for (auto& x : lists) {
            if (visited[x[0]]) continue;
            for (auto& y : x) cout << y << ' ';
            visited[x[0]] = 1;
        }
    } else {
        vector<int> next_pos(n * m / 2 + 1), idxs(n * m / 2 + 1);
        for (int i = 0; i < n; i++) {
            next_pos[lists[i][0]] = lists[i][m / 2];
            idxs[lists[i][0]] = i;
        }
        int cur = lists[0][0];
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m / 2; k++) {
                cout << lists[idxs[cur]][k] << ' ';
            }
            cur = next_pos[cur];
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}