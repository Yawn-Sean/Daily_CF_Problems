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
const int N = 1e6 + 10;
void f(int x, vector<int> &v){
    int a = 0;
    while(x%2 == 0){
        a++;
        x/=2;
    }
    if(a > 0)v.emplace_back(a);
    for(int i = 3; i * i <= x; i +=2){
        a = 0;
        while(x%i == 0){
            a++;
            x/=i;
        }
        if(a > 0)v.emplace_back(a);
    }
    if(x > 1)v.emplace_back(1);
}
void solve()
{
    int x, k;
    cin >> x >> k;
    vector<int> st;
    f(x, st);
    int l = 0, r = 63;
    while(l < r){
        int mid = (l + r)/2+1;
        int sum = 0;
        for(auto u : st){
            if(u < (1ll << mid))sum += (1ll << mid) - u;
            else{
                sum += (u+(1ll << mid)-1)/(1ll << mid) * (1ll << mid) - u;
            }
        }
        if(sum > k)r = mid-1;
        else l = mid;
    }
    cout << l << '\n';
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
