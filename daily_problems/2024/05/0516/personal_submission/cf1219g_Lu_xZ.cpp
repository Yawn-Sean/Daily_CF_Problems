#include<bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n, m; cin >> n >> m;
	
	vector g(n, vector<int>(m));
	for(int i = 0; i < n ; ++ i) {
		for(int j = 0; j < m; ++ j) {
			cin >> g[i][j]; 
		}
	}
	
	ll ans = 0;
	
	auto Part_One = [&]() {
		priority_queue<ll> q;
		for(int i = 0; i < n; ++ i) {
			ll s = 0;
			for(int j = 0; j < m; ++ j) {
				s += g[i][j];
			}
			q.push(s);
		}
		ll tmp = 0;
		for(int i = 0; !q.empty() && i < 4; ++ i) {
			tmp += q.top();
			q.pop();
		}
		ans = max(ans, tmp);
	}; Part_One(); 
	
	
	
	auto Part_Two = [&]() {
		priority_queue<ll> q;
		for(int j = 0; j < m; ++ j) {
			ll s = 0;
			for(int i = 0; i < n; ++ i) {
				s += g[i][j];
			}
			q.push(s);
		}
		ll tmp = 0;
		for(int i = 0; !q.empty() && i < 4; ++ i) {
			tmp += q.top();
			q.pop();
		}
		ans = max(ans, tmp);
	}; Part_Two(); 
	
	if(n <= 4 || m <= 4) {
		cout << ans;
		exit(0);
	}
	
	
	auto Part_Three = [&]() {
		vector<ll> s(n);
		for(int i = 0; i < n; ++ i) {
			for(int j = 0; j < m; ++ j) {
				s[i] += g[i][j];
			}
		}
		for(int j = 0; j < m; ++ j) {
			vector<ll> t = s;
			ll tmp = 0;
			for(int i = 0; i < n; ++ i) t[i] -= g[i][j], tmp += g[i][j];  
			sort(t.begin(), t.end(), greater<ll>());
			for(int i = 0; i < 3; ++ i) {
				tmp += t[i];
			}
			ans = max(ans, tmp);
		}
	}; Part_Three(); 
	
	
	
	auto Part_Four = [&]() {
		vector<ll> s(m);
		for(int j = 0; j < m; ++ j) {
			for(int i = 0; i < n; ++ i) {
				s[j] += g[i][j];
			}
		}
		for(int i = 0; i < n; ++ i) {
			vector<ll> t = s;
			ll tmp = 0;
			for(int j = 0; j < m; ++ j) t[j] -= g[i][j], tmp += g[i][j];  
			sort(t.begin(), t.end(), greater<ll>());
			for(int k = 0; k < 3; ++ k) {
				tmp += t[k];
			}
			ans = max(ans, tmp);
		}
	}; Part_Four(); 
	
	
	
	auto Part_Five = [&]() {
		if(n > m) {
			vector<ll> s(n);
			for(int i = 0; i < n; ++ i) {
				for(int j = 0; j < m; ++ j) {
					s[i] += g[i][j];
				}
			}
			for(int j1 = 0; j1 < m; ++ j1) {
				for(int j2 = j1 + 1; j2 < m; ++ j2) {
					ll tmp = 0;
					ll mx1 = 0, mx2 = 0;
					for(int i = 0; i < n; ++ i) {
						tmp += g[i][j1] + g[i][j2];
						ll x = s[i] - g[i][j1] - g[i][j2];
						if(x > mx1) {
							mx1 = x;
						}
						else if(x > mx2) {
							mx2 = x;
						}
					}   
					ans = max(ans, tmp + mx1 + mx2);
				}
			}
		}
		else {
			vector<ll> s(m);
			for(int j = 0; j < m; ++ j) {
				for(int i = 0; i < n; ++ i) {
					s[j] += g[i][j];
				}
			}
			for(int i1 = 0; i1 < n; ++ i1) {
				for(int i2 = i1 + 1; i2 < n; ++ i2) {
					ll tmp = 0, mx1 = 0, mx2 = 0;
					for(int j = 0; j < m; ++ j) {
						tmp += g[i1][j] + g[i2][j];
						ll x = s[j] -  g[i1][j] - g[i2][j];
						if(x > mx1) {
							mx1 = x;
						}
						else if(x > mx2) {
							mx2 = x;
						}
					}  
					ans = max(ans, tmp + mx1 + mx2);
				}
			}
		}
	}; Part_Five();
	
	cout << ans;
	return 0;
}
