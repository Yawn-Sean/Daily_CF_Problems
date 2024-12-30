#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	string s; cin >> s;
	int n = s.length();
	
	auto get = [&](int k) {
		ll ret = 0;
		unordered_map<char, int> cnt;
		for(int i = 0, j = 0; i < n; ++ i) {
			++ cnt[s[i]];
			while(j <= i && cnt.size() > k) {
				if(-- cnt[s[j]] == 0) cnt.erase(s[j]);
				++ j;
			}
			ret += i - j + 1;
		}
		return ret;
	};
	
	vector<ll> a(30, 0);
	
	for(int i = 26; i >= 1; -- i) {
		a[i] = get(i);
		a[i + 1] -= a[i];
	}
	
	int m = 1;
	while(a[m + 1] && m < 26) ++ m;
	cout << m << '\n';
	
	for(int i = 1; i <= m; ++ i) cout << a[i] << '\n';
	return 0;
}
