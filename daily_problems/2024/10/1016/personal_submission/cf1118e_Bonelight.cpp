/*
    Bonelight * v *
    20241014：CF,Goodnight
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,m; cin >> n >> m;
    vector<int> add(2500,0);
    for(int i = 1;i < 2500; i ++) add[i] = i + add[i - 1]; 
    if(m - 1 < 2500 && n > add[m - 1] * 2){ cout << "NO" << endl; return;}

    cout << "YES" << endl;
    int cur = 1;
    for(int i = 1; i <= m; i ++){
        for(int j = i + 1; j <= m; j ++){
            if(cur <= n) cur ++, cout << i << ' ' << j << endl;
            else return;
            if(cur <= n) cur ++, cout << j << ' ' << i << endl;
            else return;
        }
    }
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
