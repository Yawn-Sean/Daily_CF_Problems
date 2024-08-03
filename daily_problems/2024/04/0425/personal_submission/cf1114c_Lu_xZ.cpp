#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll inf = 1e18;

ll n, b, ans = inf;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> b;
	
	for(int i = 2; i <= b / i; ++ i) {
		if(b % i == 0) {
			int cur = 0;
			while(b % i == 0) {
				++ cur;
				b /= i;
			}
			
			ll tmp = 0, x = 1;
			
			do {
				x *= i;
				tmp += n / x;
				
			} while(x <= n / i);
			
			ans = min(ans, tmp / cur);			
		}
	}
	
	if(b != 1) {

		ll tmp = 0, x = 1;
		
		do {
			x *= b;
			tmp += n / x;
			
		} while(x <= n / b);
		
		ans = min(ans, tmp);
	}
	
	cout << (ans == inf ? 0 : ans);
	
	return 0;
}
