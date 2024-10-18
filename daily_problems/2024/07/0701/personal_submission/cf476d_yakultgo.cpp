#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    cout << (6 * n - 1) * k << endl;
    for (int i = 1; i <= 6*n; i+=6) {
        cout << i * k << " " << (i + 1) * k << " " << (i + 2) * k << " " << (i + 4) * k << endl;
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