#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double tot = double(n * (n - 1)) / 2.0;
    vector<int> delta_cnt(5002);
    sort(all(a));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int delta = a[i] - a[j];
            delta_cnt[delta] += 1.0;
        }
    }
    vector<int> suffix(5002);
    for (int i = 5000; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + delta_cnt[i];
    }
    double ans = 0.0;
    for (int i = 0; i <= 5000; i++) {
        for (int j = 0; j <= 5000; j++) {
            if (delta_cnt[i] > 0 && delta_cnt[j] > 0 && i + j <= 5000) {
                double p1 = double(delta_cnt[i]) / tot;
                double p2 = double(delta_cnt[j]) / tot;
                double p3 = double(suffix[i + j + 1]) / tot;
                ans += (p1 * p2 * p3);
            }
        }
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
