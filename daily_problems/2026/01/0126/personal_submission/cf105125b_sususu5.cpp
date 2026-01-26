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
    int total = 0;
    priority_queue<pii> others;
    vector<int> ones;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        total += val;
        if (val == 1) ones.push_back(i + 1);
        else if (val > 1) others.emplace(val, i + 1);
    }
    if (total % 2 == 0) {
        cout << "NO\n";
        return;
    }
    vector<int> ans;
    int flag = 1;
    while (total--) {
        int idx = -1;
        if (flag) {
            if (!ones.empty()) {
                idx = ones.back();
                ones.pop_back();
            } else {
                if (!others.empty()) {
                    auto [val, i] = others.top(); others.pop();
                    idx = i;
                    --val;
                    if (val > 1) others.emplace(val, i);
                    else ones.push_back(i);
                }
            }
        } else {
            if (!others.empty()) {
                auto [val, i] = others.top(); others.pop();
                idx = i;
                --val;
                if (val > 1) others.emplace(val, i);
                else ones.push_back(i);
            }
        }
        if (idx == -1) {
            cout << "NO\n";
            return;
        }
        ans.push_back(idx);
        flag ^= 1;
    }
    cout << "YES\n";
    for (int val : ans) cout << val << ' ';
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