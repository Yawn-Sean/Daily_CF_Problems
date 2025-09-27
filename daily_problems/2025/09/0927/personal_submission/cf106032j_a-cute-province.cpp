#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e5+10;
const int mod = 998244353;
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n+1), cnt(m+1), vis(n+1);
    set<int> st;
    for(int i = 1; i<= n; i++)cin >> a[i], cnt[a[i]]++;
    for(int i = 1; i <= n; i++){
        if(cnt[a[i]]%2 == 0)vis[i] = 1;
        else st.insert(a[i]);
    }
    int g = 0;
    while(q--){
        int op;
        cin >> op;
        if(op == 1)g++;
        else{
            int x;
            cin >> x;
            auto w = st.lower_bound(a[x]);
            if(w != st.end()){
                int up = *w - a[x];
                if(up <= g){
                    cout << *w << '\n';
                }
                else cout << a[x] + g << '\n';
            }
            else{
                if(st.size() != 0){
                    int up = m +*st.begin() - a[x];
                    if(up <= g){
                        cout << *st.begin() << '\n';
                    }
                    else cout << ((a[x] + g)%m == 0? m:(a[x] + g)%m)<< '\n';
                }
                else{
                    cout << ((a[x] + g)%m == 0? m:(a[x] + g)%m)<< '\n';
                }
            }
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
    cin >> t;
    //t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
