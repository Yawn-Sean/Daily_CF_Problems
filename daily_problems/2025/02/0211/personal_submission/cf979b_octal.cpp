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
    string a, b, c;
    cin >> a >> b >> c;
    auto cal = [&](string s) {
        map<char, int> mp;
        for(auto c: s)
            mp[c] ++;
        int res = 0;
        for(auto [x, y]: mp)
            res = max(res, y);
        int sz = s.size();
        if(res == sz && n == 1) res --;
        else if(res + n <= sz) res += n;
        else {
            res = sz;
            if((res+n-sz) == 1) res --;
        }
        return res;
    };
    int x = cal(a);
    int y = cal(b);
    int z = cal(c);
    if(x > y && x > z) {
        cout << "Kuro" << endl;
    } else if(y > x && y > z) {
        cout << "Shiro" << endl;
    } else if(z > x && z > y) {
        cout << "Katie" << endl;
    } else cout << "Draw" << endl;
}
