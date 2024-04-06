#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
#define pb emplace_back
using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;
	vector<int> p(n + 2), nxt(n + 1);
	/*
	由于无解的充要条件为存在 i < j < nxt[i] < nxt[j]
	
	nxt[i] = -1 --> nxt[i] = i + 1 不会影响有解情况
	*/
	
	for(int i = 1; i <= n; ++ i) {
		cin >> nxt[i];
		nxt[i] = max(nxt[i], i + 1);
	}
	vector<int> a(n + 1);
	iota(a.begin() + 1, a.end(), 1);
	sort(a.begin() + 1, a.end(), [&](int i, int j) {
		if(nxt[i] != nxt[j]) {
			return nxt[i] < nxt[j];
		}
		return i > j;
	});
	for(int i = 1; i <= n; ++ i) {
		p[a[i]] = i;
	}
	stack<int> stk;
	p[n + 1] = 1e9;
	stk.push(n + 1);
	for(int i = n; i >= 1; -- i) {
		while(!stk.empty() && p[i] > p[stk.top()]) {
			stk.pop();
		}
		if(nxt[i] != stk.top()) {
			cout << -1 << '\n';
			return;
		}
		stk.push(i);
	}
	for(int i = 1; i <= n; ++ i) cout << p[i] << " \n"[i == n];	
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T = 1;
	cin >> T;
	while(T --) solve();
	return 0;
}
