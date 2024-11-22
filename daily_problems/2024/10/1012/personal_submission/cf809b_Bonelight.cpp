/*
    Bonelight * v *
    20241010：CF,Goodnight
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
// #define endl '\n' 交互题
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,k; cin >> n >> k;
    auto q = [&](int x, int y){
        cout << 1 << ' ' << x  << ' ' << y << endl;
        string res; cin >> res;
        return res[0] == 'T';
    };
    auto f = [&](int l, int r){
        while(l < r){
            int mid = l + r >> 1;
            if(q(mid, mid + 1)) r = mid;
            else l = mid + 1;
        }
        return r;
    };

    int x = f(1,n);
    int y = f(1,x - 1); // x == 1时 y == 0
    if(y == 0 || !q(y,x)) y = f(x + 1, n); // 右边有，找右边
    cout << 2 << ' ' << x << ' ' << y << endl;
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
