#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
template<typename T>
struct Fenwick{
    int n;
    vector<T> tr;
    Fenwick(int n) : n(n), tr(n + 1, 0){}
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, T c) { 
        for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }
    void add(int l, int r, T c) {
        add(l, c);
        if (r + 1 <= n) add(r + 1, -c);
    }
    T sum(int x) {
        T res = T();
        for(int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void modify(int x, T c) { 
        for(int i = x; i <= n; i += lowbit(i)) tr[i] = max(tr[i], c);
    }
    T query(int x) {
        T res = T();
        for(int i = x; i; i -= lowbit(i)) res = max(res, tr[i]);
        return res;
    }
};
inline void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> alls;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        alls.push_back(a[i]);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    map<int, int> mp;
    int sz = alls.size();
    for(int i=0; i<sz; i++)
        mp[alls[i]] = i+1;
    Fenwick<int> bit(n+5);
    ll res = 0;
    for(int i=1; i<=n; i++) {
        int x = a[i];
        res += min(bit.sum(mp[x]+1, n), bit.sum(mp[x]-1));
        bit.add(mp[x], 1);
    }
    
    cout << res << endl;
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
