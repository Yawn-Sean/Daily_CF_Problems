#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, h[2], w[2], ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> h[0] >> h[1] >> w[0] >> w[1];
	
	if(w[0] < w[1]) {
		swap(w[0], w[1]), swap(h[0], h[1]);
	}
	
	if(w[0] >= sqrt(n)) {
		for(int i = 0; i <= n / w[0]; ++ i) {
			ans = max(ans, i * h[0] + (n - i * w[0]) / w[1] * h[1]);
		}	
	}
	else {
		if(w[1] * h[0] < w[0] * h[1]) {
			swap(w[0], w[1]), swap(h[0], h[1]);
		}
		
		for(int i = 0; i <= w[0]; ++ i) {
			ans = max(ans, i * h[1] + (n - i * w[1]) / w[0] * h[0]);
		}
	}
	
	cout << ans;
	
	return 0;
}
