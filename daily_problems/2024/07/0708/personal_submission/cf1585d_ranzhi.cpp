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

class FenWickTree {
public :
    int n;
    vector<int> c;

    FenWickTree(int t) : n(t), c(t + 1) {}

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
};

void solve() { 
    int n; cin >> n;
    vector<int> a(n);
    bitset<500005> vis;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (vis[a[i]]) flag = true;
        vis[a[i]] = 1;
    }
    FenWickTree tr(n + 1);
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        cnt += tr.query(a[i] - 1);
        tr.add(a[i], 1);
    }
    if (cnt % 2 && flag == false) cout << "NO" << endl;
    else cout << "YES" << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
