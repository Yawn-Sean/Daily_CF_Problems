#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9, mod = 998244353;


void solve(){
	ll X, d;
	cin >> X >> d;
	
	vector <ll> v;
	ll cnt = 0, st = 1;
	
	for (ll i = 0; i < 31; ++ i){
		ll c = X>>i & 1ll;
		if (c){
			++ cnt;
			bool key = 0;
			for (int j = i; j > 0; -- j)
				v.push_back(st), key = 1;  //指数级转线性压缩存储
			if (key) st += d;
		}
	}
	
	while (cnt--) v.push_back(st), st += d; //补位
	cout << v.size() << "\n";
	for (auto &x : v) cout << x << " ";
	cout << "\n";
}
