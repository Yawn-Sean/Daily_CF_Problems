#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 2e5 + 5;

ll n, a[N];
map<ll, int> cnt;
map<ll, set<int>> mp;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		++ cnt[a[i]];
		mp[a[i]].insert(i);
	}
	priority_queue<ll, vector<ll>, greater<ll>> q;
	for(auto [key, val] : cnt) {
		if(val >= 2) {
			q.push(key);
		}
	}
	while(!q.empty()) {
		ll x = q.top();
		auto &se = mp[x];
		int i = *se.begin(); se.erase(se.begin());
		int j = *se.begin(); se.erase(se.begin());
		a[i] = 0;
		a[j] <<= 1, mp[a[j]].insert(j);
		if(++ cnt[a[j]] == 2) {
			q.push(a[j]);
		}
		cnt[x] -= 2;
		if(cnt[x] < 2) {
			q.pop();
		}
		if(cnt[x] == 0) {
			mp.erase(x);
			cnt.erase(x);
		}
	}
	int tot = 0;
	for(int i = 1; i <= n; ++ i) if(a[i]) ++ tot;
	cout << tot << '\n';
	for(int i = 1; i <= n; ++ i) if(a[i]) cout << a[i] << ' ';
	return 0;
}
