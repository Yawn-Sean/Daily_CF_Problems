#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const ll LIM = 3 * 1e6; // 当 i 达到 3 * 10^6 时，可以停止

ll n;

// 计算给定 n 和 m 的网格中所有正方形子网格的数量
ll countSquares(ll n, ll m) {
    n = n + 1;
    m = m + 1;
    ll min_mn = min(n, m);
    ll mn = n * m;
    ll sum_k = min_mn * (min_mn + 1) / 2;
    ll sum_k2 = min_mn * (min_mn + 1) * (2 * min_mn + 1) / 6;
    return mn * min_mn - (n + m) * sum_k + sum_k2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<pair<ll, ll>> ans;

    // 枚举 n 的值
    for (ll i = 1; i <= LIM; i++) {
        // 预检查，若 countSquares(i, i) > n 则跳过
        ll square1 = countSquares(i, i);
        if (square1 > n) continue;

        // 预检查，若 countSquares(i, 1e18) < n 则跳过
        ll maxPossible = countSquares(i, 1e18);
        if (maxPossible < n) continue;

        // 二分查找 m 值，使得 countSquares(i, m) == n
        ll l = i, r = n;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            ll square = countSquares(i, mid);
            if (square == n) {
                ans.emplace_back(i, mid);
                break;
            } else if (square < n) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    int x = ans.size();
    int t = 2 * x, idx = x - 1;
    if(ans[x - 1].first == ans[x - 1].second){
    	t -= 1;
    	idx -= 1;
	}
    cout <<	t << endl;
    for(int i = 0; i < x; i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    for(int i = idx; i >= 0; i--){
    	cout << ans[i].second << " " << ans[i].first << endl;
	}
}