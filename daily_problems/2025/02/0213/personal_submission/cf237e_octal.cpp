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
    string T; cin >> T;
    int sz = T.size();
    int n;
    cin >> n;
    // 1+n+26+1
    MinCostFlow maxf(n+50);
    int s = n+27, t = n+28;
    for(auto c: T) {
        maxf.add(n+1+c-'a', t, 1, 0);
    }
    for(int i=1; i<=n; i++) {
        string a; int b;
        cin >> a >> b;
        maxf.add(s, i, b, i);
        for(auto c: a)
            maxf.add(i, n+1+c-'a', 1, 0);
    }
    auto [flow, cost] = maxf.flow(s, t);
    if(flow != sz) cout << -1 << endl;
    else cout << cost << endl;
}
