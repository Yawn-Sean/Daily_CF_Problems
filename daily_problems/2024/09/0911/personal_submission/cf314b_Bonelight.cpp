#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define pii pair<int, int>

void solve()
{
    int b,d; cin >> b >> d;
    string a,c; cin >> a >> c;
    
    int m = c.size();
    vector<int> nx(m), cnts(m);
    iota(begin(nx),end(nx),0);

    for(int i = 0; i < m; i ++){
        for(auto j:a){
            if(j == c[nx[i]]){
                nx[i] ++;
                if(nx[i] == m) nx[i] = 0, cnts[i] ++;
            }
        }
    } 
    int idx = 0, cnt = 0;
    while(b --){
        cnt += cnts[idx];
        idx = nx[idx];
    }

    cout << cnt / d << endl;

}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
    {
        solve();
    }
}
