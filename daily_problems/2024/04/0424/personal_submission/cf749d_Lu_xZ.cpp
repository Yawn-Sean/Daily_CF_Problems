#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 2e5 + 5;

multiset<int> se[N];
multiset<pair<int, int>, greater<pair<int, int>>> mx;

int n, m, q, a[N];


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	
	for(int i = 1; i <= n; ++ i) {
		int j, x; cin >> j >> x;
		a[j] = max(a[j], x);
		se[j].insert(x);
	}
	
	for(int i = 1; i <= n; ++ i) {
		if(a[i]) {
			mx.insert({a[i], i});
		}
	}
	
	cin >> q;
	
	for(int i = 1; i <= q; ++ i) {
		
		cin >> m;
		vector<int> vec(m);
		
		for(int i = 0; i < m; ++ i) {
			cin >> vec[i];
			
			auto it = mx.lower_bound(make_pair(a[vec[i]], n));
			
			if(it == mx.end()) continue;
			
			if(it -> first == a[vec[i]]) {
				mx.erase(it);
			}
			
		}
		
		if(mx.empty()) {
			cout << 0 << ' ' << 0 << '\n';
		}
		
		else if(mx.size() == 1) {
			int x = mx.begin() -> second; 
			
			cout << x << ' ' << *se[x].begin() << '\n';
		}
		
		else {
			int x = mx.begin() -> second;
			mx.erase(mx.begin());
			int y = mx.begin() -> second;
			mx.insert({a[x], x});
			
			cout << x << ' ' << *se[x].upper_bound(a[y])  << '\n';
		}
		
		
		for(int i = 0; i < m; ++ i) {
			
			if(a[vec[i]]) {
				mx.insert({a[vec[i]], vec[i]});
			}
			
		}
		
	} 
	
	
	return 0;
}
