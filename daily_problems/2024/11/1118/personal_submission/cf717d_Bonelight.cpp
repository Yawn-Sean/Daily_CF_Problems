/*
    Bonelight * v *
    20241113：重 走 西 游
    千 仇 万 恨 无 归 处， 封 灯 何 须 至 尊 骨
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e18
#define pii pair<int,int>
#define tiii tuple<int,int,int>

void solve(){   
    auto mul = [&](vector<double> &v1, vector<double> &v2){
        vector<double> res(128);
        for(int i = 0; i < 128; i ++){
            for(int j = 0; j < 128; j ++){ // x = x ^ y ^ y
                res[i] += v1[i^j]*v2[j];
            }
        }
        return res;
    };

    auto qpow = [&](vector<double> &x, int y){
        vector<double> res = x; y --;
        while(y > 0){
            if(y & 1) res = mul(res, x);    
            y >>= 1;
            x = mul(x,x);
        }
        return res;
    };

    int n,X; cin >> n >> X;
    vector<double> a(128);
    for(int i = 0; i <= X; i ++) cin >> a[i];
    a = qpow(a,n);
    cout << fixed << setprecision(20);
    cout << 1.0 - a[0] << endl;

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
