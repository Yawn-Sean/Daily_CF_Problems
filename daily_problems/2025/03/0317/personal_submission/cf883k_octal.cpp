#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;

inline void solve()
{
    int n;
    cin >> n;
    vector<int> s(n+1), g(n+1);
    int mini = 1;
    for(int i=1; i<=n; i++) {
        cin >> s[i] >> g[i];
        g[i] += s[i];   
    }
    for(int i=2; i<=n; i++) {
        g[i] = min(g[i], g[i-1]+1);
    }
    for(int i=n-1; i>=1; i--) {
        g[i] = min(g[i], g[i+1]+1);
    }
    ll res = 0;
    for(int i=1; i<=n; i++) {
        res += g[i] - s[i];
        if(g[i] < s[i]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << res << endl;
    for(int i=1; i<=n; i++)
        cout << g[i] << " ";
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}
