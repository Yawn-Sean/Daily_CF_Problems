#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
#define pb push_back
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6; 
const int mod = 1e9 + 7;

void solve()
{
    int t1, t2, x1, x2, t0;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    vector<pair<int, PII>> v;
    if(t1 == t0 && t2 == t0){
        cout << x1 <<' ' << x2 << '\n';
        return;
    }
    if(t1 == t0){
        cout << x1 <<' ' << 0 << '\n';
        return;
    }
    if(t2 == t0){
        cout << 0 <<' ' << x2 << '\n';
        return;
    }
    for(int y1 = 0; y1 <= x1; y1 ++){
        int l = 0, r = x2;
        if(y1 == 0)l = 1;
        while(l < r){
            int mid = l + r >> 1;
            if((t1-t0)*y1 + (t2-t0)*mid >=0 )r = mid;
            else l = mid+1;
        }
        if(((t1-t0)*y1 + (t2-t0)*l) < 0)continue;
        int k = 1e18, p = std::gcd(y1, l);
        if(y1)k = min(x1/y1, k);
        if(l)k = min(x2/l, k);
        v.push_back({((t1-t0)*y1 + (t2-t0)*l)/p, {y1*k, l*k}});
        //if(l && !(y1 == 0 && l == 1))v.push_back({abs((t1-t0)*y1 + (t2-t0)*(l-1)), {y1, l-1}});
    }
    sort(all(v), [&](pair<int, PII> i, pair<int, PII> j){
        if(i.x == j.x)return i.y.x+i.y.y > j.y.x+j.y.y;
        return i.x < j.x;
    });   
    //for(auto [u, p] : v)cout << u <<' ' << p.x <<' ' << p.y << '\n';
    cout << v[0].y.x <<' ' << v[0].y.y << '\n';
}

signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     // 取消同步流
    

     int t;
     //cin >> t;
 t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
