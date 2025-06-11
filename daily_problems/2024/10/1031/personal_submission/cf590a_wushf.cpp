#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int N = 5e5 + 5;
int n;
int a[N];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j + 1 <= n && a[j] ^ a[j + 1] == 1) {
            j++;
        }
        ans = max(ans, j - i >> 1);
        int mid = i + j >> 1;
        for (int k = i; k <= mid; k++) {
            a[k] = a[i];
            a[k + mid - i + 1] = a[j];
        }
        i = j;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
}

signed main() {
    IOS;
    solve();
    return 0;
}
