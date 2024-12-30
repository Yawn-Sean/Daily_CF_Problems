#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
constexpr int N = 2e5 + 5;

ll n, T, sum;

struct Node {
	ll num, t;
	bool operator < (const Node &o) const {
		return t < o.t;
	}
} a[N];

db ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> T;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i].num;
	}
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i].t;
		a[i].t -= T;
		sum += a[i].t * a[i].num;
		ans += a[i].num;
	}
	
	sort(a + 1, a + n + 1);
	
	if(sum < 0) {
		for(int i = 1; i <= n; ++ i) {
			if(sum - a[i].num * a[i].t >= 0) {
				ans -= (db)sum / a[i].t;
				sum = 0;
				break;
			}
			sum -= a[i].num * a[i].t;
			ans -= a[i].num;
		}
	}
	if(sum > 0) {
		for(int i = n; i >= 1; -- i) {			
			if(sum - a[i].num * a[i].t <= 0) {
				ans -= (db)sum / a[i].t;
				sum = 0;
				break;
			}
			sum -= a[i].num * a[i].t;
			ans -= a[i].num;
		}
	}
	
	cout << fixed << setprecision(12) << ans;
	return 0;
}
