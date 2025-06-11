/*
    Bonelight * V *
    20241007: 放假的懒惰之日 
    No Coding, No Bug 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define INF (int)2e14
void solve()
{
    int n; cin >> n;
    vector<int> ans;
    for(int i = 0; i < 60; i ++){
        long long v = 1ll << i, l = 0, r = min(1ll << 31, n / max(v - 1, 1ll));
        while(l + 1 < r){
            int mid = l + r >> 1;
            if(mid * (mid - 1) / 2 + mid * (v - 1) >= n) r = mid;
            else l = mid; 
        }
        if(r * (r - 1) / 2 + r * (v - 1) == n && r & 1){
            ans.push_back(r * v);
        }
    }

    if(ans.size()){
        for(auto i:ans) cout << i << endl;
    } else {
        cout << -1 << endl;
    }
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
