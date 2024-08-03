#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 3e5 + 5;

struct Team {
	int id;
	ll num, w;
	bool operator < (const Team &o) const {
		if(num != o.num)
			return num > o.num;
		return id < o.id;
	}
}a[N];

int n, p[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i].num >> a[i].w;			// t <= w;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++ i) {
		p[a[i].id] = i; 
	}
	priority_queue<ll> q;
	for(int i = 1; i < p[1]; ++ i) {
		q.push(a[i].num - a[i].w);
	}
	int ans = p[1], i = 0, j = p[1];
	ll need = 0;
	while(!q.empty()){
		need += -q.top() + 1;
		q.pop();
		if(a[p[1]].num < need) break;
		++ i;												// 有多少个飘走了
		while(j < n && a[p[1]].num - need < a[j + 1].num) {
			++ j;										// 有多少到前面去了
			q.push(a[j].num - a[j].w);
		}
		ans = min(ans, p[1] - i + (j - p[1]));
	}
	cout << ans;
	return 0;
}
