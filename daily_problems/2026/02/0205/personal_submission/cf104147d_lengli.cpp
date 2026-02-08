#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k % 2 == 1) {
        if (n % 2 == 1) {
            cout << "Omda\n"; 
        } else {
            cout << "Teemo\n";
        }
    } else {
        long long r = 1LL * n * k % (k + 1);
        if ((r % 2 == 1) || (r == k)) {
            cout << "Omda\n";
        } else {
            cout << "Teemo\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("dotak.in","r",stdin);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
