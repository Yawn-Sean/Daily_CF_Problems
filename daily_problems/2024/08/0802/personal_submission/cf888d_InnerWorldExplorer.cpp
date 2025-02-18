#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

using u64 = unsigned long long;

u64 comb(u64 n, u64 k) {
    if (k > n) {
        return 0;
    }
    u64 r = 1;
    for (u64 d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	u64 ans = 1;
	if (k >= 2) {
		ans += comb(n, 2);
	}
	if (k >= 3) {
		ans += comb(n, 3) * 2;
	}
	if (k >= 4) {
		ans += comb(n, 4) * 9;
	}
	cout << ans << endl;
	return 0;
}
