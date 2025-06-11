/*
    Bonelight * v *
    20241001：放假躺尸，不想动
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(n),b(m);
    
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < m; i ++) cin >> b[i];

    sort(begin(a), end(a));
    sort(begin(b), end(b));

    auto check = [&](int x){
        int sum = k;
        for(int i = 0; i < x; i ++){
            if(a[n - x + i] < b[i]) sum -= b[i] - a[n - x + i];
            // cout << a[n - x + i] << ' ' << b[i] << " " << sum << ' ' << x << endl;
            if(sum < 0) return 0;
        }
        return 1;
    };


    int l = 0, r = n;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(!check(mid)) r = mid - 1;
        else l = mid;
    }
    int ans = max(0ll, accumulate(begin(b), begin(b) + l, 0ll) - k);
    cout << l << ' ' << ans << endl;
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
