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
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    vector<int> a(k+1);
    int cnt = 0, sum = 0;
    for(int i=1; i<=k; i++) {
        cin >> a[i];
        sum += a[i];
        if(a[i] >= y) cnt ++;
    }
    int tot = (n+1) / 2;
    if(sum + (n-k) > x) {
        cout << -1 << endl;
        return;
    }
    if(cnt >= tot) {
        for(int i=1; i<=n-k; i++) {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }
    tot -= cnt;
    if(tot > n-k || sum+tot*y+(n-k-tot) > x) {
        cout << -1 << endl;
        return;
    }
    for(int i=1; i<=tot; i++)
        cout << y << " ";
    for(int i=tot+1; i<=n-k; i++) {
        cout << 1 << " ";
    }
    cout << endl;
}
