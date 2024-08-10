#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <queue>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, h;
    cin >> n >> h;
    vector<pii> wind;
    for (int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        wind.emplace_back(x1, x2);
    }
    vector<int> gap;
    for (int i = 1; i < n; i++) {
        gap.emplace_back(wind[i].first - wind[i - 1].second);
    }
    gap.push_back(1e9);
    int r = 0, ans = 0, dis = 0, sum = 0;
    for (int i = 0; i < sz(gap); i++) {
        r = max(r, i);
        while (r < sz(gap)) {
            if (sum + gap[r] >= h) {
                break;
            } else {
                dis += wind[r].second - wind[r].first + gap[r];
                sum += gap[r];
                r++;
            }
        }
        ans = max(ans, dis + wind[r].second - wind[r].first + (h - sum));
        if (i == r) {
            sum = 0;
            dis = 0;
        } else {
            sum -= gap[i];
            dis -= (wind[i].second - wind[i].first + gap[i]);
        }
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
