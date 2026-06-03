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
    ll n, d;
    cin >> n >> d;
    if (d > 2 * (n / 2) * (n / 2)) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if (n % 2 == 0) {
        rep(i, 1, n / 2) {
            rep(j, 1, n / 2) {
                cout << i << ' ' << j << ' ' << i + n / 2 << ' ' << j + n / 2 << endl;
                cout << i + n / 2 << ' ' << j + n / 2 << ' ' << i << ' ' << j << endl;
            }
        }
        rep(i, 1, n / 2) {
            rep(j, n / 2 + 1, n) {
                cout << i << ' ' << j << ' ' << i + n / 2 << ' ' << j - n / 2 << endl;
                cout << i + n / 2 << ' ' << j - n / 2 << ' ' << i << ' ' << j << endl;
            }
        }
    } else {
        rep(i, 1, n / 2) {
            rep(j, 1, n / 2) {
                cout << i << ' ' << j << ' ' << i + n / 2 << ' ' << j + n / 2 << endl;
                cout << i + n / 2 << ' ' << j + n / 2 << ' ' << i << ' ' << j << endl;
            }
        }
        rep(i, 1, n / 2) {
            rep(j, n / 2 + 1, n - 1) {
                cout << i << ' ' << j << ' ' << i + n / 2 << ' ' << j - n / 2 << endl;
                cout << i + n / 2 << ' ' << j - n / 2 << ' ' << i << ' ' << j << endl;
            }
        }
        cout << 1 << ' ' << n << ' ' << n << ' ' << n << endl;
        cout << n << ' ' << n << ' ' << n << ' ' << 1 << endl;
        cout << n << ' ' << 1 << ' ' << 1 << ' ' << n << endl;
        rep(i, 2, n - 1) {
            cout << n << ' ' << i << ' ' << n + 1 - i << ' ' << n << endl;
            cout << n + 1 - i << ' ' << n << ' ' << n << ' ' << i << endl;
        }
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
