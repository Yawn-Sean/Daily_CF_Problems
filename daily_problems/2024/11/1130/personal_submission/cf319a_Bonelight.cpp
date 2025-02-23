/*
    Bonelight =^x^=
    20241117: 单枪匹马，无畏粉身碎骨
    我尝试过无数次了，但我知道，机会只会出现在其中的一两次
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>  
#define INF 2e18
#define VC vector<int>
#define MAT vector<VC>
// #define x first
// #define y second

/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/
void solve(){
    const int MOD = 1e9 + 7;
    auto M = [&](int x){return (x % MOD + MOD) % MOD;};
    
    string s; cin >> s;
    int n = s.size();


    // int cnt = 0; // 打表
    // for(int i = 0; i < (1 << n); i ++){
    //     for(int j = 0; j < i; j ++){
    //         if((j ^ x) > (i ^ x)) cnt ++;
    //     }
    // }
    // cout << cnt << endl;

    auto qpow = [&](int x, int y){
        int res = 1;
        while(y > 0){
            if(y & 1) res = M(res * x);
            x = M(x*x);
            y >>= 1;
        }
        return res;
    };

    int ans = 0;
    int base = qpow(2,n-1);
    for(int i = n-1; i >= 0; i --){
        int p = (n-1) - i;
        if(s[i] == '1') ans = M(ans + M(base*qpow(2,p)));
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1; //cin >> T;
    while(T --){
        solve();
    } 
}
