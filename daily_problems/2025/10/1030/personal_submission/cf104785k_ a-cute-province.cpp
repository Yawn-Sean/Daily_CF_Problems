#include<bits/stdc++.h>
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e5 + 10;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> ve1, ve2;
    for(int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        if(u > v)ve1.emplace_back(i);
        else ve2.emplace_back(i);
    }
    cout << "YES" << '\n';
    if(ve1.size() >= ve2.size()){
        cout << ve1.size() << '\n';
        for(auto u : ve1)cout << u <<' ';
    }
    else{
        cout << ve2.size() << '\n';
        for(auto u : ve2)cout << u <<' ';
    }


}

int cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
