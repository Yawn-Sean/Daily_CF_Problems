/*
    Bonelight * v *
    20241017：CF,Goodnight
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
    vector<int> a(n); for(int i = 0; i < n; i ++) cin >> a[i];
    const int N = 1e6;
    map<int,int> cnt;
    vector<int> sg(N);
    for(int i = 1, l = 0, r = 0; i < N; i ++){
        while(l*l*l*l < i) cnt[sg[l]] --, l++;
        while(r*r <= i && r < i) cnt[sg[r]] ++, r ++;
        while(cnt[sg[i]]) sg[i] ++; // 区间必败状态数
    }

    cnt.clear();
    sort(begin(a), end(a));
    int ans = 0;
    for(int i = 0, l = 0, r = 0; i < n; i ++){
        while(l*l*l*l < a[i]) cnt[sg[l]] --, l ++;
        while(r*r <= a[i] && r < a[i]) cnt[sg[r]] ++, r ++;
        int t = 0;
        while(cnt[t]) t ++;
        ans ^= t;
    }
    if(ans) cout << "Furlo" << endl;
    else cout << "Rublo" << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
