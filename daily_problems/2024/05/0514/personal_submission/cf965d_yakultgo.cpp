#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int w, l;
    cin >> w >> l;
    vector<int> a(w);
    for (int i = 1; i < w; i++) {
        cin >> a[i];
    }
    int cur = 0;
    for (int i = 1; i <= l; i++) cur += a[i];
    int ans = cur;
    for (int i = l + 1; i < w; i++) {
        cur += -a[i - l] + a[i];
        ans = min(ans, cur);
    }
    cout << ans << endl;
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