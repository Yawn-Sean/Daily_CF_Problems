#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <numeric>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
void solve() {
    int n; ll m;
    cin >> n >> m;
    vector<int> ans(n);
    int head = 0, tail = n - 1;
    for (int i = 1; i <= n; i++) {
        ll cnt = 1LL << (n - i - 1);
        if (m > cnt) {
            ans[tail] = i;
            tail -= 1;
            m -= cnt;
        } else {
            ans[head] = i;
            head += 1;
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
