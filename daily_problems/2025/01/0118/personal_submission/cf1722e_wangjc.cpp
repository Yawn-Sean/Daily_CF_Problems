#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    vector<vector<int>> rec(1001, vector<int>(1001));
    auto pre = rec;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        rec[h][w]++;
    }
    for (int i = 0; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            pre[i][j] = pre[i][j - 1] + rec[i][j] * i * j;
        }
    }
    for (int i = 0; i < q; i++) {
        int h1, w1, h2, w2;
        cin >> h1 >> w1 >> h2 >> w2;
        int ans = 0;
        for (int j = h1 + 1; j < h2; j++) {
            ans += pre[j][w2 - 1] - pre[j][w1];
        }
        cout << ans << "\n";
    }

}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
       solve();
    }
    return 0;
}
