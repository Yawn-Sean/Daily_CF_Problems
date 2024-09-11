#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define pii pair<int, int>

void solve()
{
    int n,k; cin >> n >> k;
    int ow = 0;
    int last = 0;
    queue<int> qu;
    while(n --){
        int x,y; cin >> x >> y;
        ow = x;
        while(qu.size() && ow >= qu.front()) qu.pop();
        if(qu.size() <= k) {
            last = max(last, ow) + y;
            qu.push(last);
            cout << last << ' ';
        }
        else cout << -1 << " ";
    }
    cout << endl;
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
