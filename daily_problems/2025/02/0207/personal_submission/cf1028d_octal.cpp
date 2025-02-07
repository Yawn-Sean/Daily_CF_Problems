#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
inline void solve()
{
    int n;
    cin >> n;
    int l = 0, r = 2e9;
    set<int> st;
    ll res = 1;
    st.insert(l), st.insert(r);
    while(n --) {
        string op;
        int x;
        cin >> op >> x;
        if(op == "ADD") st.insert(x);
        else {
            if(x < l || x > r) {
                cout << 0 << endl;
                return;
            }
            // 不确定是买or卖
            if(x > l && x < r) res = res * 2 % mod;
            l = *prev(st.lower_bound(x));
            r = *st.upper_bound(x);
            st.erase(x);
        }
    }
    ll tot = 1;
    for(int x: st) {
        if(x > l && x < r) tot ++;
    }
    res = res * tot % mod;
    cout << res << endl;
}
