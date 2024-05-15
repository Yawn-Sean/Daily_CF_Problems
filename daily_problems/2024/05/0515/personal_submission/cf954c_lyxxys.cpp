#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void solve(){
	int n;
	cin >> n;
	vector <int> p(n+1);
	for (int i = 1; i <= n; ++ i) cin >> p[i];
	int y = 1;
	for (int i = 2; i <= n; ++ i) y = max(y, abs(p[i]-p[i-1]));
	for (int i = 2; i <= n; ++ i)
		if (abs(p[i]-p[i-1]) + min(p[i], p[i-1])%y == 1*(y != 1) || (abs(p[i]-p[i-1])-1)*(abs(p[i]-p[i-1])-y))
			return cout << "NO\n", void();
	cout << "YES\n";
	cout << INF << " " << y << "\n";
}
