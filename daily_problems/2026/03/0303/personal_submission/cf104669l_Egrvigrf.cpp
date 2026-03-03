#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a,b;
    cin >> a >> b;

    if (b == 2) {
        cout << 1 << '\n';
        return;
    }

    int sum = (a + a + b - 1) * b / 2;
    vector<int> fac;
    for (int i = 2; i * i <= sum; i++) {
        if (sum % i == 0) {
            fac.push_back(i);
            if (i * i != sum) {
                fac.push_back(sum / i);
            }
        }
    }

    sort(fac.begin(),fac.end(),greater<int>());

    for (auto i : fac) {
        bool f = 0;
        for (int j = 1; j < b; j++) {
            int L = (a + a + j - 1) * j / 2;
            int R = (a + b - 1 + a + b - 1 - j + 1) * j / 2;
            if ((L + i - 1) / i * i<= R) {
                f = 1;
                break;
            }
        }
        if (f) {
            cout << i << '\n';
            return;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
       solve();
    }
    return 0;
}