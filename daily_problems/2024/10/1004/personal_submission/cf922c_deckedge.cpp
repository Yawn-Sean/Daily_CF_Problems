#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;
using i64 = long long;

void solve() {
    i64 n, k;
    cin >> n >> k;
    rep(i, 1, k + 1) {
        if (n % i != i - 1) {
            cout << "No\n";
            return ;
        }
    }
    cout << "Yes\n"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}