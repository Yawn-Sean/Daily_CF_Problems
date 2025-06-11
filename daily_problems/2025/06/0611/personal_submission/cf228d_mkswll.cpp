#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Fenwick {
	vector <ll> ft;
	int n;
	Fenwick(int _n): n(_n), ft(_n + 1) {}
	void update(int x, ll val){
		for(int i = x; i <= n; i += i & -i){
			ft[i] += val;
		}
	}
	ll query(int x){
		ll ret = 0;
		for(int i = x; i; i -= i & -i){
			ret += ft[i];
		}
		return ret;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n;
	vector <int> a(n + 1, 0);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	auto get = [&](int z, int offset, int pos) -> int {
		pos = (pos - (offset - 2 * (z - 1))) % (2 * (z - 1));
		if(pos < z) return pos + 1;
		return 2 * z - pos - 1;
	};
	vector <vector <Fenwick> > ft(7);
	for(int z = 2; z <= 6; ++z){
		for(int i = 0; i < 2 * (z - 1); ++i){
			ft[z].push_back(Fenwick(n));
			for(int j = 1; j <= n; ++j){
				ft[z][i].update(j, (ll) a[j] * get(z, i, j));
			}
		}
	}
	cin >> m;
	for(int i = 1; i <= m; ++i){
		int opt;
		cin >> opt;
		if(opt == 1){
			int p, v;
			cin >> p >> v;
			int delta = v - a[p];
			a[p] = v;
			for(int z = 2; z <= 6; ++z){
				for(int j = 0; j < 2 * (z - 1); ++j){
					ft[z][j].update(p, (ll) delta * get(z, j, p));
				}
			}
		}
		else{
			int l, r, z;
			cin >> l >> r >> z;
			int offset = l % (2 * (z - 1));
			cout << ft[z][offset].query(r) - ft[z][offset].query(l - 1) << "\n";
		}
	}
	return 0;
}