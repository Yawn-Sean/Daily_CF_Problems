/*
    Bonelight * V *
    20241009: CF BOOM~
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
    int n,d,m; cin >> n >> d >> m;
    vector<int> st(n + 1), ed(n + 1);
    while(m --){
        int sti, edi; cin >> sti >> edi;
        st[sti] ++, ed[edi] ++;
    }
    for(int i = 1; i <= n; i ++) st[i] += st[i - 1], ed[i] += ed[i - 1];

    int mx = -INF, mi = INF, bro = 0, mom = 0;
    for(int i = d; i <= n; i ++){
        int cnt = st[i] - ed[i - d];
        if(cnt > mx) mx = cnt, bro = i - d + 1;
        if(cnt < mi) mi = cnt, mom = i - d + 1;
    }
    cout << bro << ' ' << mom << endl;
}   

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1; cin >> T;
    while(T --){
        solve();
    }
}
