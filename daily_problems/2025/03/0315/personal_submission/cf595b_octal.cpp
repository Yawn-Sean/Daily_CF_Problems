#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
inline void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n/k+1), b(n/k+1);
    for(int i=1; i<=n/k; i++)
        cin >> a[i];
    for(int i=1; i<=n/k; i++)
        cin >> b[i];
    ll res = 1;
    vector<int> pow(k+1);
    pow[0] = 1;
    for(int i=1; i<=k; i++)
        pow[i] = pow[i-1] * 10;
    for(int i=1; i<=n/k; i++) {
        int x = (pow[k]-1) / a[i] + 1;
        // b[i]*10^(k-1) ~ (b[i]+1)*10^(k-1)-1
        int y = ((b[i]+1)*pow[k-1]-1) / a[i] + 1;
        if(b[i] != 0) {
            y -= (b[i]*pow[k-1]-1) / a[i] + 1;
        }
        res = res * (x - y) % mod;
    }
    cout << res << endl;
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
