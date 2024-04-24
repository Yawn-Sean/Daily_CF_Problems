#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
void solve(){
	int n;
	cin >> n;
	vector<string> s(n);
	vector<vector<int>> p(n);
	for(int i = 0; i < n; i ++){
		cin >> s[i];
		int a = 0, b = 0;
		for(char c: s[i]){
			if(c == 's') a ++;
			else b ++;
		}
		p[i] = {a, b, i};
	}
	int ans = 0;	
	sort(p.begin(), p.end(), [&](vector<int> a, vector<int> b){
		return a[0] * b[1] > a[1] * b[0];
	});
	string str = "";
	for(auto i: p) str += s[i[2]];
	str = ' ' + str;
	n = str.size();
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++){
		a[i] = a[i - 1] + (str[i] == 'h');
	}
	for(int i = 1; i <= n; i ++){
		if(str[i] == 's') ans += a[n] - a[i];
	}
	cout << ans << '\n';
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
