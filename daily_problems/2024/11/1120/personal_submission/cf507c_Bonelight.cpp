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
#define VC vector<int>
#define MAT vector<VC>

void solve(){   
    int h,n; cin >> h >> n;

    function<int(int,int,int,int)> dfs = [&](int l, int r, int op, int h) ->int {
        if(h == 0) return 0;
        int mid = l + (r - l) / 2;
        int ans = ((n <= mid) == op)? 1ll << h:1; // 是否走反 0左1右
        ans += ((n <= mid)? dfs(l,mid,1,h-1):dfs(mid+1,r,0,h-1));
        return ans;
    };

    cout << dfs(1ll,1ll<<h,0,h) << endl << endl;
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
