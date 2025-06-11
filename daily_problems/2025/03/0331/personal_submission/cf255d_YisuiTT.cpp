#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
void solve(){
    i64 n, x, y, c;
    cin >> n >> x >> y >> c;
    auto check = [&](i64 cur) -> bool{
        i64 all = 1 + (cur + 1) * cur / 2 * 4;
        i64 u = cur - x >= 0 ? cur - x + 1 : 0;
        all -= u * u;
        i64 d = cur - (n - x + 1) >= 0 ? cur - (n - x + 1) + 1 : 0;
        all -= d * d;
        i64 l = cur - y >= 0 ? cur - y + 1 : 0;
        all -= l * l;
        i64 r = cur - (n - y + 1) >= 0 ? cur - (n - y + 1) + 1 : 0;
        all -= r * r;
        if(l > x && u > y)all += (l - x) * (l - x + 1) / 2;
        if(l > (n - x + 1) && d > y)all += (l - (n - x + 1)) * (l - (n - x + 1) + 1) / 2;
        if(r > x && u > (n - y + 1)) all += (r - x) * (r - x + 1) / 2;
        if(r > (n - x + 1) && d > (n - y + 1))all += (r - (n - x + 1)) * (r - (n - x + 1) + 1) / 2;

        // cout << cur << " " << all << '\n';
        return all >= c;
    };
    i64 l = 0, r = 2 * n;
    while(l <= r){
        i64 mid = (l + r) >> 1;
        if(check(mid))r = mid - 1;
        else l = mid + 1;
    }
    cout << r + 1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
