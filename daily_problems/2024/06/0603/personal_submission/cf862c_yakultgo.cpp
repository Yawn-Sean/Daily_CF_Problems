#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, x;
    cin >> n >> x;
    if (n == 2 && x == 0) {
        cout << "NO" << endl;
    } else if (n == 1) {
        cout << "YES" << endl;
        cout << x << endl;
    } else if (n == 2) {
        cout << "YES" << endl;
        cout << 0 << " " << x << endl;
    } else {
        cout << "YES" << endl;
        int cur = 0;
        for (int i = 1; i <= n - 3; i++) {
            cout << i << " ";
            cur ^= i;
        }
        int k = 1 << 17;
        int j = 1 << 18;
        cout << (cur ^ k) << " " << (k ^ j) << " " << (j ^ x);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}