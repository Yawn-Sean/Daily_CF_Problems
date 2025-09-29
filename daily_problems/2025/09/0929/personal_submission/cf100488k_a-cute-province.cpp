#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0, all = 0;
    for(int i = 0; i < n; i ++)cin >> a[i], all += a[i];

    for(int i =0; i < n; i ++){
        int up = i/2 + 1;
        if(up > pq.size()){
            pq.push(a[i]);
            ans += a[i];
        }
        else if(a[i] > pq.top()){
            ans -= pq.top();
            pq.pop();
            pq.push(a[i]);
            ans += a[i];
        }

    }
    cout << ans << ' ' << all - ans << '\n';

}

signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
