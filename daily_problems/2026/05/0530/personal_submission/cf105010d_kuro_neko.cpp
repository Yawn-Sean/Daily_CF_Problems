#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define frep(i, x, y) for (int i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    ll n, k;
    cin >> n >> k;
    vl a(n);
    int tem = 0;
    rep(i, 0, n - 1) {
        cin >> a[i];
        a[i] %= k;
        tem += (a[i] != 0);
    }
    if (tem == 0) {
        cout << "Rami" << endl;
        return;
    }
    if (tem == 2) {
        cout << "Oussama" << endl;
        return;
    }
    if (n % 2 == 1) {
        cout << "Rami" << endl;
        return;
    } else {
        cout << "Oussama" << endl;
        return;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
