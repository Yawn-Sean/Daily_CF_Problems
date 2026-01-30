#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 1e9 + 7;
const int N = 3e3 + 10;
void solve()
{   
    string s;
    cin >> s;   
    int n = s.size();
    vector<int> num(10);
    vector<vector<int>> cnt(10, vector<int>(n+5));
    for(int i = 1; i <= 9; i ++)cin >> num[i];
    s = " " + s;
    for(int i = n; i >= 1; i --){
        int v = s[i]-'0';
        for(int j = 1; j <= 9; j ++)cnt[j][i] = cnt[j][i+1];
        cnt[v][i] ++;
    }
    string ans;
    for(int i = 0; i <= n ; ){
        vector<int> w(10, -1), cut(10, 0);
        for(int j = i+1; j <= n; j ++){
            int ok = 1;
            for(int k = 1; k <= 9; k ++){
                if(cnt[k][j+1] < num[k]-cut[k]){
                    ok = 0;
                    break;
                }
            }
            if(ok && w[s[j]-'0'] == -1)
            w[s[j]-'0'] = j;
            cut[s[j]-'0']++;
            if(cut[s[j]-'0'] > num[s[j]-'0'])break;
            
        }
        int fl = 0;
        for(int k = 9; k >= 1; k --){
            if(w[k] != -1){
                for(int j = 1; j <= 9; j ++)num[j] -= cnt[j][i+1] - cnt[j][w[k]];
                i = w[k];
                ans += s[i];
                fl = 1;
                break;
            }
        }
        if(!fl)break;
    }
    cout << ans << '\n';
}
signed cute_prov0nce()
{   
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
