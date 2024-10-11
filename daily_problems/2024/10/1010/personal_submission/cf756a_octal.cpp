#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
inline void solve()
{
    int n;
    cin >> n;
    vector<int> fa(n+1);
    for(int i=1; i<=n; i++)
        fa[i] = i;
    function<int(int)> find = [&](int x) {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    };
    for(int i=1; i<=n; i++) {
        int p;
        cin >> p;
        int fp = find(p);
        int fi = find(i);
        if(fp != fi) fa[fp] = fi;
    }
    set<int> st;
    for(int i=1; i<=n; i++) {
        st.insert(find(i));
    }
    int tot = 0;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        tot += x;
    }
    int res = st.size() - (st.size() == 1);
    if(tot % 2 == 0) res ++;
    cout << res << endl;
    
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}
