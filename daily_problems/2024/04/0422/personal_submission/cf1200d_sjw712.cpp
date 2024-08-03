#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<string> s(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	int ans = 0;
	vector<vector<int>> a(n + 2, vector<int>(n + 2));
	auto add = [&](int x1,int y1,int x2,int y2,int c)->void{
	    a[x1][y1] += c;
	    a[x1][y2 + 1] -= c;
	    a[x2 + 1][y1] -= c;
	    a[x2 + 1][y2 + 1] += c;
	};
	for(int i = 1; i <= n; i ++){
		int l = n + 1, r = 0;
		for(int j = 1; j <= n; j ++){
			if(s[i][j] == 'B') l = min(l, j), r = max(r, j);
		}
		if(r == 0){
			ans ++;
			continue;
		}
		if(r - l + 1 > k) continue;
		int x1 = max(1ll, i - k + 1), y1 = max(1ll, r - k + 1);
		int x2 = i, y2 = l; 
		add(x1, y1, x2, y2, 1);
	}
	for(int i = 1; i <= n; i ++){
		int l = n + 1, r = 0;
		for(int j = 1; j <= n; j ++){
			if(s[j][i] == 'B') l = min(l, j), r = max(r, j);
		}
		if(r == 0){
			ans ++;
			continue;
		}
		if(r - l + 1 > k) continue;
		int x1 = max(1ll, r - k + 1), y1 = max(1ll, i - k + 1);
		int x2 = l, y2 = i;
		add(x1, y1, x2, y2, 1);
	}
	int res = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			res = max(res, a[i][j]);
		}
	}
	cout << ans + res << '\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --){
		solve();
	}
}
