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
    vector<ll> a(n+1);
    ll res = 0;
    for(int i=1; i<=n; i++)
        cin >> a[i], res ^= a[i];
    vector<ll> c(n+5, 0);
    for(int i=1; i<=n; i++) {
        int t = n % (2*i);
        if(t < i) {
            c[1] ++;
            c[t+1] --;
        } else {
            c[0] ++;
            c[1] --;
            if((t%i+1)%i != 0) {
                c[(t%i+1)%i] ++;
                c[i] --;
            }
        }
    }
    
    for(int i=1; i<n; i++)
        c[i] += c[i-1], c[i] %= 2;
    for(int i=0; i<n; i++)
    if(c[i]) res ^= i;
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
