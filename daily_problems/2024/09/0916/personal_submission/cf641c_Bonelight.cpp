#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
// #define endl '\n'
#define pii pair<int, int>

void solve()
{
    int n,q; cin >> n >> q;
    
    auto M = [&](int x){
        return (x % n + n) % n;
    };

    int odd = 0,even = 0,sw = 0;
    while(q --){
        int op; cin >> op;
        if(op == 1){
            int x; cin >> x;
            odd = M(odd + x);
            even = M(even + x);
            sw ^= (x & 1);
        } else {
            if(sw){
                odd = M(odd - 1);
                even = M(even + 1);
            } else{
                odd = M(odd + 1);
                even = M(even - 1);
            }
            sw ^= 1;
        }
    }
    vector<int> ans(n);
    for(int i = 0; i < n; i ++){
        if(i % 2 == 1){
            ans[(i + even) % n] = i + 1;
        } else {
            ans[(i + odd) % n] = i + 1;
        }
    }
    for(auto i:ans) cout << i << ' ';

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
