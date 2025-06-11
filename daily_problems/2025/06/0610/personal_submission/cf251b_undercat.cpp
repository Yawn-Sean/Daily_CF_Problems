#include <bits/stdc++.h>
using namespace std;

void solve() {
    // 1 p_{i}=p_{qi}
    // 2 t_{qi}=p_{i}
    int n, k;
    cin >> n >> k;
    vector<int> q(n), res(n), p[2 * k + 1];
    for (auto &i : q) cin >> i, i--;
    for (auto &j : res) cin >> j, j--;
    for (int i = 0; i <= 2 * k; i++) p[i].resize(n);
    iota(p[k].begin(), p[k].end(), 0);
    int flag = 1;
    if (p[k] == res) {
        cout << "NO";
        return;
    }
    vector<int> temp;
    for (int i = k + 1; i <= k * 2; i++) {
        for (int j = 0; j < n; j++) {
            p[i][j] = p[i - 1][q[j]];
        }
        if (p[i] == res) {
            temp.push_back(i);
            break;
        }
    }
    for (int i = k - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            p[i][q[j]] = p[i + 1][j];
        }
        if (p[i] == res) {
            temp.push_back(i);
            break;
        }
    }
    if (temp.size()) {
        if (temp.size() == 1 && (k - abs(k - temp[0])) % 2 == 0) {
            flag = 0;
        } else if (temp.size() == 2) {
            if (((k - abs(k - temp[0])) % 2 == 0 ||
                 (k - abs(k - temp[1])) % 2 == 0) &&
                !(temp[0] == temp[1] + 2 && k > 1))
                flag = 0;
        }
    }
    if (flag)
        cout << "NO";
    else
        cout << "YES";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}