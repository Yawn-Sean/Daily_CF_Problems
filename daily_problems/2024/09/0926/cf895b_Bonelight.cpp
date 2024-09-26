/*
    Bonelight * v *
    20240926：Good morning
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,x,k; cin >> n >> x >> k;
    vector<int> a(n);
    map<int,int> mp;
    for(auto &i:a) cin >> i, mp[i] ++;
    sort(begin(a),end(a));
    
    int ans = 0;
    for(int i = 0; i < n; i ++){
        int num = (a[i] - 1) / x + k;
        int idx = lower_bound(begin(a),end(a), x * (num + 1)) - begin(a);
        int more = lower_bound(begin(a),end(a), max(a[i], x * num)) - begin(a);
        ans += idx - more;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
