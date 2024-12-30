#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 2e5 + 5;

int n, m, a[N];
int R[N], t[N], idx;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	
	R[0] = 1e9;
	
	for(int i = 1; i <= m; ++ i) {
		int op, v; cin >> op >> v;
		while(v >= R[idx] ) {
			-- idx;
		}
		R[++ idx] = v;
		t[idx] = op;
	}
	
	multiset<int> se;
	multiset<int, greater<int>> ss;
	
	for(int i = 1; i <= R[1]; ++ i) {
		se.insert(a[i]);
		ss.insert(a[i]);
	}
	R[idx + 1] = 0;
	
	for(int i = 1; i <= idx; ++ i) {
		int l = R[i + 1] + 1;
		int r = R[i];
		if(t[i] == 1) {
			for(int j = r; j >= l; -- j) {
				a[j] = *ss.begin();
				ss.erase(ss.begin());
				se.erase(se.find(a[j]));
			}
		}
		else {
			for(int j = r; j >= l; -- j) {
				a[j] = *se.begin();
				se.erase(se.begin());
				ss.erase(ss.find(a[j]));
			}
		}
	}
	for(int i = 1; i <= n; ++ i) cout << a[i] << ' ';
	return 0;
}
