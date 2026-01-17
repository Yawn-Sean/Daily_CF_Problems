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
    int n;
    cin >> n;
    int add_mx = INT_MIN, add_mn = INT_MAX, minus_mx = INT_MIN, minus_mn = INT_MAX;
    while (n--) {
        int x, y;
        cin >> x >> y;
        add_mx = max(add_mx, x + y);
        add_mn = min(add_mn, x + y);
        minus_mx = max(minus_mx, x - y);
        minus_mn = min(minus_mn, x - y);
    }
    if (add_mx == add_mn && minus_mx == minus_mn) {
        cout << 4 << '\n';
    } else if (add_mx == add_mn || minus_mx == minus_mn) {
        cout << add_mx - add_mn + minus_mx - minus_mn + 5 << '\n'; 
    } else {
        cout << add_mx - add_mn + minus_mx - minus_mn + 4 << '\n';
    }
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