#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    int col = -1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) {
            if (abs(a[i] - a[i - 1]) > 1) {
                if (col == -1 || col == abs(a[i] - a[i - 1]))
                    col = abs(a[i] - a[i - 1]);
                else {
                    cout << "NO" << endl;
                    return;
                }
            } else if (abs(a[i] - a[i - 1]) == 0) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    if (col == -1) col = 1e9;
    for (int i = 1; i < n; i++) {
        int x1 = (a[i - 1] - 1) / col, y1 = (a[i - 1] - 1) % col;
        int x2 = (a[i] - 1) / col, y2 = (a[i] - 1) % col;
        if (abs(x1 - x2) + abs(y1 - y2) != 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    cout << int(1e9) << " " << col << endl;
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
