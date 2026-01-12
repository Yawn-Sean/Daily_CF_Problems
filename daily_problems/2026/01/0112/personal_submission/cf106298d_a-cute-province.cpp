#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;
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
void solve() {
    int n;
    cin >> n;  
    vector<int> ve, l(n+1), r(n+1);
    for(int i = 1; i <= n; i ++)cin >> l[i];
    for(int i = 1; i <= n; i ++)cin >> r[i];
    for(int i = 1 ;i <= n; i++){
        if(r[i] == l[i])ve.emplace_back(r[i]);
    }
    if(ve.empty()){
        cout << "YES\n";
        for(int i = 1; i <= n; i ++){
            if(l[i]%2)cout << l[i]+1 <<' ';
            else cout << l[i] <<' ';
        }
        cout << '\n';
        return ;
    }
    int g = 0;
    for(auto x : ve)g = __gcd(g, x);
    set<int> st;
    f(g, st);

    for(auto u : st){
        int ok = 1;
        for(int i = 1; i <= n; i ++){
            if((l[i]+u-1)/u * u > r[i])ok = 0;
        }
        
        if(ok){
            cout << "YES\n";
            for(int i = 1; i <= n; i ++){
                cout << (l[i]+u-1)/u * u <<' ';
            }
            cout << '\n';
            return ;
        }
    }
    cout << "NO\n";
            return ;
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
