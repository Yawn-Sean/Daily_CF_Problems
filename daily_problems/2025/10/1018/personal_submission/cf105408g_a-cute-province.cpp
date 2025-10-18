#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e7 + 10;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int g = 0;
    for(int i = 0 ; i < n; i ++){
        cin >> a[i];
        g = std::gcd(g, a[i]);
    }
    for(int i = 0; i < n; i ++){
        a[i] /= g;
    }
    map<int, int> mp;
    int N = *max_element(a.begin(), a.end());
    vector<int> p(N+1, 0);
    iota(p.begin(), p.end(), 0);
    for(int i = 2; i <= N; i ++){
        if(p[i] == i)
        for(int j = i; j <= N; j += i)p[j] = i;
    }
    for(int i = 0; i < n; i ++){
        set<int> st;
        int x = a[i];
        while(x > 1){
            st.insert(p[x]);
            x /= p[x];
        }
        for(auto u : st){
            mp[u]++;
            if(mp[u] >= 2){
                cout << "NO" << '\n';
                return ;
            }
        }
    }
    cout << "YES" << '\n';
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
