
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;
const int inf = 1e14;

void solve(int _) 
{
    int n, m;
    cin >> n >> m;
    vector<PII> a[m+1], t;
    for (int i = 1, p, c; i <= n; i ++ ) {
        cin >> p >> c;
        if (p != 1) t.emplace_back(c, i);
        a[p].emplace_back(c, i);
    }
    sort(all(t));
    for (int i = 1; i <= m; i ++ ) {
        auto &v = a[i];
        if (SZ(v)) {
            sort(all(v));
        }
    }
    vector<int> used(n+1);
    int ans = inf;
    for (int x = 0; x < n; x ++ ) {
        int vote = SZ(a[1]), res = 0;
        for (int i = 2; i <= m; i ++ ) {
            auto v = a[i];
            int tm = SZ(v);
            int now = 0;
            while (tm > x) {
                res += v[now].x;
                used[v[now].y] = 1;
                now ++; vote ++; tm --;
            }
        }
        int cur = 0;
        while (vote <= x) {
            while (used[t[cur].y]) cur ++;
            res += t[cur].x;
            cur ++; vote ++;
        }
        ans = min(ans, res);
        for (int i = 1; i <= n; i ++ ) used[i] = 0;
    }
    cout << ans << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}