#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ll left = 0, right = 1e17;
        while (left < right) {
            ll mid = (left + right) / 2;
            if (mid / x + mid / y >= a[i])
                right = mid;
            else
                left = mid + 1;
        }
        if (left % x == 0 && left % y == 0)
            cout << "Both" << endl;
        else if (left % x == 0)
            cout << "Vova" << endl;
        else
            cout << "Vanya" << endl;
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