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
    unordered_map<int, int> idx;
    idx[4] = 0, idx[8] = 1, idx[15] = 2, idx[16] = 3, idx[23] = 4, idx[42] = 5;
    int n;
    cin >> n;
    int ans = 0;
    vector<int> vals(6);
    while (n--) {
        int a;
        cin >> a;
        int i = idx[a];
        if (i == 0) vals[i]++;
        else {
            if (vals[i - 1] == 0) {
                ans++;
                continue;
            } else {
                vals[i - 1]--;
                vals[i]++;
            }
        }
    }
    for (int i = 0; i < 5; i++) ans += vals[i] * (i + 1);
    cout << ans << '\n';
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