#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    map<int, int> last_idx;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        last_idx[a[i]] = i;
    }
    for (int i = 0, j = 0; i < n; i++) {
        j = max(j, last_idx[a[i]]);
        if (i == j) ans = (ans == 0 ? 1 : ans * 2 % mod);
    }
    cout << ans << endl;
    return 0;
}
