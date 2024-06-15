#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

using ll = long long;
constexpr int N = 2e5 + 5;

int n, k, a[N], nxt[N], ans;
ll suf[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	nxt[n + 1] = n + 1;
	for(int i = n; i >= 1; -- i) {
		if(a[i] > 1) {
			nxt[i] = i;
		}
		else {
			nxt[i] = nxt[i + 1];
		}
		suf[i] = a[i] + suf[i + 1];
	}
	for(int i = 1; i <= n; ++ i) {
		ll s = 0;
		ll m = 1;
		for(int j = i; j <= n; ++ j) {
			if(m >= (suf[i] * k) / a[j] + 1) break;
			if(a[j] == 1) {
				int v = nxt[j] - j;
				if(m > s * k && m % k == 0) {
					ll t = m / k;
					if(t - s <= v) {
						++ ans;
					}
				}
				s += v;
				j = nxt[j] - 1;
			}
			else {
				m *= a[j];
				s += a[j];
				if(m == s * k) {
					++ ans;
				} 
			}
		}
	}
	cout << ans;
	return 0;
}
