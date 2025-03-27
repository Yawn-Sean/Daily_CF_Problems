#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        i64 n, m;
        cin >> n >> m;

        if(n == m) {
            cout << "YES\n";
            cout << "1\n1\n";
        } else if (2ll * (n - m + 1) > n) {
            cout << "YES\n";
            cout << 2 << '\n';
            cout << n - m + 1 << ' ' << 1 << '\n';
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
