/*
    Bonelight * v *
    20240923:  I'm sad, How CF2013/F2, * x *
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int tar_x,tar_y; cin >> tar_x >> tar_y;
    int x = 0, y = 0;

#pragma region 
    auto deal = [&](int &x, int &y, char ch, int v){
        if(ch == 'L') x -= v;
        if(ch == 'R') x += v;
        if(ch == 'U') y += v;
        if(ch == 'D') y -= v;
    };

    auto check = [&](int d){
        int tx = x, ty = y;
        for(int i = 0; i < d; i ++){
            deal(tx, ty, s[i], -1);
        }

        for(int l = 0, r = d - 1; r < n ;l ++, r ++){
            int dist = abs(tar_x - tx) + abs(tar_y - ty);
            if(dist <= d && (d + tx + ty + tar_x + tar_y) % 2 == 0) return 1;
            if(r + 1 < n){
                deal(tx,ty,s[l],1);
                deal(tx,ty,s[r + 1],-1);
            }
        }
        return 0;
    };
#pragma endregion

    for(auto ch:s){
        deal(x, y, ch,1);
    }

    int l = 0, r = n + 1;
    while(l < r){
        int mid = l + r >> 1;
        if(!check(mid)) l = mid + 1;
        else r = mid;
    }
    if(r == n + 1) cout << -1 << endl;
    else cout << r << endl;
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
