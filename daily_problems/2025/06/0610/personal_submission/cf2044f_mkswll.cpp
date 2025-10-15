#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector divs(MAXN + 1, vector <int> ());
	for(int i = 1; i <= MAXN; ++i){
		for(int j = i; j <= MAXN; j += i){
			divs[j].push_back(i);
		}
	}
	int n, m, q;
	cin >> n >> m >> q;
	vector <int> a(n + 1), b(m + 1);
	ll sma = 0, smb = 0;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		sma += a[i];
	}
	for(int i = 1; i <= m; ++i){
		cin >> b[i];
		smb += b[i];
	}
	set <int> sta, stb;
	for(int i = 1; i <= n; ++i){
		ll val = a[i] - sma;
		if(abs(val) <= MAXN) sta.insert(a[i] - sma);
	}
	for(int i = 1; i <= m; ++i){
		ll val = b[i] - smb;
		if(abs(val) <= MAXN) stb.insert(b[i] - smb);
	}
	map <int, int> rec;
	for(int i = 1; i <= q; ++i){
		int x;
		cin >> x;
		if(rec.count(x)){
			cout << (rec[x] ? "YES" : "NO") << "\n";
			continue;
		}
		bool ans = 0;
		for(int j : divs[abs(x)]){
			int k = x / j;
			if(sta.count(j) && stb.count(k) || sta.count(-j) && stb.count(-k)){
				ans = 1;
				break;
			}
		}
		rec[x] = ans;
		cout << (ans ? "YES" : "NO") << "\n";
	}
}