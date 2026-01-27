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

vector<int> digits ={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
vector<int> ans(22, 1000);

void solve() {
    int n;
    cin >> n;
    if (n <= 21) {
        cout << ans[n] << '\n';
        return;
    }
    int prefix = (n - 15) % 7 + 15;
    cout << ans[prefix] << string((n - prefix) / 7, '8') << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 10; i++) {
        ans[digits[i]] = min(ans[digits[i]], i);
    }
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int val = digits[i] + digits[j];
            ans[val] = min(ans[val], 10 * i + j);
        }
    }
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                int val = digits[i] + digits[j] + digits[k];
                ans[val] = min(ans[val], 100 * i + 10 * j + k);
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}