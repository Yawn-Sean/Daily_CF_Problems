#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define INF 2e14
void solve()
{
    int n; cin >> n; 
    string s; cin >> s;

    int G = 0;
    int ans = 0, lt = 0, now = 0, bil = 0;

    for(int i = 0; i < n; i ++){
        if(s[i] == 'G')  G ++;
    }

    for(int i = 0; i < n; i ++){
        if(s[i] == 'G'){
            now ++;
        } else {
            bil ++;
        }
        ans =  max(ans, now + lt + 1);
        if(bil == 1){
            lt = now, now = 0, bil = 0;
        }
    }
    ans = min(G,ans);
    cout << ans << endl; 
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
