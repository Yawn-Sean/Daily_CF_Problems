#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9, mod = 998244353;


void solve(){
	int n, m;
	cin >> n >> m;
	vector <ll> row(n+1), col(m+1);
	vector <int> v;
	auto gain = [&](int i, int j){  //获取下标
		return (i-1)*m + j-1;
	};
	
	for (int i = 1; i <= n; ++ i){
		for (int j = 1, x; j <= m; ++ j)
			cin >> x, v.push_back(x), row[i] += x;
		int siz = v.size()-1;
		for (int j = 0; j < m; ++ j)
			col[m-j] += v[siz-j];
	}
	//case:1+2, 选四个行/列
	ll res = 0;
	{
		ll v1 = 0, v2 = 0, v3 = 0, v4 = 0;
		for (int i = 1; i <= n; ++ i){
			if (row[i] > v1) v4 = v3, v3 = v2, v2 = v1, v1 = row[i];
			else if (row[i] > v2) v4 = v3, v3 = v2, v2 = row[i];
			else if (row[i] > v3) v4 = v3, v3 = row[i];
			else if (row[i] > v4) v4 = row[i];
		}
		res = max(res, v1+v2+v3+v4);
		v1 = 0, v2 = 0, v3 = 0, v4 = 0;	
		for (int i = 1; i <= m; ++ i){
			if (col[i] > v1) v4 = v3, v3 = v2, v2 = v1, v1 = col[i];
			else if (col[i] > v2) v4 = v3, v3 = v2, v2 = col[i];
			else if (col[i] > v3) v4 = v3, v3 = col[i];
			else if (col[i] > v4) v4 = col[i];
		}
		res = max(res, v1+v2+v3+v4);		
	}

//	case:3+4， 选三个行/列，一个列/行
	{
		for (int i = 1; i <= n; ++ i){
			ll r1 = row[i], v1 = 0, v2 = 0, v3 = 0;
			for (int j = 1; j <= m; ++ j){
				int p = gain(i, j);
				if (col[j]-v[p] > v1) v3 = v2, v2 = v1, v1 = col[j]-v[p];
				else if (col[j]-v[p] > v2) v3 = v2, v2 = col[j]-v[p];
				else if (col[j]-v[p] > v3) v3 = col[j]-v[p];
			}
			res = max(res, r1+v1+v2+v3);
		}
		for (int i = 1; i <= m; ++ i){
			ll c1 = col[i], v1 = 0, v2 = 0, v3 = 0;
			for (int j = 1; j <= n; ++ j){
				int p = gain(j, i);
				if (row[j]-v[p] > v1) v3 = v2, v2 = v1, v1 = row[j]-v[p];
				else if (row[j]-v[p] > v2) v3 = v2, v2 = row[j]-v[p];
				else if (row[j]-v[p] > v3) v3 = row[j]-v[p];
			}
			res = max(res, c1+v1+v2+v3);
		}
	}
	//case:5  选两个行/列，两个列/行
	if (n < m){
		for (int i = 1; i <= n; ++ i){
			ll r1 = row[i];
			for (int j = i+1; j <= n; ++ j){
				ll c1 = 0, c2 = 0, r2 = row[j];
				for (int k = 1; k <= m; ++ k){
					int p1 = gain(i, k), p2 = gain(j, k); 
					if (col[k]-v[p1]-v[p2] > c1) c2 = c1, c1 = col[k]-v[p1]-v[p2];
					else if (col[k]-v[p1]-v[p2] > c2) c2 = col[k]-v[p1]-v[p2];
				}
				
				res = max(res, r1+r2+c1+c2);
			}
		}	
	} else {
		for (int i = 1; i <= m; ++ i){
			ll c1 = col[i];
			for (int j = i+1; j <= m; ++ j){
				ll r1 = 0, r2 = 0, c2 = col[j];
				for (int k = 1; k <= n; ++ k){
					ll p1 = gain(k, i), p2 = gain(k, j); 
					if (row[k]-v[p1]-v[p2] > r1) r2 = r1, r1 = row[k]-v[p1]-v[p2];
					else if (row[k]-v[p1]-v[p2] > r2) r2 = row[k]-v[p1]-v[p2];
				}
				
				res = max(res, r1+r2+c1+c2);
			}
		}		
	}
	
	cout << res << "\n";
}
