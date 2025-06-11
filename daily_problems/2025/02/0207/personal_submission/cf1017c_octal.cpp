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
    int k = sqrt(n);
    vector<pii> seq;
    for(int i=1; i<=n; i+=k) {
        seq.push_back({i, min(i+k-1, n)});
    }
    for(auto [l, r]: seq) {
        for(int i=r; i>=l; i--)
            cout << i << " ";
    }
}
