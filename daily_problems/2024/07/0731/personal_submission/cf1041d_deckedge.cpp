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

inline int read() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = read(), h = read();
    i64 res = 0;
    ve<array<int, 3>> a(n), b(n);
    ve<i64> pre_up(n + 1), sum(n);
    rep(i, 0, n) {
    	int l = read(), r = read();
    	a[i][0] = r - l, a[i][1] = l, a[i][2] = r;
    	if (i) {
    		b[i][1] = a[i - 1][2];
    		b[i][2] = a[i][1];
    		b[i][0] = b[i][2] - b[i][1];
    		sum[i] = sum[i - 1] + b[i][0];
    	} 
    }
    rep(i, 1, n + 1) {
    	pre_up[i] = pre_up[i - 1] + a[i - 1][0];
    }
    rep(i, 0, n) {
    	int low = 0, high = n - 1;
    	while (low < high) {
    		int mid = (low + high + 1) >> 1;
    		if (sum[mid] - sum[i] < h) {
    			low = mid;
    		} else {
    			high = mid - 1;
    		}
    	}
    	if (sum[low] - sum[i] >= h) {
    		low--;
    	}
    	i64 dis = pre_up[low + 1] - pre_up[i] + sum[low] - sum[i];
    	dis += h - (sum[low] - sum[i]);
    	res = max(res, dis);
    }
    cout << res << '\n';
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
