#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int w, l, a[100005], s, res = 2e9;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> w >> l;
	for(int i = 1; i < w; ++ i) {
		cin >> a[i];
		s += a[i];
		if(i >= l) {
			s -= a[i - l];
			res = min(res, s);
		}
	}
	if(res == 2e9) res = 0;
	cout << res;
	return 0;
}
