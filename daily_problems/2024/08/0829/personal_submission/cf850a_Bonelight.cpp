#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>
 
void solve()
{
    int n; cin >> n;
    vector<vector<int>> a(n,vector<int>(5));
    
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < 5; j ++){
            cin >> a[i][j];
        }
    }

    if(n > 33) { cout << 0 << endl; return; }
    else {
        vector<int> ans;
        for(int i = 0; i < n; i ++){
            int ok1 = 1;
            for(int j = 0; j < n; j ++){
                for(int k = 0; k < j; k ++){
                    int sum = 0;
                    for(int d = 0; d < 5; d ++){
                        sum += (a[j][d] - a[i][d]) * (a[k][d] - a[i][d]);
                    }
                    if(sum > 0) ok1 = 0;
                }
            }
            if(ok1) ans.push_back(i);
        }
        cout << ans.size() << endl;
        for(auto i:ans) cout << i + 1 << ' ';
        cout << endl;
    }
}
 
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
        solve();
}
