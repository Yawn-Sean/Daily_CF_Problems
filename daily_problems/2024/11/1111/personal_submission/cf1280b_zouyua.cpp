#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using PII = pair<int,int>;
#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define lowbit(x) (x) & (-x)
#define endl "\n" 
#define pb push_back
#define point(x) setiosflags(ios::fixed)<<setprecision(x)
#define debug(x) cerr << #x << " = " << x << endl
const int N=1e5+10;
const int INF=0x3f3f3f3f;
const int mod=998244353;

void solve()
{
    int n, m; cin >> n >> m;
    int cnt = 0;
    vector<vector<char>> g(n + 1, vector<char> (m + 1));
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            if(g[i][j] == 'A') cnt ++;
        }
    }
    if(cnt == 0) {
        cout << "MORTAL" << endl;
        return ;
    }
    if(cnt == n * m) {
        cout << 0 << endl;
        return ;
    }
    auto check = [&](int k) {
        if(k == 1) {
            int ct = 0;
            for(int j = 1; j <= m; j ++) ct += g[1][j] == 'A';
            if(ct == m) return true;
            ct = 0;
            for(int j = 1; j <= m; j ++) ct += g[n][j] == 'A';
            if(ct == m) return true;
            ct = 0;
            for(int i = 1; i <= n; i ++) ct += g[i][1] == 'A';
            if(ct == n) return true;
            ct = 0;
            for(int i = 1; i <= n; i ++) ct += g[i][m] == 'A';
            if(ct == n) return true;

            return false;
        } else if(k == 2) {
            if(g[1][1] == 'A' || g[1][m] == 'A' || g[n][1] == 'A' || g[n][m] == 'A') return true;
            for(int i = 1; i <= n; i ++) {
                int ct = 0;
                for(int j = 1; j <= m; j ++) ct += g[i][j] == 'A';
                if(ct == m) return true;
            }
            for(int j = 1; j <= m; j ++) {
                int ct = 0;
                for(int i = 1; i <= n; i ++) ct += g[i][j] == 'A';
                if(ct == n) return true;
            }
            return false;
        } else if(k == 3){
            for(int j = 2; j <=m - 1; j ++)  if(g[1][j] == 'A') return true;
            for(int j = 2; j <=m - 1; j ++) {
                //cout << n << ' ' << j << ' ' << g[n][j] << endl;
                if(g[n][j] == 'A') return true;
            }
            for(int i = 2; i <=n - 1; i ++) if(g[i][1] == 'A') return true;;
            for(int i = 2; i <=n - 1; i ++) if(g[i][m] == 'A') return true;;
            return false;
        } else return true;
    };
    //cout << check(3) << endl;
    for(int i = 1; i <= 4; i ++) {
        if(check(i)) {
            cout << i << endl;
            return ;
        }
    }
    //cout << 4 << endl;
    assert(-1);
}
int main()
{
    IOS;
    int T = 1;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
