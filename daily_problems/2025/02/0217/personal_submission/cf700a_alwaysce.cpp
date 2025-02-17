#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;
i64 mod = 1e9+9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /* 
        "时间固定这件事情是怎么发现的好神奇啊"
    */
    
    int n, l, v1, v2, k;
    cin >> n >> l >> v1 >> v2 >> k;

    int x = (n + k - 1) / k;

    long double ans = (long double)1.0 * l / v2 * (2ll * v2 * (x - 1) + v1 + v2) / (2ll * v1 * (x - 1) + v1 + v2);
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}
