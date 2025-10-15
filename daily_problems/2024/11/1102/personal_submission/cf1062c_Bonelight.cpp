/*
    Bonelight * v *
    20241101：重 走 西 游
    千 仇 万 恨 无 归 处， 封 灯 何 须 至 尊 骨
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    const int MOD = 1e9 + 7;
    auto M = [&](int x){return (x % MOD + MOD) % MOD;};
    auto qmi = [&](int x, int y){
        int res = 1;
        while(y > 0){
            if(y & 1) res = M(res * x);
            y >>= 1;
            x = M(x * x);
        }
        return res;
    };

    int n,q; cin >> n >> q;
    string s; cin >> s;
    s = " " + s;
    vector<int> pre(n + 1);

    for(int i = 1; i <= n; i ++) {
        pre[i] = pre[i - 1] + (s[i] == '1');
    }

    while(q --){
        int l, r; cin >> l >> r;
        int d = r - l + 1;
        int cnt = pre[r] - pre[l - 1];
        int ans = M(M(qmi(2,cnt) - 1) * M(qmi(2,d - cnt)));
        cout << ans << endl;
    }

}

signed main(){
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    // cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
