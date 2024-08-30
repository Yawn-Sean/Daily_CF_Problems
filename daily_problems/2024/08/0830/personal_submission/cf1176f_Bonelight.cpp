#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>
 
void solve()
{
    int n; cin >> n;
    vector<int> dp(10, -2e18);
    dp[0] = 0;
    while(n --){
        int m; cin >> m;
        vector<int> ndp(10,-2e18);
        vector<vector<int>> a(4);
        
        for(int i = 0; i < m; i ++){
            int c,d; cin >> c >> d;
            a[c].push_back(d);
        }
        for(int i = 1; i <= 3; i ++){
            sort(begin(a[i]),end(a[i]),greater<>());
        }
        for(int n1 = 0; n1 <= 3 && n1 <= a[1].size(); n1 ++){
            for(int n2 = 0; n1 + 2 * n2 <= 3 && n2 <= a[2].size(); n2 ++){
                for(int n3 = 0; n1 + 2 * n2 + 3 * n3 <= 3 && n3 <= a[3].size(); n3 ++){
                    int sum = 0, mx = 0;
                    for(int i = 0; i < n1; i ++){
                        sum += a[1][i];
                        mx = max(mx,a[1][i]);
                    }
                    for(int i = 0; i < n2; i ++){
                        sum += a[2][i];
                        mx = max(mx,a[2][i]);
                    }
                    for(int i = 0; i < n3; i ++){
                        sum += a[3][i];
                        mx = max(mx,a[3][i]);
                    }

                    for(int i = 0; i < 10; i ++){
                        int v = dp[i] + sum; 
                        int cost = i + n1 + n2 + n3;
                        if(cost >= 10){
                            v += mx;
                            cost -= 10;
                        }
                        ndp[cost] = max(ndp[cost], v);
                    }
                }
            }
        }
        dp = ndp;
    }
    cout << *max_element(begin(dp),end(dp)) << endl;
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
