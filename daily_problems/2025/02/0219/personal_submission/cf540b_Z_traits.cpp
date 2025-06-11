#pragma GCC optimize(2)
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
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
#define all(x) x.begin(), x.end()
#define endl '\n'

void solve() { 
    int n, k, p, x, y; cin >> n >> k >> p >> x >> y;
    max_heap<int> left;
    min_heap<int> right;
    vector<int> ans;
    function<void(int)> insert = [&](int x) {
        if (left.size() == right.size()) {
            left.push(x);
            right.push(left.top());
            left.pop();
        } else {
            right.push(x);
            left.push(right.top());
            right.pop();
        }
        return;
    };
    function<double()> get_mid = [&]() -> double {
        if (left.empty() && right.empty()) return 0;
        if (left.size() == right.size()) 
            return (left.top() + right.top()) * 1.0 / 2;
        return right.top();
    };
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        insert(x);
        cnt += x;
    }
    for (int i = 1; i <= n - k; i++) {
        double mid = get_mid();
        if (mid < y) insert(y), cnt += y, ans.emplace_back(y);
        else insert(1), cnt += 1, ans.emplace_back(1);
    }
    if (cnt > x || right.top() < y) cout << -1 << endl;
    else {
        for (auto &x : ans) cout << x << " ";
    }
    cout << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
