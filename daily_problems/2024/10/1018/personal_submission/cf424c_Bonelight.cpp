/*
    Bonelight * v *
    20241017：CF,Goodnight
    No Coding , No Bug
*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define endl '\n'
// #define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n; cin >> n;
    int ans = 0;
    for(int i = 1, x = 0; i <= n; i ++) cin >> x, ans ^= x;
    auto pre = [&](int x)->int {
        if(x % 4 == 0) return x;
        if(x % 4 == 1) return 1;
        if(x % 4 == 2) return x + 1;
        return 0;
    };

    for(int i = 1; i <= n; i ++){
        ans ^= (n / i) % 2 == 0? 0:pre(i - 1);
        ans ^= pre(n % i);
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
