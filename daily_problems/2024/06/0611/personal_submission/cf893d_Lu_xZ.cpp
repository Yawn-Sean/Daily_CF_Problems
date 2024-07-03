#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

using ll = long long;

int n, d, l, r, ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> d;
	for(int i = 1; i <= n; ++ i) {
		int x; cin >> x;
		if(!x) {
			l = max(l, 0);
			if(r < 0) {
				r = d;
				++ ans;
			}
		}
		else {
			l += x;
			r += x;
			if(l > d) {
				cout << -1;
				exit(0);
			}
			r = min(r, d);
		}
	}
	cout << ans << '\n';
	return 0;
}
