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
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

class FenwickTree {
public :
    int n;
    vector<int> c;

    FenwickTree(int t) : n(t), c(t + 1) {}

    int lowbit(int x) {
        return x & -x;
    }

    void add(int i, int x) {
        while (i <= n) c[i] += x, i += lowbit(i);
        return;
    }

    int query(int i) {
        int sum = 0;
        while (i) sum += c[i], i -= lowbit(i);
        return sum;
    }

    int get_pre(int x) {
        return query(x - 1);
    }

    int get_back(int x) {
        return query(n) - query(x);
    }
};

void solve() { 
    int n; cin >> n;
    vector<int> arr(n), temp(n);
    for (int i = 0; i < n; i++) cin >> arr[i], temp[i] = arr[i];
    sort(temp.begin(), temp.end());
    map<int, int> mp;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (mp.count(temp[i])) continue;
        mp[temp[i]] = cnt++;
    }
    FenwickTree tr(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) arr[i] = mp[arr[i]];
    for (auto &x : arr) {
        ans += min(tr.get_pre(x), tr.get_back(x));
        tr.add(x, 1);
    }
    cout << ans << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
