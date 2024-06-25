#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 2e5 + 5;

int a[N], p[N], idx;
multiset<int> se[2];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n, k; cin >> n >> k;
	
	int lst = 0, cur = 0;
	
	int ans = 0;
	
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		if(a[i] < 0) {
			p[++ idx] = i;
			++ cur;
		}	
		if(i > 1) {
			ans += (a[i] < 0 && a[i - 1] >= 0) || (a[i] >= 0 && a[i - 1] < 0);
		}
	}
	ans += (a[1] < 0);
	p[++ idx] = n + 1; 
	
	
	for(int i = 2; i <= idx; ++ i) {
		
		int x = p[i] - p[i - 1] - 1;
		if(x) {
			
			if(i != idx) se[1].insert(x);
			else se[0].insert(x);
		}
	}
	
	k -= cur;
	if(k < 0) {
		cout << -1;
		exit(0);
	}
	
	for(int x : se[1]) {
		if(x <= k) {
			k -= x;
			ans -= 2;
		}
		else break;
	}
	for(int x : se[0]) {
		if(x <= k) {
			k -= x;
			ans -= 1;
		}
		else break;
	}
	cout << ans << '\n';
	return 0;
}
