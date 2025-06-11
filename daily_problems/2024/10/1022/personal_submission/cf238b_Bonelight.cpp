/*
    Bonelight * v *
    20241017：CF,Goodnight
    No Coding , No Bug
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,h; cin >> n >> h;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    
    if(n == 2){
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
    } else {
        int mi1 = INF, mi2 = INF, mi3 = INF, mx1 = -INF, mx2 = -INF, mi1_idx = 0;
        for(int i = 0; i < n; i ++){
            if(a[i] >= mx1) mx2=mx1, mx1=a[i];
            else if(a[i] > mx2) mx2 = a[i];

            if(a[i] <= mi1) mi3 = mi2, mi2 = mi1, mi1 = a[i], mi1_idx = i;
            else if(a[i] <= mi2) mi3 = mi2, mi2 = a[i];
            else if(a[i] < mi3) mi3 = a[i];
        }
        int mxR1 = mx1 + mx2, mxR2 = max(mx1 + mi1 + h, mx1 + mx2);
        int miR1 = mi1 + mi2, miR2 = min(mi1 + mi2 + h, mi2 + mi3);
        
        if(mxR1 - miR1 < mxR2 - miR2) mi1_idx = INF;

        int ans = min(mxR1 - miR1, mxR2 - miR2);
        cout << ans << endl;
        for(int i = 0; i < n; i ++){
            if(i == mi1_idx) cout << 2 << ' ';
            else cout << 1 << ' ';    
        }
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
