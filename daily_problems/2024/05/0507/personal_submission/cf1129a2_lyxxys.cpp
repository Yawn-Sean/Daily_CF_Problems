#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector <int> dis(n+1, 2e9), cnt(n+1);
	
	for (int i = 1; i <= m; ++ i){
		int a, b;
		cin >> a >> b;
		int d = b < a ? n+b-a : b-a;
		dis[a] = min(dis[a], d), ++ cnt[a];
	}
	
	for (int i = 1; i <= n; ++ i){
		long long res = 0;
		for (int j = 1; j <= n; ++j)
			if (cnt[j])
				res = max(res, 1ll*(cnt[j]-1)*n + (j-i+n)%n + dis[j]);  //贪心取最大值，答案只和该点的运输最小距离和运输次数有关
		cout << res << " ";
	}
	cout << "\n";
}
