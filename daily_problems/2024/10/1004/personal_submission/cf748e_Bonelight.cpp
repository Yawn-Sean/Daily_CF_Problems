/*
    Bonelight * V *
    20241004: 放假的懒惰之日 
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
    int n,m; cin >> n >> m;
    int MX = 1e7;
    vector<int> mp(MX + 1);

    for(int i = 0; i < n; i ++){
        int x; cin >> x; 
        mp[x] ++;
    }

    int cnt = 0;
    for(int i = MX; i >= 1; i --){
        cnt += mp[i];
        
        if(i * 2 + 1 <= MX){
            cnt += mp[i * 2 + 1];
            mp[i] += mp[i * 2 + 1];
            mp[i + 1] += mp[i * 2 + 1];
        }
        
        if(i * 2 <= MX){
            cnt += mp[i * 2];
            mp[i] += mp[i * 2] * 2;
        }

        if(cnt >= m){
            cout << i << endl;
            return;
        } 
    }
    cout << -1 << endl;
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
