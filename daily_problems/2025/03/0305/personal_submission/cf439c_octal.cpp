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
    int n, k, p;
    cin >> n >> k >> p;
    k -= p;
    vector<int> a(n+1);
    ll sum = 0;
    vector<int> odd, even;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
        if(a[i] % 2) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }
    if(sum % 2 != k % 2 || k > odd.size()) {
        cout << "NO" << endl;
        return;
    }
    vector<vector<int>> res(k+p+1);
    if(even.size() >= p) {
        for(int i=1; i<=p; i++) {
            res[i].push_back(even.back());
            even.pop_back();
        }
        for(int i=p+1; i<=p+k; i++) {
            res[i].push_back(odd.back());
            odd.pop_back();
        }
        if(odd.size() % 2) {
            cout << "NO" << endl;
            return;
        }
        while(even.size()) {
            res[1].push_back(even.back());
            even.pop_back();
        }
        while(odd.size()) {
            res[1].push_back(odd.back());
            odd.pop_back();
        }
    } else {
        int i;
        for(i=1; !even.empty(); i++) {
            res[i].push_back(even.back());
            even.pop_back();
        }
        if((p-i+1)*2+k > odd.size()) {
            cout << "NO" << endl;
            return;
        }
        for(i; i<=p; i++) {
            res[i].push_back(odd.back());
            odd.pop_back();
            res[i].push_back(odd.back());
            odd.pop_back();
        }
        for(i; i<=p+k; i++) {
            res[i].push_back(odd.back());
            odd.pop_back();
        }
        if(odd.size() % 2) {
            cout << "NO" << endl;
            return;
        }
        while(even.size()) {
            res[1].push_back(even.back());
            even.pop_back();
        }
        while(odd.size()) {
            res[1].push_back(odd.back());
            odd.pop_back();
        }
    }
    cout << "YES" << endl;
    for(int i=1; i<=p+k; i++) {
        cout << res[i].size() << " ";
        for(int x: res[i])
            cout << x << " ";
        cout << endl;
    }

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
