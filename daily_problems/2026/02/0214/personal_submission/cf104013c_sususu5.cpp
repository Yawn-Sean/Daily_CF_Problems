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

string query(int l, int r) {
    cout << l << ' ' << r << '\n';
    cout.flush();
    string x; cin >> x;
    if (x == "WIN") exit(0);
    return x;
}

void report(ll m) {
    cout << "! " << m << '\n';
    cout.flush();
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 2; j <= n; j++) query(j - 1, j);
        for (int j = n; j >= 2; j--) query(j - 1, j);
    }
    return;
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