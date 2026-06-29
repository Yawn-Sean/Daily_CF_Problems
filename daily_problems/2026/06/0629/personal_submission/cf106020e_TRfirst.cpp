#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;



void solve(){
    int n;
    cin >> n;
    vector<int> nums(n + 5);
    for (int i = 1; i <= n; i++) cin >> nums[i];
    vector<vector<int>> ring(n + 5);
    vector<int> vis(n + 5);
    int now;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        cnt++;
        now = i;
        while (!vis[now]) {
            vis[now] = 1;
            ring[cnt].push_back(now);
            now = nums[now];
        }
    }
    ll ans = 0;
    vector<ll> ji; 
    for (int i = 1; i <= cnt; i++) {
        int len = ring[i].size();
        if (len & 1) {
            ll res = 0;
            ll sum = 0;
            for (int j = 1; j < len; j++) {
                if (j & 1) sum += ring[i][j];
                else sum -= ring[i][j];
            }
            for (int j = 0; j < len; j++) {
                if (j & 1) {
                    res = max(res, ring[i][j] + sum);
                    sum += ring[i][(j + 1) % len];
                    sum -= ring[i][j];
                }
                else {
                    res = max(res, ring[i][j] - sum);
                    sum -= ring[i][(j + 1) % len];
                    sum += ring[i][j];
                }
            }
            ji.push_back(res);
        }
        else {
            ll res = 0;
            for (int j = 0; j < len; j++) {
                if (j & 1) res += ring[i][j];
                else res -= ring[i][j];
            }
            ans += abs(res);
        }
    }
    sort(ji.begin(), ji.end(), greater<int>());
    int c = 0;
    for (auto v : ji) {
        if (c & 1) ans -= v;
        else ans += v;
        c++;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _T = 1;
    cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}
