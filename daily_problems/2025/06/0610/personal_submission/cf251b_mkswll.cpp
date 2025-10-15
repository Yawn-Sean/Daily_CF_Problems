#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector <int> q(n + 1), b(n + 1);
	for(int i = 1; i <= n; ++i) cin >> q[i];
	for(int i = 1; i <= n; ++i) cin >> b[i];
	vector <int> d(2, k + 1);
	bool flag = 1;
	for(auto& dis : d){
		vector <int> a(n + 1);
		iota(a.begin(), a.end(), 0);
		for(int i = 0; i <= k; ++i){
			if(a == b){
				dis = i;
				break;
			}
			vector <int> na(n + 1, 0);
			for(int j = 1; j <= n; ++j){
				if(flag) na[j] = a[q[j]];
				else na[q[j]] = a[j];
			}
			a = move(na);
		}
		flag = !flag;
	}
	auto check = [&](int d1, int d2) -> bool {
		return d1 <= k && (d1 + k) % 2 == 0 && (d1 == k || d1 > 1 || d2 > 1); 
	};
	cout << (check(d[0], d[1]) || check(d[1], d[0]) ? "YES" : "NO") << "\n";
}