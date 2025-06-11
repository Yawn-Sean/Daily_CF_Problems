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

void solve() { 
    int n; cin >> n;
    string c, a; cin >> c >> a;
    vector<vector<int>> num(3);
    int cnt = 0;
    for (int i = 0; i < c.size(); i++) {
        cnt += c[i] - '0';
        num[c[i] - '0' + a[i] - '0'].emplace_back(i + 1);
    }
    for (int i2 = 0; i2 <= num[2].size(); i2++) {
        int i1 = cnt - i2 * 2, i0 = n / 2 - i1 - i2;
        if (i1 >= 0 && i1 <= num[1].size() && i0 >= 0 && i0 <= num[0].size()) {
            for (int i = i0; i < num[0].size(); i++) cout << num[0][i] << " ";
            for (int i = i1; i < num[1].size(); i++) cout << num[1][i] << " ";
            for (int i = i2; i < num[2].size(); i++) cout << num[2][i] << " ";
            cout << endl;
            return ;
        }
    }
    cout << -1 << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
