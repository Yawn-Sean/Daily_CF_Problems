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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> cnt(N + 1);
    while (n--) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    vector<vector<int>> factor(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            factor[j].push_back(i);
        }
    }

    ll ans = 0;
    for (int i = x; i <= y; i++) {
        ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
        for (int j = 0; j < factor[i].size(); j++) {
            for (int k = 0; k < j; k++) {
                int g = gcd(factor[i][j], factor[i][k]);
                if (x <= g && 1LL * factor[i][j] * factor[i][k] / g == i) {
                    ans += 1LL * cnt[factor[i][j]] * cnt[factor[i][k]]; 
                }
            }
        }
    }
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