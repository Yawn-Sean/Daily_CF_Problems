#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
#define rep(i, n) for (int i = 1; i <= n; i ++)
#define rep0(i, n) for (int i = 0; i < n; i ++)

using namespace std;
void print(vector<int>& vi) {
    for (auto t: vi) {
        cout << t << ' ';
    }
    cout << endl;
}

//////////////////////////////////////////////////
const int N = 2e5 + 10;
const int mod = 998244353;
void solve(int _) 
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), pre(n+1), nxt(n+1);
    rep(i, n) {
        cin >> a[i];
    }

    rep(i, n) {
        pre[a[i]] = (i > 1 ? a[i-1] : -1);
        nxt[a[i]] = (i < n ? a[i+1] : -1);
    }

    vector<int> b(m+1), need(n+1);
    rep(i, m) {
        cin >> b[i];
        need[b[i]] = 1;
    }

    int ans = 1;
    rep(i, m) {
        int p = (pre[b[i]] > 0 && need[pre[b[i]]] == 0);
        int q = (nxt[b[i]] > 0 && need[nxt[b[i]]] == 0);
        if (p && q) {
            ans = (ans * 2) % mod;
        }
        if (!p && !q) {
            cout << 0 << endl;
            return;
        }
        need[b[i]] = 0;
    }
    cout << ans << endl;
} 


signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}