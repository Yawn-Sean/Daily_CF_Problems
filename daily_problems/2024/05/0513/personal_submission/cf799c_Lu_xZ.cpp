#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 1e5 + 5;


int n, c, d;

struct Fenwick_Tree {
	int t[N];
	void insert(int p, int v) {
		while(p < N) {
			t[p] = max(t[p], v);
			p += p & -p;
		}
	}
	int pre(int p) {
		int ret = 0;
		while(p > 0) {
			ret = max(ret, t[p]);
			p -= p & -p;
		}
		return ret;
	}
} coins, diamonds;

int mx[2], mm[2];


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> c >> d;
	
	for(int i = 1; i <= n; ++ i) {
		int b, p; 
		char ty;
		cin >> b >> p >> ty;
		if(ty == 'C') {
			if(p <= c) mm[0] = max(mm[0], b);
			int x = coins.pre(c - p);
			if(x > 0) {
				mx[0] = max(mx[0], x + b);
			}
			coins.insert(p, b);
		}
		else {
			if(p <= d) mm[1] = max(mm[1], b);
			int x = diamonds.pre(d - p);
			if(x > 0) {
				mx[1] = max(mx[1], x + b);
			}
			diamonds.insert(p, b);
		}
	}
	
	int ans = max({mx[0], mx[1], (mm[0] > 0 && mm[1] > 0) * (mm[0] + mm[1])});
	cout << ans;
	return 0;
}
