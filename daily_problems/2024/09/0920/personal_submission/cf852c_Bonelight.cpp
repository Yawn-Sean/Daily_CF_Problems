#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define INF 2e14
#define pii pair<int, int>

void solve(){
    int n; cin >> n;
    vector<int> a(n),idx(n);

    for(int &i:a) cin >> i;
    iota(begin(idx),end(idx),0);
    sort(begin(idx),end(idx), [&](const int &x, const int &y){
        return a[x % n] + a[(x + 1) % n] < a[y % n] + a[(y + 1) % n];  
    });

    vector<int> ans(n);
    for(int i = 0; i < n; i ++){
        ans[idx[i]] = i;
    }
    for(auto i:ans) cout << i <<  ' ';
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
