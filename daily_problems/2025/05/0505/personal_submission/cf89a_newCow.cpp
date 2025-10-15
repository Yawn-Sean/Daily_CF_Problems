#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;
const int N = 10010;

ll n,m,k,a[N];

ll solve() {
	if (n == 1) {
		return min(m * k,a[1]);
	}
	
	if (n % 2 == 0) {
		return 0;
	}
	
	if (m >= (n + 1) / 2) {
		
		ll t = m / ((n + 1) / 2),minv = 10000000;
		
		for (int i = 1;i <= n; i+= 2) {
			minv = min(a[i],minv);
		}
		
		return min(k * t,minv);
	} else {
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1;i <= n; i++) {
		cin >> a[i];
	}
	
	int ans = solve();
	
	cout << ans << "\n";
	
	
	return 0;
}
