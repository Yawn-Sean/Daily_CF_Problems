/*
    Bonelight * V *
    20241011: CF Goodnight~
    No Coding, No Bug 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define INF (int)2e14

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1); for(int i = 1; i <= n; i ++) cin >> a[i];
    vector<int> pre(n + 2, 0), sub(n + 2, 0);
    vector<int> prev(n + 2, 0), subv(n + 2, 0);

    for(int i = 1; i <= n; i ++){
        pre[i] = max(pre[i - 1] + 1, a[i]);
        prev[i] = prev[i - 1] + (pre[i] - a[i]);
    }

    for(int i = n; i >= 1; i --) {
        sub[i] = max(sub[i + 1] + 1, a[i]);
        subv[i] = subv[i + 1] + (sub[i] - a[i]);
    }
    // for(int i = 0; i <= n+1; i ++) cout << pre[i] << " \n"[i == n + 1];
    // for(int i = 0; i <= n+1; i ++) cout << sub[i] << " \n"[i == n + 1];
    // for(int i = 0; i <= n+1; i ++) cout << prev[i] << " \n"[i == n + 1];
    // for(int i = 0; i <= n+1; i ++) cout << subv[i] << " \n"[i == n + 1];

    int ans = INF;
    for(int i = 1; i <= n; i ++){
        int o = max(max(pre[i - 1], sub[i + 1]) + 1, a[i]);
        int d = o - a[i];
        ans = min(ans, prev[i - 1] + subv[i + 1] + d);
    } 
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    
    int T = 1;
    while(T --){
        solve();
    }
}
