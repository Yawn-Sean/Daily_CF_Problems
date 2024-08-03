#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

const int N = 21, M = 5e4 + 5;
int a[N][M];
int cnt[N];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    Z in = 1;
    for (int j = 1; j <= n; j++)
        in *= j;
    in = in.inv();
    Z ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j][i] >= 2)
                cnt[a[j][i] - 2]++;
        }
        Z cur = 1;
        Z cur_cnt = 0;
        for (int j = n - 1; j >= 0; j--) {
            cur_cnt += cnt[j];
            cur *= cur_cnt;
            cur_cnt -= 1;
        }
        for (int j = 0; j <= n - 1; j++) cnt[j] = 0;
        ans += 1 - cur * in;
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