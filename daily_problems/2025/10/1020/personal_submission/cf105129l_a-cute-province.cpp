#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e7 + 10;
void f(int x, set<int> &v){
    while(x%2 == 0){
        v.insert(2);
        x/=2;
    }
    for(int i = 3; i * i <= x; i +=2){
        while(x%i == 0){
            v.insert(i);
            x/=i;
        }
    }
    if(x > 1)v.insert(x);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), vis(51);

    for(int i = 0 ;i < n; i ++)cin >> a[i], vis[a[i]] = 1;
    set<int> all;
    for(int i = 0 ; i < n; i ++){
        set<int> st;
        f(a[i], st);
        for(auto u : st){
            all.insert(u);
        }
    }
    vector<int> ve = {1};
    for(auto u : all){
        int k = ve.size();
        for(int i = 0; i < k; i ++)ve.emplace_back(ve[i] * u);
    }
    sort(ve.begin(), ve.end());
    for(auto u : ve){
        int ok = 1;
        for(int i = 2; i <= 50; i ++){
            if(vis[i] && std::gcd(i, u) == 1){
                ok = 0;
                break;
            }
        }
        if(ok){
            cout << u << '\n';
            return ;
        }
    }
   
}   

signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
