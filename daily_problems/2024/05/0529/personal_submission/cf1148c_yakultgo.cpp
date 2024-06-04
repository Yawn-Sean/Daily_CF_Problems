#include <bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> invp;

vector<pair<int, int> > ans;

void sw(int a, int b) {
    ans.emplace_back(a, b);
    swap(p[a], p[b]);
    swap(invp[p[a]], invp[p[b]]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    p.resize(n);
    invp.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        invp[p[i]] = i;
    }
    for (int i = n / 2 - 1; i > 0; i--) {
        int loc = invp[i];
        if (loc < n / 2) {
            sw(loc, n - 1);
            sw(n - 1, i);
        } else {
            sw(loc, 0);
            sw(0, n - 1);
            sw(n - 1, i);
        }
        loc = invp[n - 1 - i];
        if (loc < n / 2) {
            sw(loc, n - 1);
            sw(0, n - 1);
            sw(0, n - 1 - i);
        } else {
            sw(loc, 0);
            sw(0, n - 1 - i);
        }
    }
    if (p[0] != 0) {
        sw(0, n - 1);
    }
    for (int i = 0; i < n; i++) {
        assert(p[i] == i);
    }
    cout << (int)ans.size() << '\n';
    for (pair<int, int> x : ans) {
        cout << x.first + 1 << " " << x.second + 1 << '\n';
    }
}