/*
    Bonelight * V *
    20241005: 放假的懒惰之日 
    No Coding, No Bug 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define INF (int)2e14
void solve()
{
    int n,q; cin >> n >> q;
    map<int,int> mp;
    mp[1ll << n - 1] = 0;
    mp[1ll << n] = 0;
    for(int i = 0; i < q; i ++){
        int h,l,r,ans;
        cin >> h >> l >> r >> ans;
        r ++;
        l <<= n - h;
        r <<= n - h;
        if(ans) mp[l] ++, mp[r] --;
        else mp[l] --,mp[r] ++, mp[1ll << n] --, mp[1ll << n - 1] ++;
    }

    int cnt_q = 0;
    int o = 0, la = 1ll << n - 1, cnt = 0;
    for(auto &[idx,v]:mp){
        if(cnt_q == q){
            cnt += idx - la;
            o = la;
        }
        cnt_q += v;
        la = idx;
    } 
    if(cnt == 0){
        cout << "Game cheated!";
    } else if(cnt == 1){
        cout << o;
    } else {
        cout << "Data not sufficient!";
    }
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
