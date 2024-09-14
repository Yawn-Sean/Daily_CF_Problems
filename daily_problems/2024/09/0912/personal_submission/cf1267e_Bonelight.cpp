#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define pii pair<int, int>

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> sum(n); 
    vector<vector<int>> table(m, vector<int>(n));
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            cin >> table[i][j];
            sum[j] += table[i][j]; 
        }
    }

    if(max_element(begin(sum),end(sum)) - begin(sum) != n - 1){
        cout << 0 << endl;
        cout << endl;
        return;
    }
    vector<int> res(m + 1);
    vector<int> idx(m);
    iota(begin(idx),end(idx),0);
    for(int win = 0; win < n - 1; win ++){
        sort(begin(idx),end(idx), [&](int x, int y){
            return table[x][win] - table[x][n - 1] < table[y][win] - table[y][n - 1];
        });    
        int gap = sum[n - 1] - sum[win];
        vector<int> res_t;
        for(int i = 0; i < m; i ++){
            int o = idx[i];
            gap += table[o][win] - table[o][n - 1];
            res_t.push_back(o + 1);
            if(gap <= 0) break;
        }
        // cout << gap << endl;
        // for(auto i:res_t) cout << i << ' ';
        // cout << endl;
        if(res_t.size() < res.size()) res = res_t;
    }

    cout << res.size() << endl;
    for(auto i:res) cout << i << ' ';
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
