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
    int n,m; cin >> n >> m;
    int a,b1,b2,c; a=b1=b2=c=0;

    for(int i = 2; i <= 4*n; i += 4){
        for(int j = 2; j <= 4*m; j += 4){
            int x; cin >> x;
            a += x;
            b1 += 2*x*i;
            b2 += 2*x*j;
            c += x*(i*i+j*j);
        }
    }

    auto f = [&](int a, int b){
        if(!a) return 0ll;
        int x1 = b / a / 8;
        int x2 = x1 + 1;
        return abs(8*a*x1 - b) <= abs(8*a*x2 - b)? x1*4:x2*4;
        // 判断距离 |x - b/2a| 
    };

    int x = f(a,b1), y = f(a,b2);
    // cout << x << ' ' << y <<endl;
    cout << a * (x*x+y*y) - b1*x - b2*y + c << endl;
    cout << x/4 << ' ' << y/4 << endl;
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
